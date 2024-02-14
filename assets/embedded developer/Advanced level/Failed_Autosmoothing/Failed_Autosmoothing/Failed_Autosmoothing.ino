#include <IRremote.h>

IRrecv IR(10);  // Specify that the IR receiver is connected to pin 10
int ledPin = 9;
int brightness = 95; // Initial brightness level
int fadeAmount = 5; // Amount to increase/decrease brightness by
unsigned long buttonPressTime = 0; // Time that the button was pressed
int zeroCounter = 0; // Counter for consecutive zero readings

void setup() {
  IR.enableIRIn();
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);
}

void loop() {
  analogWrite(ledPin, brightness);
  
  if (IR.decode()) {
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    
    if (IR.decodedIRData.decodedRawData == 0xE916FF00) {
      // Button is pressed
      buttonPressTime = millis();
    } else if (IR.decodedIRData.decodedRawData == 0xE916FF00) {
      // Button is released
      
      if (millis() - buttonPressTime > 2000) {
        // Button was held down for more than 2 seconds
        fadeAmount = 5;
        zeroCounter = 0;
      } else if (zeroCounter >= 10) {
        // Button is being held down continuously
        if (brightness > 5 && brightness < 250) {
          brightness += fadeAmount;
          brightness = min(255, max(0, brightness));
        }
      } else {
        // Button was tapped
        brightness = min(255, max(5, brightness + fadeAmount));
      }
      
      analogWrite(ledPin, brightness);
      zeroCounter = 0;
    } else if (IR.decodedIRData.decodedRawData == 0xE619FF00) {
      // Button is pressed
      buttonPressTime = millis();
    } else if (IR.decodedIRData.decodedRawData == 0xE619FF01) {
      // Button is released
      
      if (millis() - buttonPressTime > 2000) {
        // Button was held down for more than 2 seconds
        fadeAmount = 5;
        zeroCounter = 0;
      } else if (zeroCounter >= 10) {
        // Button is being held down continuously
        if (brightness > 5 && brightness < 250) {
          brightness -= fadeAmount;
          brightness = min(255, max(0, brightness));
        }
      } else {
        // Button was tapped
        brightness = min(255, max(5, brightness - fadeAmount));
      }
      
      analogWrite(ledPin, brightness);
      zeroCounter = 0;
    } else if (IR.decodedIRData.decodedRawData == 0xFFFFFFFF) {
      // Invalid button press
      zeroCounter++;*
    } else {
      // Valid button press
      zeroCounter = 0;
    }
    
    IR.resume();
  }
}




















#include <IRremote.h>

IRrecv IR(10);  // Specify that the IR receiver is connected to pin 10
int ledPin = 9;
int brightness = 95; // Initial brightness level
int fadeAmount = 5; // Amount to increase/decrease brightness by

const int buttonPin = 2; // button pin
int lastButtonState = LOW; // previous button state
int buttonState; // current button state
unsigned long lastDebounceTime = 0; // last time the button was debounced
unsigned long debounceDelay = 50; // debounce time in milliseconds
unsigned long buttonPressTime = 0; // time when the button was pressed

void setup() {
  IR.enableIRIn();
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  analogWrite(ledPin, brightness);

  // Check if the button is pressed and debounce it
  int buttonPress = debounceButton();
  if (buttonPress != -1) {
    if (buttonPress == HIGH) {
      buttonPressTime = millis();
    } else {
      unsigned long buttonReleaseTime = millis();
      unsigned long buttonDuration = buttonReleaseTime - buttonPressTime;
      if (buttonDuration > 2000) {
        fadeAmount = 50;
      } else {
        fadeAmount = 5;
      }
    }
  }

  // Check for IR remote signal
  if (IR.decode()) {
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    if (IR.decodedIRData.decodedRawData == 0xE916FF00){
      // Increase brightness
      brightness = min(255, brightness + fadeAmount);
      analogWrite(ledPin, brightness);
    } else if (IR.decodedIRData.decodedRawData == 0xE619FF00){
      // Decrease brightness
      brightness = max(5, brightness - fadeAmount);
      analogWrite(ledPin, brightness);
    }
    IR.resume();
  }
}

int debounceButton() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      return buttonState;
    }
  }

  lastButtonState = reading;
  return -1;
}
