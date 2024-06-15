#include "button_positions.hpp"
#include "comms/backend_init.hpp"
#include "core/CommunicationBackend.hpp"
#include "core/KeyboardMode.hpp"
#include "core/Persistence.hpp"
#include "core/mode_selection.hpp"
#include "core/state.hpp"
#include "display/DisplayMode.hpp"
#include "display/GlyphConfigMenu.hpp"
#include "display/InputDisplay.hpp"
#include "display/MenuButtonHints.hpp"
#include "display/RgbBrightnessMenu.hpp"
#include "glyph_overrides.hpp"
#include "glyph_pinout.hpp"
#include "input/DebouncedSwitchMatrixInput.hpp"
#include "matrix_definition.hpp"
#include "reboot.hpp"
#include "stdlib.hpp"

#include <Adafruit_SSD1306.h>
#include <config.pb.h>

Config config = glyph_default_config();

DebouncedSwitchMatrixInput<num_rows, num_cols> matrix_input(
    row_pins,
    col_pins,
    matrix,
    DiodeDirection::COL2ROW
);

CommunicationBackend **backends = nullptr;
size_t backend_count;
KeyboardMode *current_kb_mode = nullptr;

InputState inputs;

InputSource *input_sources[] = { &matrix_input };
size_t input_source_count = sizeof(input_sources) / sizeof(InputSource *);

void setup() {
    // Create GPIO input source and use it to read button states for checking button holds.
    matrix_input.UpdateInputs(inputs);

    // Check bootsel button hold as early as possible for safety.
    if (inputs.mb1) {
        reboot_bootloader();
    }

    // Attempt to load config, or write default config to flash if failed to load config.
    if (!persistence.LoadConfig(config)) {
        persistence.SaveConfig(config);
    }

    // Create array of input sources to be used.
    backend_count = initialize_backends(
        backends,
        inputs,
        input_sources,
        input_source_count,
        config,
        pinout,
        get_backend_config_default,
        get_usb_backend_config_default,
        &detect_console,
        &init_secondary_backends_glyph
    );

    setup_mode_activation_bindings(config.game_mode_configs, config.game_mode_configs_count);
}

void loop() {
    select_mode(backends, backend_count, config);

    for (size_t i = 0; i < backend_count; i++) {
        backends[i]->SendReport();
    }

    if (current_kb_mode != nullptr) {
        current_kb_mode->SendReport(backends[0]->GetInputs());
    }
}

/* Second core handles OLED display */
Adafruit_SSD1306 display(128, 64, &OLED_WIRE_INSTANCE);
IntegratedDisplay *display_backend = nullptr;

RgbBrightnessMenu rgb_brightness_menu(config);

InputDisplay *input_viewer = nullptr;

void setup1() {
    while (!backend_count || backends == nullptr) {
        delay(1);
    }

    // These have to be initialized after backends.
    CommunicationBackendId primary_backend_id = backends[0]->BackendId();
    static MenuButtonHints menu_button_hints(backends, backend_count);
    static InputDisplay input_display(
        platform_fighter_buttons,
        platform_fighter_buttons_count,
        primary_backend_id
    );
    static GlyphConfigMenu config_menu(config, backends, backend_count);

    static DisplayMode *display_modes[] = {
        &menu_button_hints,
        &input_display,
        &config_menu,
        &rgb_brightness_menu,
    };
    size_t display_modes_count = count_of(display_modes);

    input_viewer = &input_display;

    Wire1.setSDA(OLED_SDA);
    Wire1.setSCL(OLED_SCL);
    Wire1.setClock(1'000'000UL);
    Wire1.begin();
    if (display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false, false)) {
        // clang-format off
        display_backend = new IntegratedDisplay(
            inputs,
            display,
            []() { display.clearDisplay(); },
            []() { display.display(); },
            DisplayControls{ .back = BTN_MB1, .down = BTN_MB6, .up = BTN_MB5, .enter = BTN_MB7 },
            display_modes,
            display_modes_count
        );
        // clang-format on
        display_backend->SetDisplayMode(
            config.default_dashboard_option == DASHBOARD_INPUT_VIEWER ? DISPLAY_MODE_VIEWER
                                                                      : DISPLAY_MODE_BUTTON_HINTS
        );
    }
}

void loop1() {
    if (display_backend == nullptr) {
        return;
    }
    if (backends[0] != nullptr && backends[0]->CurrentGameMode() != nullptr &&
        display_backend->CurrentGameMode() != backends[0]->CurrentGameMode()) {
        display_backend->SetGameMode(backends[0]->CurrentGameMode());
    }
    // Update input display layout.
    if (display_backend->CurrentGameMode() != nullptr) {
        GameModeConfig *mode_config = display_backend->CurrentGameMode()->GetConfig();
        switch (mode_config->layout_plate) {
            case LAYOUT_PLATE_UNSPECIFIED:
            case LAYOUT_PLATE_EVERYTHING:
                input_viewer->UpdateButtonLayout(full_layout_buttons, full_layout_buttons_count);
                break;
            case LAYOUT_PLATE_FGC:
                input_viewer->UpdateButtonLayout(fgc_buttons, fgc_buttons_count);
                break;
            case LAYOUT_PLATE_SPLIT_FGC:
                input_viewer->UpdateButtonLayout(split_fgc_buttons, split_fgc_buttons_count);
                break;
            case LAYOUT_PLATE_PLATFORM_FIGHTER:
                input_viewer->UpdateButtonLayout(
                    platform_fighter_buttons,
                    platform_fighter_buttons_count
                );
                break;
        }
    }
    display_backend->SendReport();
}
