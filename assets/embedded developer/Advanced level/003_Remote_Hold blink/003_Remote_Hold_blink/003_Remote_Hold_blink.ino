#include <IRremote.h>

IRrecv IR(10);  // Specify that the IR receiver is connected to pin 10
int ledPin = 8;
bool ledOn = false; // Add a variable to keep track of the LED status

void setup() {
  // initialize your variables and peripherals here
  IR.enableIRIn();
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    if (IR.decodedIRData.decodedRawData == 0xF30CFF00){
      digitalWrite(ledPin, HIGH);
      ledOn = true; // Update the LED status
    }
    // Check if the LED is already on before turning it off
    else if (IR.decodedIRData.decodedRawData == 0xF30CFF00 && ledOn) {
      digitalWrite(ledPin, LOW);
      ledOn = false; // Update the LED status
    }
    delay(500);
    IR.resume();
  }
}
