#include <Arduino.h>

// GPIO 36
const int buttonPin = 36;

// Define the threshold values for each button
const int button1MinThreshold = 1400;
const int button1Threshold = 1500;
const int button2Threshold = 2300;
const int button3Threshold = 3300;

int buttonState = 0;
int lastButtonState = 0;

void setup() {
  Serial.begin(115200);

  pinMode(buttonPin, INPUT);
}

void loop() {
  // Read the analog value from the button pin
  int buttonValue = analogRead(buttonPin);

  // Determine which button is pressed based on the analog value
  if ((buttonValue < button1Threshold) && (buttonValue > button1MinThreshold)) {
    buttonState = 1;
  }
  else if ((buttonValue < button2Threshold) && (buttonValue > button1MinThreshold)) {
    buttonState = 2;
  }
  else if ((buttonValue < button3Threshold) && (buttonValue > button1MinThreshold)) {
    buttonState = 3;
  }
  else {
    buttonState = 0;
  }

  // Check if the button state has changed
  if (buttonState != lastButtonState) {
    // Print the new button state to the serial monitor
    switch (buttonState) {
      case 0:
        Serial.println("No button pressed");
        break;
      case 1:
        Serial.println("Button 1 pressed");
        break;
      case 2:
        Serial.println("Button 2 pressed");
        break;
      case 3:
        Serial.println("Button 3 pressed");
        break;
    }

    // Update the last button state
    lastButtonState = buttonState;
  }

  // Delay for a short period of time to debounce the button
  delay(50);
}