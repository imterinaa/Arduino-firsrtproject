// wrapperSensor.h
#ifndef WRAPPERSENSOR_H
#define WRAPPERSENSOR_H

#include <Adafruit_AHTX0.h>
#include <EncButton.h>

class AHTWrapper {
private:
    Adafruit_AHTX0 aht;

protected:
    void getEvent(sensors_event_t* humidity, sensors_event_t* temp);

public:
    AHTWrapper();
    void printTemperatureAndHumidity();
};

class EncoderWrapper : public AHTWrapper{
    private: 
        EncButton eb;
    
    public:
        EncoderWrapper();
        void printData();

        void tick(){
            eb.tick();
        }
       // Add a public method to set the button level
        void setButtonLevel(int level) {
            eb.setBtnLevel(level);
        }

        // Add a public method to set the click timeout
        void setClickTimeout(int timeout) {
            eb.setClickTimeout(timeout);
        }

        // Add a public method to reset the encoder counter
        void resetCounter() {
            eb.counter = 0;
        }
};

#endif // WRAPPERSENSOR_H