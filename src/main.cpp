#include "Arduino.h"

const byte interruptPin = 4;
const byte led = 3;

int secondsToKeepPowerOn = 0;

ISR (PCINT0_vect)
{
  secondsToKeepPowerOn = 60;
}

void setup() {
  pinMode(interruptPin, INPUT); // set to input with an internal pullup resistor (HIGH when switch is open)
  pinMode(led, OUTPUT);

  // interrupts
  PCMSK  |= bit (PCINT4);  // want pin D4 / pin 3
  GIFR   |= bit (PCIF);    // clear any outstanding interrupts
  GIMSK  |= bit (PCIE);    // enable pin change interrupts 
}

void loop() {
  if (secondsToKeepPowerOn > 0) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  secondsToKeepPowerOn--;

  delay(125);
}
