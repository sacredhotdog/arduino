const int LED_PIN_2 = 2;
const int LED_PIN_3 = 3;
const int LED_PIN_4 = 4;

const int SENSOR_PIN = A0;

const float BASELINE_TEMPERATURE = 24.0;


boolean loggingEnabled = false;


void setup() {
  initialiseLedPins();
}

void loop() {
  float temperature = calculateTemperature();
  indicateLevel(temperature);
  delay(1);
}

void initialiseLedPins() {
  for(int pinNumber = LED_PIN_2; pinNumber <= LED_PIN_4; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    switchOff(pinNumber);
  } 
}

void enableLogging() {
  loggingEnabled = true;
  Serial.begin(9600);
}

float calculateTemperature() {
  float voltage = calculateVoltage();
  float temperature = (voltage - 0.5) * 100;
  
  if (loggingEnabled) {
    log(temperature);
  }
  
  return temperature;
}

void indicateLevel(float temperature) {
  if(isBelowFirstThreshold(temperature)) {
    clearAllLevels();
  }
  else if(isWithinFirstThreshold(temperature)) {
    indicateFirstLevel();
  }
  else if(isWithinSecondThreshold(temperature)) {
    indicateSecondLevel();
  }
  else if(isAboveSecondThreshold(temperature)) {
    indicateMaximumLevel();
  } 
}

float calculateVoltage() {
  int sensorValue = analogRead(SENSOR_PIN);
  
  return (sensorValue / 1024.0) * 5.0;
}

void log(float temperature) {
  Serial.print("Degrees C: ");
  Serial.println(temperature);  
}

boolean isBelowFirstThreshold(float temperature) {
  float lowerLimit = BASELINE_TEMPERATURE;
  
  return temperature < lowerLimit;
}

boolean isWithinFirstThreshold(float temperature) {
  float lowerLimit = BASELINE_TEMPERATURE + 2;
  float upperLimit = BASELINE_TEMPERATURE + 4;
  
  return isTemperatureWithinLimits(temperature, lowerLimit, upperLimit);
}

boolean isWithinSecondThreshold(float temperature) {
  float lowerLimit = BASELINE_TEMPERATURE + 4;
  float upperLimit = BASELINE_TEMPERATURE + 6;
  
  return isTemperatureWithinLimits(temperature, lowerLimit, upperLimit);
}

boolean isAboveSecondThreshold(float temperature) {
  float upperLimit = BASELINE_TEMPERATURE + 6;
  
  return temperature > upperLimit;
}

void clearAllLevels() {
  switchOff(LED_PIN_2);
  switchOff(LED_PIN_3);
  switchOff(LED_PIN_4);
}

void indicateFirstLevel() {
  switchOn(LED_PIN_2);
  switchOff(LED_PIN_3);
  switchOff(LED_PIN_4);
}

void indicateSecondLevel() {
  switchOn(LED_PIN_2);
  switchOn(LED_PIN_3);
  switchOff(LED_PIN_4);
}

void indicateMaximumLevel() {
  switchOn(LED_PIN_2);
  switchOn(LED_PIN_3);
  switchOn(LED_PIN_4); 
}

boolean isTemperatureWithinLimits(float temperature, float lowerLimit, float upperLimit) {
  return temperature >= lowerLimit && temperature < upperLimit;
}

void switchOn(int pinNumber) {
  digitalWrite(pinNumber, HIGH);
}

void switchOff(int pinNumber) {
  digitalWrite(pinNumber, LOW);
}

