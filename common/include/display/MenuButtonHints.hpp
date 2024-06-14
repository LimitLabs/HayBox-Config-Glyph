#ifndef _DISPLAY_MENUBUTTONHINTS_HPP
#define _DISPLAY_MENUBUTTONHINTS_HPP

#include "core/CommunicationBackend.hpp"
#include "display/DisplayMode.hpp"

class MenuButtonHints : public DisplayMode {
  public:
    MenuButtonHints(CommunicationBackend **const backends, size_t backends_count);
    DisplayModeId GetId();
    void HandleControls(
        IntegratedDisplay *instance,
        const DisplayControls &controls,
        Button button
    );
    void UpdateDisplay(IntegratedDisplay *instance, Adafruit_GFX &display);

  protected:
    const char *CurrentlyPressedButtonText();

    CommunicationBackend **const _backends;
    const size_t _backends_count;
    CommunicationBackendId _backend_id = COMMS_BACKEND_UNSPECIFIED;

    absolute_time_t _pressed_output_locked_until = 0;
    const char *_last_pressed_button_text;
};

#endif