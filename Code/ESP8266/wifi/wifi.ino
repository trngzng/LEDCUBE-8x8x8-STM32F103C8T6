#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <BlynkSimpleEsp8266.h>
#define  BLYNK_PRINT Serial


enum
{
  TURN_OFF_ALL_LEDS,
  TURN_ON_ALL_LEDS,
  SWEEP_ALL_LEDS,
  GROW_SHRINK_CUBE,
  DIAGONAL_CUBE,
  AROUND_EDGE_CUBE,
  COUNT_DOWN_CUBE,
  RANDOM_RAIN_CUBE,
  SPIRAL_CUBE,
  WAVE_EFFECT,
  SIDE_WAVES_EFFECT,
  FIREWORKS_EFFECT,
  TOTAL_EFFECTS,
};

uint8_t current = WAVE_EFFECT;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.write(current);
  delay(5000);
}