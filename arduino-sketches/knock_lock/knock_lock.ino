#include<Servo.h>

Servo servo;

const int piezo = A0;
const int switchPin = 2;
const int servoPin = 9;
const int redLed = 5;
const int yellowLed = 4;
const int greenLed = 3;

int knockValue;
int switchValue;

const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;
int numberOfKnocks = 0;


void setup() {
  servo.attach(servoPin);
  
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  
  Serial.begin(9600);
  
  digitalWrite(greenLed, HIGH);
  servo.write(0);
  Serial.println(" -> Unlocked...");
}

void loop() {
  if (locked == false) {
    switchValue = digitalRead(switchPin);
    
    if (switchValue == HIGH) {
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      servo.write(90);
      Serial.println(" -> Locked.");
      
      delay(1000);
    }
  }
  
  if (locked == true) {
    knockValue = analogRead(piezo);
    
    if (numberOfKnocks < 3 && knockValue > 0) {
      if (checkForKnock(knockValue) == true) {
        numberOfKnocks++;
      }
      
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more knocks to go");
    }
    
    if (numberOfKnocks >= 3) {
      numberOfKnocks = 0;
      locked = false;
      servo.write(0);
      delay(20);
      
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println(" -> Unlocked...");
    }
  }
}

boolean checkForKnock(int value) {
  if (value > quietKnock && value < loudKnock) {
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    Serial.print(" -> Knock: ");
    Serial.println(value);
    
    return true;
  }
  else {
    Serial.print(" -> No valid knock detected (knock value was ");
    Serial.print(value);
    Serial.println(")");
    
    return false;
  }
}
