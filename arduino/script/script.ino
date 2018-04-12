// Plant watering script v0.2
// Author: Geert Rademakers
// Copyright

//Init pins
const int moistPower = 53;
const int moistSensor = 7;
const int onBoardLed = 13;
const int pump = 52;
const int pumptime = 100;
const long timeout = 100;
const int moistMax = 300;
const int afterPumpDelay = 100;
int moistLvl = 0;
unsigned long sinceStart = millis();

void setup() {
  pinMode(moistPower, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(onBoardLed, OUTPUT);
  Serial.begin(9600);
  Serial.println("Setting up");
}

void loop() {
  if(sinceStart%10000 == 0) {
    Serial.println("10 seconds passed");
    wateringSequence();
  }
  else if (sinceStart%5000 == 0) {
    Serial.println("5 seconds passed");
    measureMoist();
  }
}

void measureMoist() {
  enableSensor();
  String prefix = "command:measure:";
  int data = analogRead(moistSensor);
  String toSend = prefix + data;
  Serial.println(toSend);
  disableSensor();
}

void wateringSequence() {
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
  //Serial.println("Pumped water for " + String((pumptime / 1000)) + " seconds. Waiting a few seconds before retrying...");
  String toprint = "command:feed:";
  String toprintdata = toprint + pumptime;
  Serial.println(toprintdata);
  delay(afterPumpDelay);
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


