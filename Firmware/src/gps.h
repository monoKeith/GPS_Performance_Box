#ifndef GPS_H
#define GPS_H

#include <Arduino.h>
#include <SparkFun_u-blox_GNSS_Arduino_Library.h> 
#include "config.h"
#include "state.h"

namespace gps
{
    extern void setup();
    extern void update();

    extern long lastTime;
};

#endif
