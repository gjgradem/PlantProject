// Plant watering script v0.2
// Author: Geert Rademakers
// Copyright

//Init pins
const int moistPower = 53;
const int moistSensor = 7;
const int onBoardLed = 13;
const int pump = 52;
const int pumptime = 10000;
const long timeout = 5000;
const int moistMax = 300;
int moistLvl = 0;

void setup() {
  pinMode(moistPower, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(onBoardLed, OUTPUT);
  Serial.begin(9600);
  Serial.write("Setting up");
}

void loop() {
  Serial.println("Starting watering sequence...");
  enableSensor();
  moistLvl = analogRead(moistSensor);
  Serial.println(moistLvl);
  //Serial.println("Sensor value: " + moistLvl);
  if (moistLvl < moistMax) {
    pumpWater();
  }
  else {
    disableSensor();
    //Serial.println("Going to sleep for " + (timeout / 1000) + " seconds");
    Serial.println("Ending watering sequence...");
    delay(timeout);
  }
}

void pumpWater() {
  Serial.println("Pumping water...");
  digitalWrite(onBoardLed, HIGH);
  digitalWrite(pump, HIGH);
  delay(pumptime);
  digitalWrite(pump, LOW);
  digitalWrite(onBoardLed, LOW);
  //Serial.println("Pumped water for " + (pumptime / 1000) + " seconds. Waiting a few seconds before retrying...");
  delay(10000);
}

void enableSensor() {
  Serial.println("Enabeling sensor...");
  digitalWrite(moistPower, HIGH);
  delay(500);
  Serial.println("Sensor enabled!");
}

void disableSensor() {
  Serial.println("Disabling sensor...");
  digitalWrite(moistPower, LOW);
  Serial.println("Sensor disabled!");
}

