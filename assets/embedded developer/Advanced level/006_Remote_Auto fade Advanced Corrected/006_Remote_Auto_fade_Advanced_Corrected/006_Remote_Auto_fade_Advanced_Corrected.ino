#include <IRremote.h>

IRrecv IR(10);  // Specify that the IR receiver is connected to pin 10
int ledPin = 9;
bool ledOn = false; // Add a variable to keep track of the LED status
int brightness = 10; // Initial brightness level
int fadeAmount = 5;  // How many points to fade the LED by

void setup() {
  // initialize your variables and peripherals here
  IR.enableIRIn();
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    if (IR.decodedIRData.decodedRawData == 0xBA45FF00){
      // Toggle the LED state
      ledOn = !ledOn;
      digitalWrite(ledPin, ledOn ? (brightness > 0 ? HIGH : LOW) : LOW);
    } else if (IR.decodedIRData.decodedRawData == 0xE916FF00){
      // Reduce brightness
      if (brightness > 0) {
        brightness = max(0, brightness - 1);
      }
      
      // Auto fading
      if (brightness == 0) {
        fadeAmount = abs(fadeAmount);
      } else if (brightness == 10) {
        fadeAmount = -abs(fadeAmount);
      }
      brightness = max(0, min(10, brightness + fadeAmount));
      analogWrite(ledPin, brightness * 255 / 10);
    }
    
    IR.resume();
  }
}
