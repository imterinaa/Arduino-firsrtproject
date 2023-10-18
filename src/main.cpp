
#include <Arduino.h>
#include <Adafruit_AHTX0.h>
#include "wrappersSensor.h"
// #define EB_NO_FOR           // отключить поддержку pressFor/holdFor/stepFor и счётчик степов (экономит 2 байта оперативки)
// #define EB_NO_CALLBACK      // отключить обработчик событий attach (экономит 2 байта оперативки)
// #define EB_NO_COUNTER       // отключить счётчик энкодера (экономит 4 байта оперативки)
// #define EB_NO_BUFFER        // отключить буферизацию энкодера (экономит 1 байт оперативки)

// #define EB_DEB_TIME 50      // таймаут гашения дребезга кнопки (кнопка)
// #define EB_CLICK_TIME 500   // таймаут ожидания кликов (кнопка)
// #define EB_HOLD_TIME 600    // таймаут удержания (кнопка)
// #define EB_STEP_TIME 200    // таймаут импульсного удержания (кнопка)
// #define EB_FAST_TIME 30     // таймаут быстрого поворота (энкодер)

// SDA = D21; SCL = D22;

#include <EncButton.h>  
EncoderWrapper encoderWrapperInstance;
AHTWrapper ahtWrapperInstance;

void setup() {
    Serial.begin(115200);

    // показаны значения по умолчанию
    encoderWrapperInstance.setButtonLevel(LOW); 
    encoderWrapperInstance.setClickTimeout(500);

    // сбросить счётчик энкодера
    encoderWrapperInstance.resetCounter();

   
}

void loop() {
    encoderWrapperInstance.tick();
    encoderWrapperInstance.printData();
}