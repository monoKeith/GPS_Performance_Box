#ifndef CONFIG_H
#define CONFIG_H

/* GPIO Pins */

#define SDA_PIN 4
#define SCL_PIN 5

/* Display */

// Shift UI in regular screen, positive = down, negative = up
#define SCREEN_Y_OFFSET 7

// How long should a message (light on / off) stay on display?
#define MSG_DISPLAY_MS 3000

#endif