#include <IRremote.h>

IRrecv IR(10);  // Specify that the IR receiver is connected to pin 10
int ledPin = 8;

void setup() {
  // initialize your variables and peripherals here
  IR.enableIRIn();
  Serial.begin(9600);  
  pinMode(ledPin,OUTPUT);
}

void loop() {
  if (IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    if (IR.decodedIRData.decodedRawData == 0xF30CFF00){
      digitalWrite(ledPin, HIGH);
    }
    if (IR.decodedIRData.decodedRawData == 0xBA45FF00){
      digitalWrite(ledPin, LOW);
    }
    delay (500);
    IR.resume();
  }
}
