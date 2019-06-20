#include "Arduino.h"
#include "Controller.h"

Controller::Controller(int pSensorEchoPin, int pSensorTriggerPin, int cSensorEchoPin, int cSensorTriggerPin, int cGreenPin, int cRedPin, int cYellowPin){
	this->pSensor = new PedestrianSensor(pSensorEchoPin, pSensorTriggerPin);
	this->cSensor = new CarSensor(cSensorEchoPin, cSensorTriggerPin);
	this->cSemaphore = new Semaphore(cGreenPin, cRedPin, cYellowPin);
}