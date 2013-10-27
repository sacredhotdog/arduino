const int SENSOR_PIN = A0;
const float BASELINE_TEMPERATURE = 24.0;


void setup() {
  Serial.begin(9600);
  
  // Reset pins
  for(int pinNumber = 2; pinNumber <= 4; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN);
  float voltage = (sensorValue / 1024.0) * 5.0;
  float temperature = (voltage - 0.5) * 100;

  // log(sensorValue, voltage, temperature);
  
  if(temperature < BASELINE_TEMPERATURE) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= (BASELINE_TEMPERATURE + 2) && temperature < (BASELINE_TEMPERATURE + 4)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= (BASELINE_TEMPERATURE + 4) && temperature < (BASELINE_TEMPERATURE + 6)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if(temperature > (BASELINE_TEMPERATURE + 6)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  
  delay(1);
}

void log(int sensorValue, float voltage, float temperature) {
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  
  Serial.print(", Volts: ");
  Serial.print(voltage);
  
  Serial.print(", degrees C: ");
  Serial.println(temperature);  
}
