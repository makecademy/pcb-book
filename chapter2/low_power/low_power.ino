// Low power functions library
#include <JeeLib.h>

// LED pin
int led_pin = 13;

// Setup the watchdog
ISR(WDT_vect) { Sleepy::watchdogEvent(); } 

void setup() {
  
  // Set LED pin to output
  pinMode(led_pin, OUTPUT);
}

void loop() {
    
  // Turn the LED on and sleep for 5 seconds
  digitalWrite(led_pin, HIGH);
  Sleepy::loseSomeTime(5000);
    
  // Turn the LED off and sleep for 5 seconds
  digitalWrite(led_pin, LOW);
  Sleepy::loseSomeTime(5000);
}
