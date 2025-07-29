// Defining pins
const int ledPin = 13;
const int buttonPin = 2;
const int ldrPin = A0;

// Constants
const int ldrThreshold = 500; // Lower = darker.
const unsigned long timeoutDuration = 5000; // 5 seconds before turning off
const int ledFlashDelay = 200; // Flash delay

// State variables
bool ledState = false;
bool lastButtonState = HIGH; // Pull-up logic so no need for resistor (HIGH = not pressed)
bool waitingForTimeout = false;
unsigned long timeoutStart = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600); // For debugging
}

void loop() {
  // Reading inputs
  int ldrValue = analogRead(ldrPin);
  bool isDim = ldrValue < ldrThreshold;
  bool buttonPressed = digitalRead(buttonPin) == LOW;

  // BUTTON PRESS HANDLING
  if (buttonPressed && lastButtonState == HIGH) {
    // Button just pressed
    if (ledState) {
      if (!isDim) {
        turnOffLED();
        waitingForTimeout = false;
      } else {
        // If Button OFFs and the LDR is dim, it will be ON again
        turnOffLED();
        delay(100);
        flashLED(3);
        turnOnLED();
        waitingForTimeout = false;
      }
    } else {
      // Button toggles ON
      flashLED(3);
      turnOnLED();
      if (!isDim) {
        timeoutStart = millis();
        waitingForTimeout = true;
      } else {
        waitingForTimeout = false;
      }
    }
  }

  // LDR HANDLING (if LED is OFF and dim is detected)
  if (!ledState && isDim) {
    flashLED(3);
    turnOnLED();
    waitingForTimeout = false;
  }

  // LED Timeout Handling
  if (ledState && !isDim && !waitingForTimeout) {
    // Start timeout
    timeoutStart = millis();
    waitingForTimeout = true;
  }

  if (waitingForTimeout && millis() - timeoutStart >= timeoutDuration) {
    // Timeout expired
    if (!isDim) {
      turnOffLED();
    }
    waitingForTimeout = false;
  }

  // Update button state
  lastButtonState = !buttonPressed ? HIGH : LOW;
}


// Helper functions

void flashLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(ledPin, HIGH);
    delay(ledFlashDelay);
    digitalWrite(ledPin, LOW);
    delay(ledFlashDelay);
  }
}

void turnOnLED() {
  digitalWrite(ledPin, HIGH);
  ledState = true;
}

void turnOffLED() {
  digitalWrite(ledPin, LOW);
  ledState = false;
}
