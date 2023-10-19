#ifndef _WRAPPER_H_
#define _WRAPPER_H_

#include "EncButton.h"
#include "Adafruit_AHTX0.h"

class wrapperAHT{
    private:
        Adafruit_AHTX0 aht;
        sensors_event_t humidity, temp;
    public: 
        void aht_setup(){

             if (! aht.begin()) {
                Serial.println("Could not find AHT? Check wiring");}

             Serial.println("AHT20 found");
        }
        void print(){
          aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
          Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
          Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");
        }
};

class wrapperEncoder{
    private:
        EncButton enc;
    public:
        wrapperEncoder(){
            enc = EncButton(27,26,25);
        }
        void enc_setup(){
             enc.setBtnLevel(LOW);
             enc.setClickTimeout(500);

             // сбросить счётчик энкодера
             enc.counter = 0;
        }
        void event_click(wrapperAHT& aht){
            if (enc.click()) {
			Serial.println("click");
			aht.print();
			delay(500);
            }
        }

        void print(){
            enc.tick();
            // обработка поворота раздельная
            if (enc.left()) Serial.println("left");
            if (enc.right()) Serial.println("right");
            if (enc.leftH()) Serial.println("leftH");
            if (enc.rightH()) Serial.println("rightH");

            // кнопка
            if (enc.press()) {
            Serial.println("press");
            }

            if (enc.release()) {
            Serial.println("release");
            Serial.print("clicks: ");
            Serial.print(enc.getClicks());
            Serial.print(", steps: ");
            Serial.print(enc.getSteps());
            Serial.print(", press for: ");
            Serial.print(enc.pressFor());
            Serial.print(", hold for: ");
            Serial.print(enc.holdFor());
            Serial.print(", step for: ");
            Serial.println(enc.stepFor());
            }

            // состояния
            // Serial.println(enc.pressing());
            // Serial.println(enc.holding());
            // Serial.println(enc.busy());
            // Serial.println(enc.waiting());

            // таймаут
            if (enc.timeout(1000)) Serial.println("timeout!");

            // удержание
            if (enc.hold()) Serial.println("hold");
            if (enc.hold(3)) Serial.println("hold 3");

            // импульсное удержание
            if (enc.step()) Serial.println("step");
            if (enc.step(3)) Serial.println("step 3");

            // отпущена после импульсного удержания
            if (enc.releaseStep()) Serial.println("release step");
            if (enc.releaseStep(3)) Serial.println("release step 3");

            // отпущена после удержания
            if (enc.releaseHold()) Serial.println("release hold");
            if (enc.releaseHold(2)) Serial.println("release hold 2");

            // проверка на количество кликов
            if (enc.hasClicks(3)) Serial.println("has 3 clicks");

            // вывести количество кликов
            if (enc.hasClicks()) {
                Serial.print("has clicks: ");
                Serial.println(enc.getClicks());   
        }
                
        }
        };

#endif _WRAPPER_H_