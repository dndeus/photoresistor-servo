#include <Arduino.h>
#include <Servo.h>

const int lightPin = A5;
const int servoPin = D3;
int lightVal = 0;
int servoVal = 0;

Servo myservo;

void setup() {
    pinMode(lightPin, INPUT);
    myservo.attach(servoPin);
    myservo.write(0);
    Serial.begin(9600);
}

void loop() {
    lightVal = analogRead(lightPin);
    servoVal = (lightVal * 180) / 1023;
    myservo.write(servoVal);
    delay(15);
}