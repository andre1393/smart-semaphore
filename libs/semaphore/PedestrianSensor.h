#ifndef PedestrianSensor_h
#define PedestrianSensor_h

#include "Arduino.h"
#include <Ultrasonic.h>

class PedestrianSensor {

private:
	bool hasPedestrian;
	int _lastTrue;
	int _distanceThreshold;

public:
	Ultrasonic ultrasonic;
	PedestrianSensor(int triggerPin, int echoPin, int distanceThreshold);
	bool checkPedestrian();
	float getDistanceCM();
};

#endif