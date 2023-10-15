#include "Arduino.h"
#include "Wire.h"
#include "Adafruit_AHTX0.h"
#define ENCODER_A 27
#define ENCODER_B 26
#define BUTTON 25
int encoderPos = 0;
int lastEncoderPos = 0;
int buttonState = 0;
int lastButtonState = 0;
unsigned long lastPrint = 0; // Время последнего вывода
unsigned long printInterval = 1000; // Интервал вывода в миллисекундах


void setup() {
 pinMode(ENCODER_A, INPUT_PULLUP);
 pinMode(ENCODER_B, INPUT_PULLUP);
 pinMode(BUTTON, INPUT_PULLUP);
 Serial.begin(115200);
}

void loop() {
 encoderPos += (digitalRead(ENCODER_A) == digitalRead(ENCODER_B)) ? -1 : 1;
 buttonState = digitalRead(BUTTON);
 if (buttonState != lastButtonState) {
 if (buttonState == LOW) {
 encoderPos = 0;
 Serial.println("Кнопка нажата!");
    }
 lastButtonState = buttonState;
  }

 if (encoderPos != lastEncoderPos) {
    lastEncoderPos = encoderPos;
    unsigned long currentMillis = millis();
    if (currentMillis - lastPrint >= printInterval) {
      lastPrint = currentMillis;
      Serial.println(encoderPos, DEC);
    
    }}
}