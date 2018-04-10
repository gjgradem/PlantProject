// Plant watering script v0.1
// Author: Geert Rademakers
// Copyright

//Init pins
const int moistPower = 1;
const int moistSensor = 2;
const int onBoardLed = 13;
const int pump = 3;
const int pumptime = 5000;
const int timeout = 1800000;

void setup() {
  pinMode(moistPower, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(onBoardLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Starting watering sequence...");
  enableSensor();
  moistLvl = analogRead(moistSensor);
  Serial.println("Sensor value: " + moistLvl);
  if (moistLvl < 3000) {
    pumpWater();
  }
  else {
    disableSensor();
    Serial.println("Going to sleep for " + (timeout / 1000) + " seconds");
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
  Serial.println("Pumped water for " + (pumptime / 1000) + " seconds. Waiting a few seconds before retrying...");
  delay(10000);
}

void enableSensor() {
  Serial.println("Enabeling sensor...");
  digitalWrite(moistPower, HIGH);
  delay(500);
  Serial.println("Sensor enabled!");
}

void disbableSensor() {
  Serial.println("Disabling sensor...");
  digitalWrite(moistPower, LOW);
  Serial.println("Sensor disabled!");
}

