#ifndef CarSensor_h
#define CarSensor_h

#include "Arduino.h"

class CarSensor {
  
  private:
    unsigned int countCar;
    unsigned long epoch;
    int _triggerPin;
    int _echoPin;
    bool checkCar();

  public:
    CarSensor(int triggerPin, int echoPin);
    double getCarFlux();
};

#endif