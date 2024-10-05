#include <Arduino.h>
#include "HomeSpan.h"
#include "DEV_RELAY.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // create a new HomeSpan object
  homeSpan.setPairingCode("11122333"); // 8 digit pairing code

  homeSpan.begin(Category::Lighting, "Kilian PCF Switch");

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify();
       new Service::LightBulb();
      new Characteristic::On();
    new DEV_RELAY(12);

}

void loop() {
  // put your main code here, to run repeatedly:
  homeSpan.poll();
}
