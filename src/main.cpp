#include<Arduino.h>
int pirPin = 2;     // PIR sensor OUT pin
int ledPin = 13;    // LED pin (built-in LED)

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("PIR Sensor Warming Up...");
  delay(30000);   // IMPORTANT: PIR warm-up time (30 sec)
}

void loop() {
  int motion = digitalRead(pirPin);

  if (motion == HIGH) {
    digitalWrite(ledPin, HIGH);   // LED ON
    Serial.println("Motion Detected!");
  } 
  else {
    digitalWrite(ledPin, LOW);    // LED OFF
    Serial.println("No Motion");
  }

  delay(200);
}