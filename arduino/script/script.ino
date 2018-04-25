// Plant watering script v0.2
// Author: Geert Rademakers
// Copyright

// Includes
#include <SoftTimer.h>



//Init pins
const int moistPower = 53;
const int moistSensor = 7;
const int onBoardLed = 13;
const long measureInterval = 900000;
const long pumpInterval = 3600000;
const int pump = 51;
const int pumptime = 3000;

//standard value: kek
const int moistMin = 350;

//standard value: 180000
const long afterPumpDelay = 180000;
int moistLvl = 0;
int feedtimes = 0;

void pumpTest(Task* me) {
  Serial.println("Pumploop activated!");
  wateringSequence();
}

void measureTest(Task* me) {
  Serial.println("Measureloop activated!");
  measureMoist();
}

Task measureTask(measureInterval, measureTest);
Task pumpTask(pumpInterval, pumpTest);


//void loop() {
//  if(sinceStart%10000 == 0) {
//    Serial.println("10 seconds passed");
//    //wateringSequence();
//  }
//  else if (sinceStart%5000 == 0) {
//    Serial.println("5 seconds passed");
//    //measureMoist();
//  }
//}

void measureMoist() {
  enableSensor();
  String prefix = "command:measure:";
  int data = analogRead(moistSensor);
  String toSend = prefix + data;
  Serial.println(toSend);
  disableSensor();
}

void wateringSequence() {
  //Serial.println("Starting watering sequence...");
  enableSensor();
  moistLvl = analogRead(moistSensor);
  //toPrint = "sensor value: " + moistLvl;
  Serial.println(moistLvl);
  if (moistLvl < moistMin) {
    feedtimes++;
    pumpWater();
    wateringSequence();
  }
  else {
    disableSensor();
    if (feedtimes != 0) {
      String toprint = "command:feed:";
      String toprintdata = toprint + feedtimes;
      Serial.println(toprintdata);
      feedtimes = 0;
    }
    else {
      Serial.println("Not fed");
    }
  }
}

void pumpWater() {
  Serial.println("Pumping water...");
  digitalWrite(onBoardLed, HIGH);
  digitalWrite(pump, HIGH);
  delay(pumptime);
  digitalWrite(pump, LOW);
  digitalWrite(onBoardLed, LOW);
  Serial.println("Waiting for: ");
  Serial.print(afterPumpDelay);
  delay(afterPumpDelay);
}

void enableSensor() {
  //Serial.println("Enabeling sensor...");
  digitalWrite(moistPower, HIGH);
  delay(500);
  //Serial.println("Sensor enabled!");
}

void disableSensor() {
  //Serial.println("Disabling sensor...");
  digitalWrite(moistPower, LOW);
  //Serial.println("Sensor disabled!");
}


void setup() {
  pinMode(moistPower, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(onBoardLed, OUTPUT);
  Serial.begin(9600);
  Serial.println("Setting up");
  SoftTimer.add(&measureTask);
  SoftTimer.add(&pumpTask);
}


