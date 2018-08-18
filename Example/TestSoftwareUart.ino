#include <SoftwareUART.h>

SoftwareUART suart(0,2);

void setup() {
  
  suart.begin(115200);
  Serial.begin(115200);
}

void loop() {
  delay(0);

  while (suart.available()) {
    Serial.write(suart.read());
  }

  while (Serial.available()) {
    suart.write(Serial.read());
  }
}
