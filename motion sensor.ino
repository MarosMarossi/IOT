#define MOTION_SENSOR_PIN 32 // ESP32 pin GPIO32 connected to the OUTPUT pin of motion sensor
#define LED_PIN 3 // ESP32 pin GPIO17 connected to LED's pin

int motionStateCurrent = LOW; // current state of motion sensor's pin
int motionStatePrevious = LOW; // previous state of motion sensor's pin

void setup() {
  Serial.begin(9600); // initialize serial
  pinMode(MOTION_SENSOR_PIN, INPUT); // set ESP32 pin to input mode
  pinMode(LED_PIN, OUTPUT); // set ESP32 pin to output mode
}

void loop() {
  motionStatePrevious = motionStateCurrent; // store old state
  motionStateCurrent = digitalRead(MOTION_SENSOR_PIN); // read new state

  if (motionStatePrevious == LOW && motionStateCurrent == HIGH) { // pin state change: LOW -> HIGH
    Serial.println("Motion detected!, turns LED ON");
    digitalWrite(LED_PIN, HIGH); // turn on
  } else if (motionStatePrevious == HIGH && motionStateCurrent == LOW) { // pin state change: HIGH -> LOW
    Serial.println("Motion stopped!, turns LED OFF");
    digitalWrite(LED_PIN, LOW); // turn off
  }
}