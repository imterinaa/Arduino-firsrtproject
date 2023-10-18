#include <Adafruit_AHTX0.h>
#include <EncButton.h> 
#include "wrappersSensor.h"


    void AHTWrapper::getEvent(sensors_event_t* humidity, sensors_event_t* temp) {
        aht.getEvent(humidity, temp);
    }


    AHTWrapper::AHTWrapper() {
        if (!aht.begin()) {
            Serial.println("Could not find AHT? Check wiring");
            while (1) delay(10);
        }
        Serial.println("AHT10 or AHT20 found");
    }

    void AHTWrapper::printTemperatureAndHumidity() {
        sensors_event_t humidity, temp;
        aht.getEvent(&humidity, &temp); // populate temp and humidity objects with fresh data
        Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
        Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");
    }



    EncoderWrapper::EncoderWrapper() : eb(27, 26, 25) {}

    void EncoderWrapper::printData() {

        if (eb.left()) Serial.println("left");
        if (eb.right()) Serial.println("right");
        if (eb.leftH()) Serial.println("leftH");
        if (eb.rightH()) Serial.println("rightH");

        // кнопка
        if (eb.press()) {
        Serial.println("press");
        }
        if (eb.click()) {
        Serial.println("click");
        sensors_event_t humidity, temp;
        getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
        Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
        Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");

        delay(500);}

        if (eb.release()) {
        Serial.println("release");

        Serial.print("clicks: ");
        Serial.print(eb.getClicks());
        Serial.print(", steps: ");
        Serial.print(eb.getSteps());
        Serial.print(", press for: ");
        Serial.print(eb.pressFor());
        Serial.print(", hold for: ");
        Serial.print(eb.holdFor());
        Serial.print(", step for: ");
        Serial.println(eb.stepFor());
        }

        // состояния
        // Serial.println(eb.pressing());
        // Serial.println(eb.holding());
        // Serial.println(eb.busy());
        // Serial.println(eb.waiting());

        // таймаут
        if (eb.timeout(1000)) Serial.println("timeout!");

        // удержание
        if (eb.hold()) Serial.println("hold");
        if (eb.hold(3)) Serial.println("hold 3");

        // импульсное удержание
        if (eb.step()) Serial.println("step");
        if (eb.step(3)) Serial.println("step 3");

        // отпущена после импульсного удержания
        if (eb.releaseStep()) Serial.println("release step");
        if (eb.releaseStep(3)) Serial.println("release step 3");

        // отпущена после удержания
        if (eb.releaseHold()) Serial.println("release hold");
        if (eb.releaseHold(2)) Serial.println("release hold 2");

        // проверка на количество кликов
        if (eb.hasClicks(3)) Serial.println("has 3 clicks");

        // вывести количество кликов
        if (eb.hasClicks()) {
        Serial.print("has clicks: ");
        Serial.println(eb.getClicks()); 
       
    }}


