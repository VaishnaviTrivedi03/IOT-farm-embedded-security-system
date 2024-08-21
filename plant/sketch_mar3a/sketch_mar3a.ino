#include <Servo.h>
Servo myservo;  
void setup() {
  // put your setup code here, to run once:
  
myservo.attach(9);  

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
for(int pos=0;pos<=180;pos=pos+2)
   {
   myservo.write(pos);  
   delay(15);
   }   
 delay(5000);

  for(int pos=180;pos>=0;pos=pos-2)
   {
   myservo.write(pos);  
   delay(15);
   }  
 delay(5000);

}
