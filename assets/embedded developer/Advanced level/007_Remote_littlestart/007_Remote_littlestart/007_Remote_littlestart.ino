#include <IRremote.h>

IRrecv IR(10);  // Specify that the IR receiver is connected to pin 10
int ledPin = 9;
int brightness = 95; // Initial brightness level
int fadeAmount = 50; // Amount to increase/decrease brightness by

void setup() {
  IR.enableIRIn();
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);
  analogWrite(ledPin, brightness);
  
}

void loop() {
  
  if (IR.decode()){
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
