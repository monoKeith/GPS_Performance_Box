#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include "SSD1306Wire.h"
#include "time.h"
#include "state.h"
#include "config.h"
#include "fonts.h"

namespace monitor
{
    // Must call during initialization to init I2C connection
    extern void setup();
    // Update content of monitor based on current state
    extern void refresh();

    // Display modes
    extern void drawBootScreen();
    extern void drawDebugScreen();
    extern void drawScreen();

    // Connection to I2C display
    extern SSD1306Wire display;

};

#endif