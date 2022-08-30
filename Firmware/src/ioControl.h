#ifndef IOCONTROL_H
#define IOCONTROL_H

#include <Arduino.h>
#include "state.h"
#include "config.h"

namespace ioControl
{
    // Must call to register interruptions
    extern void setup();

    extern bool changeMode(); // if Requested to change mode

};

#endif