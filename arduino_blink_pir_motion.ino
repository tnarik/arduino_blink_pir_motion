// Do not remove the include below
#include "arduino_blink_pir_motion.h"

const int pirPin = 2;
const int ledPin =  13;

bool buttonActivate = true;
int buttonState = 0;

//The setup function is called once at startup of the sketch
void setup() {
  Serial.begin(9600);
  Serial.print("Start");
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  delay(2000);
}

// The loop function is called in an endless loop
void loop() {
  if ( buttonActivate ) {
    buttonState = digitalRead(pirPin);

    if (buttonState == HIGH) {
      Serial.println("high");
      digitalWrite(ledPin, LOW);
    }
    else {
      Serial.println("low");
      digitalWrite(ledPin, HIGH);
      delay(2000);
      digitalWrite(ledPin, LOW);
    }
    delay(1000);
  } else {
    digitalWrite(ledPin, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(1000);                 // wait for a second
    digitalWrite(ledPin, LOW);  // turn the LED off by making the voltage LOW
    delay(1000);                 // wait for a second
  }
}
