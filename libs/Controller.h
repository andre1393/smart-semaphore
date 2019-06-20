#ifndef Controller_h
#define Controller_h

#include "Arduino.h"
#include "PedestrianSensor.h"
#include "CarSensor.h"
#include "Semaphore.h"

class Controller {
private:
	PedestrianSensor pSensor;
	CarSensor cSensor;
	Semaphore cSemaphore;

public:
	Controller(int pSensorEchoPin, int pSensorTriggerPin, int cSensorEchoPin, int cSensorTriggerPin, int cGreenPin, int cRedPin, int cYellowPin);
};

#endif