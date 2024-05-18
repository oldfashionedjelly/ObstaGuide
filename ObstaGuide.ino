const int trigPin = 9;
const int echoPin = 10;
#include <Servo.h>
Servo myServo;

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  myServo.attach(8);

  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2; 
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);
  if(distance<20) {
    myServo.write(0);  
    delay(1000);        
    myServo.write(90);  
    delay(1000);       
    myServo.write(180); 
    delay(1000);
    myServo.write(0);  
    delay(1000);        
    myServo.write(90);  
    delay(1000);       
    myServo.write(180); 
    delay(1000);
  }
}
