#include "display/MenuButtonHints.hpp"

#include "comms/IntegratedDisplay.hpp"
#include "core/config_utils.hpp"
#include "util/state_util.hpp"

MenuButtonHints::MenuButtonHints(CommunicationBackend **backends, size_t backends_count)
    : _backends(backends),
      _backends_count(backends_count) {
    _backend_id = backends[0]->BackendId();
}

DisplayModeId MenuButtonHints::GetId() {
    return DISPLAY_MODE_BUTTON_HINTS;
}

void MenuButtonHints::HandleControls(
    IntegratedDisplay *instance,
    const DisplayControls &controls,
    Button button
) {
    if (button == controls.back) {
        instance->SetDisplayMode(DISPLAY_MODE_CONFIG);
    }
}

void MenuButtonHints::UpdateDisplay(IntegratedDisplay *instance, Adafruit_GFX &display) {
    InputState &inputs = instance->GetInputs();
    uint8_t font_width = instance->font_width;
    uint8_t color = instance->default_color;

    /* Gamemode text */
    display.setCursor(0, 0);
    if (instance->CurrentGameMode() != nullptr) {
        const GameModeConfig &mode_config = *instance->CurrentGameMode()->GetConfig();
        if (strnlen(mode_config.name, sizeof(mode_config.name)) > 0) {
            display.print(mode_config.name);
        } else {
            display.print(gamemode_name(mode_config.mode_id));
        }
    }

    /* Backend text */
    const char *backend_text = backend_name(_backend_id);
    display.setCursor(display.width() - (strlen(backend_text) * font_width), 0);
    display.print(backend_name(_backend_id));

    /* Currently activated output */
    display.setCursor(0, 20);
    const char *currently_pressed_button_text = CurrentlyPressedButtonText();
    // Lazy debounce on the output state, because it may be updated from the other core which could
    // cause flickering. This debounce makes it so the button text has to change for 5 consecutive
    // milliseconds before it will update on the display.
    if (strcmp(currently_pressed_button_text, _last_pressed_button_text) == 0) {
        _pressed_output_locked_until = 0;
    } else {
        if (_pressed_output_locked_until == 0) {
            _pressed_output_locked_until = make_timeout_time_ms(5);
        } else if (time_reached(_pressed_output_locked_until)) {
            _last_pressed_button_text = currently_pressed_button_text;
        }
    }
    display.print(_last_pressed_button_text);

    /* Button hints */
    uint8_t old_rotation = display.getRotation();
    display.setRotation(3);

    display.setCursor(0, 0);

    display.println("Menu\n");
    display.println("Start\n");
    display.println("Back\n");
    display.println("Home\n");
    display.println("Capt.\n");
    display.println("L3\n");
    display.println("R3\n");

    display.setRotation(old_rotation);
}

const char *MenuButtonHints::CurrentlyPressedButtonText() {
    OutputState &outputs = _backends[0]->GetOutputs();
    uint32_t buttons = _backends[0]->GetOutputs().buttons;
    for (uint8_t i = 0; i < _DigitalOutput_MAX; i++) {
        bool activated = buttons & (1UL << i);
        if (activated) {
            return digital_output_name((DigitalOutput)(i + 1));
        }
    }
    if (outputs.leftStickX < (128 - 5)) {
        return "Left Stick X-";
    } else if (outputs.leftStickX > (128 + 5)) {
        return "Left Stick X+";
    } else if (outputs.leftStickY < (128 - 5)) {
        return "Left Stick Y-";
    } else if (outputs.leftStickY > (128 + 5)) {
        return "Left Stick Y+";
    } else if (outputs.leftStickX < (128 - 5)) {
        return "Right Stick X-";
    } else if (outputs.leftStickX > (128 + 5)) {
        return "Right Stick X+";
    } else if (outputs.leftStickY < (128 - 5)) {
        return "Right Stick Y-";
    } else if (outputs.leftStickY > (128 + 5)) {
        return "Right Stick Y+";
    } else if (outputs.triggerLAnalog > 0) {
        return "L2 Analog";
    } else if (outputs.triggerRAnalog > 0) {
        return "R2 Analog";
    }
    return "";
}