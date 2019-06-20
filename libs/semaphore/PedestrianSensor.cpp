#include "PedestrianSensor.h"

PedestrianSensor::PedestrianSensor(int triggerPin, int echoPin, int distanceThreshold) : ultrasonic(triggerPin, echoPin) {
	this->_distanceThreshold = distanceThreshold;
	this->_lastTrue = 0;
}


bool PedestrianSensor::checkPedestrian() {
  
  double distance = getDistanceCM();

  if(distance < this->_distanceThreshold){
    this->_lastTrue += 1;
  } else {
  	this->_lastTrue = 0;
  }

  if(_lastTrue >= 3) {
  	return true;
  } else {
  	return false;
  }
}

float PedestrianSensor::getDistanceCM() {
  	long microsec = ultrasonic.timing();
  	return ultrasonic.convert(microsec, Ultrasonic::CM);
}