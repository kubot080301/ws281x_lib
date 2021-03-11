#include "Arduino.h"
#include <WS2812FX.h>

#define LED1_COUNT 13
#define LED1_PIN A6
#define LED2_COUNT 16
#define LED2_PIN A7

WS2812FX led1(LED1_COUNT, LED1_PIN, NEO_GRB + NEO_KHZ800);
WS2812FX led2(LED2_COUNT, LED2_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  led1.init();
  led1.setBrightness(200);
  led1.setSpeed(100);
  led1.setMode(FX_MODE_RAINBOW_CYCLE);
  led1.start();

  led2.init();
  led2.setBrightness(200);
  led2.setSpeed(100);
  led2.setColor(0, 255, 0);
  led2.setMode(FX_MODE_COLOR_WIPE);
  led2.start();
}

void loop() {
  led1.service();
  led2.service();
}