#include <Semaphore.h>
#include <PedestrianSensor.h>
#include <Ultrasonic.h>

#define pino_trigger 4
#define pino_echo 5

#define car1_trigger 6
#define car1_echo 7

#define PIN_RED 13
#define PIN_YELLOW 11
#define PIN_GREEN 12

#define GREEN_MILLIS 2000
#define RED_MILLIS 3000
#define YELLOW_MILLIS 2000

#define MIN_OPEN_SEMAPHORE 10000
#define CLOSED_SEMAPHORE_TIME 4000
#define YELLOW_TIME 2000

#define PEDESTRIAN_DISTANCE_THRESHOLD 50

Semaphore semaphore(PIN_GREEN, PIN_RED, PIN_YELLOW);
PedestrianSensor pedestrianSensor(pino_trigger, pino_echo, PEDESTRIAN_DISTANCE_THRESHOLD);

Ultrasonic ultrasonic(pino_trigger, pino_echo);
long lastTimeOpen;
bool hasPedestrian;

void setup() {
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  
  lastTimeOpen = millis();
  hasPedestrian = false;

  semaphore.open();
  
}

void loop() {
  hasPedestrian = hasPedestrian ? true : pedestrianSensor.checkPedestrian();
  Serial.println(pedestrianSensor.getDistanceCM());
  if(millis() - lastTimeOpen > MIN_OPEN_SEMAPHORE && hasPedestrian){
    hasPedestrian = false;
    semaphore.warning();
    delay(YELLOW_MILLIS);
    semaphore.close();
    delay(CLOSED_SEMAPHORE_TIME);
    semaphore.open();
    lastTimeOpen = millis();
  }
}
