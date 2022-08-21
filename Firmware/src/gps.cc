#include <gps.h>

namespace gps
{

    SFE_UBLOX_GNSS myGNSS;

    void setup() {
        // debug serial port
        Serial.begin(BAUD_DEBUG);

        bool updateBaudRate = true;

        // conenct to module on serial 1
        Serial1.begin(BAUD_DEFAULT);
        while (!myGNSS.begin(Serial1)) {
            // Try target baud rate
            Serial.println(F("Default baud rate failed, trying target baud rate."));
            Serial1.updateBaudRate(BAUD_TARGET);
            if (myGNSS.begin(Serial1)) {
                updateBaudRate = false;
                break;
            }
            Serial.println(F("u-blox GNSS not connected to Seairl 1. Please check wiring. Try again in 5s."));
            delay(5000);
        }

        if (updateBaudRate) {
            // set baud rate to target
            myGNSS.setSerialRate(BAUD_TARGET);
            Serial1.updateBaudRate(BAUD_TARGET);
        }
        
        // Setup finish
        Serial.println(F("u-blox setup finished."));
    }

    void update() {

    }
}