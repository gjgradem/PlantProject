// Plant watering script v0.2
// Author: Geert Rademakers
// Copyright

// Includes
#include <SoftTimer.h>
#include <LiquidCrystal.h>

//Init pins
const int moistPower = 8;
const int moistSensor = A0;
const int onBoardLed = 13;
const long measureInterval = 900000;
const long pumpInterval = 900000;
const int pump = 7;
const int pumptime = 10000;

//standard value: kek
const int moistMin = 410;

//standard value: 300000
const long afterPumpDelay = 300000;
int moistLvl = 0;
int feedtimes = 0;

//LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


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
  updateDisplay(data);
  disableSensor();
}

void wateringSequence() {
  //Serial.println("Starting watering sequence...");
  enableSensor();
  moistLvl = analogRead(moistSensor);
  disableSensor();
  //toPrint = "sensor value: " + moistLvl;
  Serial.println(moistLvl);
  if (moistLvl < moistMin) {
    pumpWater();
    wateringSequence();
  }
  else {
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
  enableSensor();
  int moist_in_pumploop = analogRead(moistSensor);
  disableSensor();
  if (moist_in_pumploop < 450) {
    Serial.println("Pumping water...");
    digitalWrite(onBoardLed, HIGH);
    digitalWrite(pump, HIGH);
    delay(pumptime);
    digitalWrite(pump, LOW);
    digitalWrite(onBoardLed, LOW);
    Serial.println("Waiting for: ");
    Serial.print(afterPumpDelay);
    delay(afterPumpDelay);
    feedtimes++;
    pumpWater();
    updateDisplay(moist_in_pumploop);
  }
  else {
    Serial.println("Ground is moist enough");
    updateDisplay(moist_in_pumploop);
  }
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

void updateDisplay(int currentValue) {
  lcd.setCursor(0,0);
  lcd.print("Now:");
  lcd.setCursor(4,0);
  lcd.print(currentValue);
  lcd.setCursor(0,1);
  lcd.print("Min:");
  lcd.print(moistMin);
}


void setup() {
  pinMode(moistPower, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(onBoardLed, OUTPUT);
  Serial.begin(9600);
  Serial.println("Setting up");
  SoftTimer.add(&measureTask);
  SoftTimer.add(&pumpTask);
  lcd.begin(16,2);
  lcd.print("Now:");
  lcd.setCursor(0,1);
  lcd.print("Min:");
  lcd.print(moistMin);
}


