/**
   The MIT License (MIT)

   Copyright (c) 2018 by ThingPulse, Daniel Eichhorn
   Copyright (c) 2018 by Fabrice Weinberg

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.

   ThingPulse invests considerable time and money to develop these open source libraries.
   Please support us by buying our products (and not the clones) from
   https://thingpulse.com

*/

#include "monitor.h"

namespace monitor
{

    SSD1306Wire display = SSD1306Wire(0x3c, SDA_PIN, SCL_PIN);

    void setup()
    {
        display.init();
        display.flipScreenVertically();
    }

    void drawBootScreen()
    {
        // Clear
        display.clear();
        // Draw
        display.setFont(Roboto_Mono_Medium_18);
        display.setTextAlignment(TEXT_ALIGN_LEFT);
        display.drawString(0, 0, "GPS");
        display.setFont(Roboto_Mono_Medium_15);
        display.setTextAlignment(TEXT_ALIGN_RIGHT);
        display.drawString(128, 20, "Speedometer");
        display.setFont(ArialMT_Plain_10);
        display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.drawString(64, 35, "Initializing...");
        display.setTextAlignment(TEXT_ALIGN_RIGHT);
        display.drawString(128, 50, "BY KEITH");
        // Done
        display.display();
    }

    void drawDebugScreen()
    {
        // Clear
        display.clear();

        // Clock
        display.setFont(ArialMT_Plain_16);
        display.setTextAlignment(TEXT_ALIGN_LEFT);
        display.drawString(0, 0, state::displayTime);
        // Date
        display.setFont(ArialMT_Plain_10);
        display.setTextAlignment(TEXT_ALIGN_RIGHT);
        display.drawString(128, 6, state::displayDate);
        // Speed
        display.setFont(Roboto_Mono_Medium_18);
        display.setTextAlignment(TEXT_ALIGN_RIGHT);
        display.drawString(128, 20, state::displaySpeed);
        // Location
        display.setFont(ArialMT_Plain_10);
        display.setTextAlignment(TEXT_ALIGN_CENTER);
        display.drawString(64, 42, state::displayLocation);
        // Uptime
        display.setFont(ArialMT_Plain_10);
        display.setTextAlignment(TEXT_ALIGN_LEFT);
        display.drawString(0, 54, "UPTIME:");
        display.setTextAlignment(TEXT_ALIGN_RIGHT);
        display.drawString(128, 54, String(millis()));

        // Done
        display.display();
    }

    void drawScreen()
    {
        // Clear
        display.clear();

        String msg = state::getMessage();

        if (msg.isEmpty())
        {
            // Target speed
            display.setFont(ArialMT_Plain_10);
            display.setTextAlignment(TEXT_ALIGN_LEFT);
            display.drawString(0, 0, "TARGET: " + state::getTimer()->getTargetSpeed());
            // Clock
            display.setFont(ArialMT_Plain_10);
            display.setTextAlignment(TEXT_ALIGN_RIGHT);
            display.drawString(128, 0, state::displayTime);
            // Speed
            display.setFont(ArialMT_Plain_16);
            display.setTextAlignment(TEXT_ALIGN_RIGHT);
            display.drawString(128, 11, state::displaySpeed);
            // Duration
            display.setFont(ArialMT_Plain_24);
            display.setTextAlignment(TEXT_ALIGN_RIGHT);
            display.drawString(128, 28, state::getTimer()->getDuration());
            // Separate
            display.drawHorizontalLine(0, 53, 128);
            // Previous
            display.setFont(ArialMT_Plain_10);
            display.setTextAlignment(TEXT_ALIGN_LEFT);
            display.drawString(0, 54, "PREV: " + state::getTimer()->getPrevious());
            // Best
            display.setFont(ArialMT_Plain_10);
            display.setTextAlignment(TEXT_ALIGN_LEFT);
            display.drawString(64, 54, "BEST: " + state::getTimer()->getBest());
        }
        else
        {
            // Right corner: small time
            display.setFont(Roboto_Mono_Medium_15);
            display.setTextAlignment(TEXT_ALIGN_RIGHT);
            display.drawString(128, SCREEN_Y_OFFSET, state::displayTime);
            // Message
            display.setFont(Roboto_Mono_Medium_18);
            display.setTextAlignment(TEXT_ALIGN_LEFT);
            display.drawStringMaxWidth(0, 18 + SCREEN_Y_OFFSET, 128, msg);
        }

        // Done
        display.display();
    }

    void blackScreen()
    {
        // Clear
        display.clear();
        // Done
        display.display();
    }

    void refresh()
    {
        switch (state::displayMode)
        {
        case state::DisplayMode::REGULAR:
            drawScreen();
            break;

        case state::DisplayMode::DEBUG:
            drawDebugScreen();
            break;

        default:
            blackScreen();
            break;
        }
    }

}
