#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  
    myservo.write(180);              // tell servo to go to position in variable 'pos'
                          // waits 15ms for the servo to reach the position
    
  // goes from 180 degrees to 0 degrees
                       // waits 15ms for the servo to reach the position
  
}