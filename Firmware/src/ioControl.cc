#include "ioControl.h"

namespace ioControl
{
    

    long lastPressTime = 0;

    bool changeMode_r = false;

    void modeBtnHandler()
    {
        // Debounce
        long currentTime = millis();
        long deltaT = currentTime - lastPressTime;
        if (deltaT > DEBOUNCE_MS)
        {
            // Trigger
            changeMode_r = true;
        }
        lastPressTime = currentTime;
    }

    bool changeMode()
    {
        if (changeMode_r)
        {
            changeMode_r = false;
            return true;
        }
        return false;
    }
    
    // Initialize interruption
    void setup()
    {
        // White
        pinMode(MODE_BUTTON_PIN, INPUT_PULLUP);
        attachInterrupt(MODE_BUTTON_PIN, modeBtnHandler, FALLING);
    }
};