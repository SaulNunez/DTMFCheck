#include <Arduino.h>

const int Q1 = 26;
const int Q2 = 25;
const int Q3 = 33;
const int Q4 = 32;
const int EST = 27;

int pin1Res = 0;
int pin2Res = 0;
int pin3Res = 0;
int pin4Res = 0;
int result = 0;

void setup() {
  pinMode(Q1, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q4, INPUT);
  pinMode(EST, INPUT);
}

void loop() {
  int signal = digitalRead(EST);
  if(signal == HIGH){
    pin1Res = digitalRead(Q1);
    pin2Res = digitalRead(Q2);
    pin3Res = digitalRead(Q3);
    pin4Res = digitalRead(Q4);

    result = pin1Res | (pin2Res << 1) | (pin3Res << 2) | (pin4Res << 3);

    switch(result){
      case 0xB:
        Serial.println("Pressed: *");
        break;
      case 0xC:
        Serial.println("Pressed: #");
        break;
      default:
        Serial.printf("Pressed: %i", result);
        break;
    }
  }

}