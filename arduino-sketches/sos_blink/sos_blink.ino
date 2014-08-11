/*
  SOS Blink
  
  Uses a LED to send a SOS message
 */
 
// Arduino Uno - LED connected to pin 13
int led = 13;

void setup() {                
  // Flag the LED pin as an output
  pinMode(led, OUTPUT);     
}

void loop() {
  digitalWrite(led, HIGH);    // On
  delay(250);               
  digitalWrite(led, LOW);     // Off
  delay(250);               
  
  digitalWrite(led, HIGH);
  delay(250);
  digitalWrite(led, LOW);
  delay(250);

  digitalWrite(led, HIGH);
  delay(250);
  digitalWrite(led, LOW);
  delay(250);

  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(250);

  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(250);

  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(250);

  digitalWrite(led, HIGH);
  delay(250);
  digitalWrite(led, LOW);
  delay(250);

  digitalWrite(led, HIGH);
  delay(250);
  digitalWrite(led, LOW);
  delay(250);

  digitalWrite(led, HIGH);
  delay(250);
  digitalWrite(led, LOW);
  delay(1000);
}
