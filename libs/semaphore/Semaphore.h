#ifndef Semaphore_h
#define Semaphore_h

#include "Arduino.h"

class Semaphore {
private:
	int _greenPin, _redPin, _yellowPin;
	int _isSemaphoreOpen;
	int _lastTimeOpen;

public:
	Semaphore(int greenPin, int redPin, int yellowPin);
	void close();
	void open();
	void warning();
	void turnAllOff();
	void turnLedOn(int ledOn);
	bool isSemaphoreOpen();
};

#endif