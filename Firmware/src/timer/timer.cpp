#include "timer.h"

#define UNAVAILABLE_STR "--"

// Divide by 1000 and print float
String toString(unsigned long value)
{
    char buffer[16];
    float time = value;
    time = time /1000;
    snprintf(buffer, sizeof(buffer), "%.01f", time);
    return buffer;
}

String toStringInt(double value)
{
    char buffer[16];
    snprintf(buffer, sizeof(buffer), "%i", (int)value);
    return buffer;
}

Timer::Timer(double targetSpeed)
{
    this->targetSpeed = targetSpeed;
    this->state = WAITING;
    this->noRecord = true;
    this->targetSpeed_s = toStringInt(targetSpeed);
}

Timer::~Timer()
{
}

void Timer::updateSpeed(double newSpeed)
{
    if (newSpeed == this->curSpeed)
    {
        return;
    }

    this->curSpeed = newSpeed;

    switch (state)
    {
    case RESET:
        if (!rolling())
        {
            // Reset timer when car stopped
            state = WAITING;
        }
        break;
    case WAITING:
        duration = 0;
        if (rolling())
        {
            // Start counting
            startTime = millis();
            state = TICKING;
        }
        break;

    case TICKING:
        duration = millis() - startTime;
        // Reset if car stopped before achieving target speed
        if (!rolling())
        {
            state = WAITING;
        }
        // Target reached, stop counting
        if (newSpeed >= targetSpeed)
        {
            best = noRecord ? duration : min(best, duration);
            previous = duration;            
            noRecord = false;
            state = ACHIEVED;
        }
        break;

    case ACHIEVED:
        if (!rolling())
        {
            // Reset timer when car stopped
            state = WAITING;
        }
        break;
    }
}

bool Timer::rolling()
{
    return curSpeed >= ROLLING_THRESHOLD;
}

String Timer::getTargetSpeed()
{
    return targetSpeed_s;
}

String Timer::getPrevious()
{
    return noRecord ? UNAVAILABLE_STR : toString(previous);
}

String Timer::getBest()
{
    return noRecord ? UNAVAILABLE_STR : toString(best);
}

String Timer::getDuration()
{
    if (state == RESET) {
        return "RESET";
    }

    return (noRecord && state == WAITING) ? UNAVAILABLE_STR : toString(duration);
}


void Timer::reset(){
    this->state = RESET;
    this->noRecord = true;
}