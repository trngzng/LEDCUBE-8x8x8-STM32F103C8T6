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
};

uint8_t current = WAVE_EFFECT;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  if (current == SIDE_WAVES_EFFECT) current = SWEEP_ALL_LEDS;
  else current++;
  Serial.write(current);
  delay(60000);
}
