#include <Servo.h>

#define servo1pin 10
#define servo2pin 11
#define servo3pin 12
int drill = 13;

int origin;
int new_position = 19;

Servo Servo1;
Servo Servo2;
Servo Servo3;

void coordinate();

void coordinate(int new_position){
  for(int i = 0; i <= new_position; i++){
    Servo1.write(10 * i); 
  }                                //make servo motor increases the joint angle
    for(int i = new_position; i >= 0; i--){
      Servo2.write(10 * i);
    }                             //make servo motor decreases the joint angle
    for(int i = 0; i <= new_position; i++){
    Servo3.write(10 * i);
    }                                 //make servo motor increases the joint angle
    delay(2000);
    
  }


void setup() {
  Serial.begin(9600);
  Servo1.attach(servo1pin);
  Servo2.attach(servo2pin);
  Servo3.attach(servo3pin);
  pinMode(drill, OUTPUT);
}

void loop() {
  //How do we make servo 1 and servo 2 move together to produce a linear motion
  //We need an equation that control the three motor at the same time
  coordinate(new_position);
  digitalWrite(drill, HIGH);
}
