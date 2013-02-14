#include <AutoScale.h>
//-------------------------------------------------
// Example scaling analog input to 0-11 (inclusive)

const int input_pin = A0;

AutoScale SensorFilter(0, 11);

void setup(void)
{
  Serial.begin(9600);
}
void loop(void)
{
  int raw_val;
  int cooked_val;

  raw_val = analogRead(input_pin);
  cooked_val = SensorFilter(raw_val);
  Serial.print(cooked_val);
  Serial.print(":");
  Serial.println(raw_val);
  delay(500);
}
