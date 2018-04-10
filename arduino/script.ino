//Init pins
const int moistPower = 1;
const int moistSensor = 2;
const int pump = 3;
const int pumptime = 5000;
const int timeout = 1800000;

void setup() {
  pinMode(moistPower, OUTPUT);
  pinMode(moistSensor, INPUT);
  pinMode(pump, OUTPUT);
  }

void loop() {
  if(moistsensor < 3000) {
    digitalWrite(pump, HIGH);
    delay(pumptime);
    digitalWrite(pump, LOW);
    }
  else {
    delay(timeout);
    }
  }
