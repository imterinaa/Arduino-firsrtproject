
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

// #include <EncButton.h>
// EncButton eb(27, 26, 25); // S1 = 27; S2 = 26; Key = 25;
// Adafruit_AHTX0 aht;
// EncButton eb(2, 3, 4, INPUT); // + режим пинов энкодера
// EncButton eb(2, 3, 4, INPUT, INPUT_PULLUP); // + режим пинов кнопки


#include <Arduino.h>
#include "Wrapper.h"

wrapperAHT aht;
wrapperEncoder enc;

void setup() {

	Serial.begin(115200);
	aht.setup();
	enc.setup();
}

void loop() {
	enc.print();
	enc.event_click(aht);
}
