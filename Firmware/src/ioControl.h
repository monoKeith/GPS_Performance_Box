#ifndef IOCONTROL_H
#define IOCONTROL_H

#include <Arduino.h>
#include "state.h"
#include "config.h"

namespace ioControl
{
    enum ButtonType
    {
        RED,
        YELLOW,
        GREEN,
        NONE
    };

    // Must call to register interruptions
    extern void setup();

    extern ButtonType buttonPressed(); //

};

#endif