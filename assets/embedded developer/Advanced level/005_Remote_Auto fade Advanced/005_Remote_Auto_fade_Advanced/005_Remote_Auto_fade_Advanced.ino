#include <IRremote.h>

IRrecv IR(10);  // Specify that the IR receiver is connected to pin 10
int ledPin = 9;
bool ledOn = false; // Add a variable to keep track of the LED status
int brightness = 10; // Initial brightness level

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
      brightness = max(0, brightness - 1);
      analogWrite(ledPin, brightness * 255 / 10);
      
      // Check if button is held for more than 2 seconds
      int holdTime = 0;
      while (IR.decode()) {
        delay(50);
        holdTime += 50;
      }
      if (holdTime >= 2000) {
        while (brightness > 0) {
          brightness = max(0, brightness - 1);
          analogWrite(ledPin, brightness * 255 / 10);
          delay(500);
        }
        digitalWrite(ledPin, LOW);
        ledOn = false;
      }
      
    }
    delay (180);
    IR.resume();
  }
}
