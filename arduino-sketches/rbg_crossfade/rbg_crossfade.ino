
const int RED_PIN = 2;
const int BLUE_PIN = 3;
const int GREEN_PIN = 4;

const int LED1_PIN = 5;

const int RED = 0;
const int BLUE = 1;
const int GREEN = 2;

int rgbColour[3] = {255, 0, 0};


void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  for (int sourceColourIndex = RED; sourceColourIndex < (GREEN + 1); sourceColourIndex++) {
    int targetColourIndex = sourceColourIndex == GREEN ? RED : sourceColourIndex + 1;
    
    for (int i = 0; i < 255; i++) {
      rgbColour[sourceColourIndex]--;
      rgbColour[targetColourIndex]++;
      
      setColour();
      
      delay(50);
    }
  }
}

void setColour() {
  analogWrite(RED_PIN, rgbColour[RED]);
  analogWrite(BLUE_PIN, rgbColour[BLUE]);
  analogWrite(GREEN_PIN, rgbColour[GREEN]);
}

