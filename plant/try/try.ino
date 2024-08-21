#include <Servo.h>
#include <DHT.h>
#define dht_apin 11 
DHT dhtObject;
Servo myservo;  
int flag;  
const int buzzer=13;
const int trigPin = 4;
const int echoPin = 2;
float duration, distance;


void setup() 
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT); 
myservo.attach(9);  
dhtObject.setup(11);
Serial.begin(9600);
}


void loop()
{ 
  
  check_motion();
  check_moisture();
  check_temperature();
  Serial.println("******************");
  delay(3000);
}


// SERVO

void servo_active()
 {
   
  myservo.write(180);     
   
 }
void servo_deactive()
  {
    
     myservo.write(0);        
    
  }

// Temperature


void check_temperature()
{
  int temp = dhtObject.getTemperature();
  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.print("\n");
  if(temp>=30)
  {
    for(int t=0;t<=3000;t=t+1000){
      tone(buzzer, 1000);
      delay(100);
      noTone(buzzer); 
      delay(100);}
  
    
    servo_active();

    flag=1;
  }
  else
  {  
     
     if(flag==1)
     {
      servo_deactive();
     }
  }
 
}




// motion
void check_motion()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  int dis=distance;
  Serial.print("Distance: ");
  Serial.println(dis);
  if (dis<10)
  {  
     for(int t=0;t<=3000;t=t+1000){
      tone(buzzer, 1000);
      delay(100);
      noTone(buzzer); 
      delay(200);}
  }
}

// moisture

void check_moisture() {
  
  int sensorValue = analogRead(A1);
  Serial.print("moisture=");
  Serial.println(sensorValue);
  if(sensorValue>2000)
  {
     
      tone(buzzer, 1000);
      delay(2000);
      noTone(buzzer); 
      delay(1000);}
  }
    





