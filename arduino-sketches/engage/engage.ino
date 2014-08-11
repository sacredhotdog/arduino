const int PIN_2 = 2;
const int PIN_3 = 3;
const int PIN_4 = 4;
const int PIN_5 = 5;


int switchState = 0;

void setup() {
  pinMode(PIN_3, OUTPUT);
  pinMode(PIN_4, OUTPUT);
  pinMode(PIN_5, OUTPUT);
  pinMode(PIN_2, INPUT);
}

void loop() {
  switchState = digitalRead(2);
  
  if (switchState == LOW) {
    // The switch is off, so reset
    digitalWrite(PIN_3, HIGH);
    digitalWrite(PIN_4, LOW);
    digitalWrite(PIN_5, LOW);
  }
  else {
    // The switch is on - do stuff!
    digitalWrite(PIN_3, LOW);
    digitalWrite(PIN_4, LOW);
    digitalWrite(PIN_5, HIGH);
    
    delay(250);
    
    digitalWrite(PIN_4, HIGH);
    digitalWrite(PIN_5, LOW);
    
    delay(250);
  }
}
