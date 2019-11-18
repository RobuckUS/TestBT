#include <Arduino.h>

void setup()
{
  Serial.begin(9600);

  Serial.println("\nRESET");

  Serial1.begin(115200);
  Serial1.print("$");
  Serial1.print("$");
  Serial1.print("$");
  delay(100);
  Serial1.println("U,9600,N");
  Serial1.begin(9600);
  //Serial1.println(AT);
  //AT+BIND=0024,1E,7A9F74
  //00:24:1E:7A:9F:74
}

void loop()
{
  if (Serial1.available())
  {
    Serial.print((char)Serial1.read());
  }
  if (Serial.available())
  {
    Serial1.print((char)Serial.read());
    Serial.print((char)Serial1.read());
  }
}
