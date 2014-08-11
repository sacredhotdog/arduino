const int RED_LED_PIN = 11;
const int GREEN_LED_PIN = 9;
const int BLUE_LED_PIN = 10;

const int RED_SENSOR_PIN = A0;
const int GREEN_SENSOR_PIN = A2;
const int BLUE_SENSOR_PIN = A1;


int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;


void setup() {
  Serial.begin(9600);
  
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}

void loop() {
  getSensorValues();
  calculateColourValues();
  adjustRgbLed();
}

void getSensorValues() {
  redSensorValue = getSensorValue(RED_SENSOR_PIN);
  greenSensorValue = getSensorValue(GREEN_SENSOR_PIN);
  blueSensorValue = getSensorValue(BLUE_SENSOR_PIN);  
  // logSensorValues(redSensorValue, greenSensorValue, blueSensorValue);
}

void calculateColourValues() {
  redValue = calculateColourValue(redSensorValue);
  greenValue = calculateColourValue(greenSensorValue);
  blueValue = calculateColourValue(blueSensorValue);  
  // logColourValues(redValue, greenValue, blueValue);
}

void adjustRgbLed() {
  analogWrite(RED_LED_PIN, redValue);
  analogWrite(GREEN_LED_PIN, greenValue);
  analogWrite(BLUE_LED_PIN, blueValue);
}

int getSensorValue(int sensorPin) {
  int sensorValue = analogRead(sensorPin);
  delay(5);
  
  return sensorValue;
}

int calculateColourValue(int sensorValue) {
  return sensorValue / 4;
}

void logSensorValues(int redSensorValue, int greenSensorValue, int blueSensorValue) {
  Serial.print("Raw sensor values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print(" \t Green: ");
  Serial.print(greenSensorValue);
  Serial.print(" \t Blue: ");
  Serial.println(blueSensorValue);
}

void logColourValues(int redValue, int greenValue, int blueValue) {
  Serial.print("Colour values \t Red: ");
  Serial.print(redValue);
  Serial.print(" \t Green: ");
  Serial.print(greenValue);
  Serial.print(" \t Blue: ");
  Serial.println(blueValue); 
}
