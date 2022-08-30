#ifndef CONFIG_H
#define CONFIG_H

/* GPIO Pins */

#define SDA_PIN 4
#define SCL_PIN 5

#define BAUD_DEBUG 115200

/* Display */

// Shift UI in regular screen, positive = down, negative = up
#define SCREEN_Y_OFFSET 7

// How long should a message (light on / off) stay on display?
#define MSG_DISPLAY_MS 3000

/* GPS Module */

#define BAUD_DEFAULT 9600
#define BAUD_TARGET 921600
#define GNSS_REFRESH_RATE 10

/* Timer */

#define ROLLING_THRESHOLD 1

/* Buttons */

#define DEBOUNCE_MS 150

#define MODE_BUTTON_PIN 0   // GPIO 0 (boot button)

#endif