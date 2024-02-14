#include <IRremote.h>

IRrecv IR(10);  // Specify that the IR receiver is connected to pin 6

void setup() {
  // initialize your variables and peripherals here
  IR.enableIRIn();
  Serial.begin(9600);  
}

void loop() {
  if (IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    delay (500);
    IR.resume();
  }
}
