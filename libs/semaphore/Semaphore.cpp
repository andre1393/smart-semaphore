#include "Arduino.h"
#include "Semaphore.h"

Semaphore::Semaphore(int greenPin, int redPin, int yellowPin) {
	this->_greenPin = greenPin;
	this->_redPin = redPin;
	this->_yellowPin = yellowPin;

  	pinMode(this->_redPin, OUTPUT);
  	pinMode(this->_yellowPin, OUTPUT);
  	pinMode(this->_greenPin, OUTPUT);

	this->_isSemaphoreOpen = false;
	this->_lastTimeOpen = 0;
}

void Semaphore::close(){
  turnLedOn(this->_redPin);
  this->_isSemaphoreOpen = false;
}

void Semaphore::open(){
  turnLedOn(this->_greenPin);
  this->_lastTimeOpen = millis();
  this->_isSemaphoreOpen = true;
}

void Semaphore::warning() {
  turnLedOn(this->_yellowPin);
  this->_lastTimeOpen = millis();
  this->_isSemaphoreOpen = false;
}

void Semaphore::turnAllOff(){
  digitalWrite(this->_redPin, LOW);
  digitalWrite(this->_yellowPin, LOW);
  digitalWrite(this->_greenPin, LOW);
}

void Semaphore::turnLedOn(int ledOn) {
  turnAllOff();
  digitalWrite(ledOn, HIGH);
}

bool Semaphore::isSemaphoreOpen() {
  return this->_isSemaphoreOpen;
}
