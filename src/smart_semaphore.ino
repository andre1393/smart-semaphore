#include <Ultrasonic.h>

#define pino_trigger 5
#define pino_echo 4

#define PIN_RED 12
#define PIN_YELLOW 11
#define PIN_GREEN 10

#define MIN_OPEN_SEMAPHORE 10000
#define CLOSED_SEMAPHORE_TIME 4000
#define YELLOW_TIME 2000

int hasPedestrian;
unsigned long openTimeElapsed;
unsigned long lastTimeOpen;
boolean isSemaphoreOpen;

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup() {
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);

  openSemaphore();
  hasPedestrian = false;
  openTimeElapsed = 0;
  lastTimeOpen = 0;
}

void loop() {
  hasPedestrian = hasPedestrian ? true : checkPedestrian();

  if(isSemaphoreOpen && hasPedestrian){
    if((millis() - lastTimeOpen) > MIN_OPEN_SEMAPHORE){
      hasPedestrian = false;
      closeSemaphore();
      delay(CLOSED_SEMAPHORE_TIME);
      openSemaphore();
    }
  }
}

boolean checkPedestrian() {
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);

  delay(200);
  
  if(cmMsec < 15){
    return true;
  } else {
    return false;
  }
}

void turnOn(int on) {
  turnAllOff();
  digitalWrite(on, HIGH);
}

void turnAllOff(){
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_YELLOW, LOW);
  digitalWrite(PIN_GREEN, LOW);
}

void openSemaphore(){
  isSemaphoreOpen = true;
  turnOn(PIN_GREEN);
  lastTimeOpen = millis();
}

void closeSemaphore(){
  isSemaphoreOpen = false;
  turnOn(PIN_YELLOW);
  delay(YELLOW_TIME);
  turnOn(PIN_RED);
}
