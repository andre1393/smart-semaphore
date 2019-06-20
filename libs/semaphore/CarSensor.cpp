#include "CarSensor.h"

CarSensor::CarSensor(int echoPin, int triggerPin) {
	this->_echoPin = echoPin;
	this->_triggerPin = triggerPin;
}

double CarSensor::getCarFlux() {
	return 0;
}

bool CarSensor::checkCar() {
	return 0;
}

