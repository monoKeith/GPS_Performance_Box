#include "ioControl.h"

namespace ioControl
{

    long lastPressTime = 0;

    bool pressed = false;
    ButtonType button;

    void btnHandler(ButtonType type)
    {
        // Debounce by limiting trigger rate
        long currentTime = millis();
        long deltaT = currentTime - lastPressTime;
        if (deltaT > DEBOUNCE_MS)
        {
            // Trigger
            button = type;
            pressed = true;
        }
        lastPressTime = currentTime;
    }

    void press_red()
    {
        btnHandler(RED);
    }

    void press_yellow()
    {
        btnHandler(YELLOW);
    }

    void press_green()
    {
        btnHandler(GREEN);
    }

    ButtonType buttonPressed()
    {
        if (pressed)
        {
            pressed = false;
            return button;
        }
        return NONE;
    }

    // Initialize interruption
    void setup()
    {
        // Red
        pinMode(BTN_RED, INPUT_PULLUP);
        attachInterrupt(BTN_RED, press_red, FALLING);
        // Yellow
        pinMode(BTN_YELLOW, INPUT_PULLUP);
        attachInterrupt(BTN_YELLOW, press_yellow, FALLING);
        // Green
        pinMode(BTN_GREEN, INPUT_PULLUP);
        attachInterrupt(BTN_GREEN, press_green, FALLING);
    }
};