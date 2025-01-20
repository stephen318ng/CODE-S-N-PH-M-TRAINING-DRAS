#include <MotorDriver.h>
MotorDriver m;

const int trigPin = 9;
const int echoPin = 10;


const int motor1Pin1 = 3;
const int motor1Pin2 = 4;


long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600); 
}

void moveForward() {
  m.motor(3, FORWARD, 255);
  m.motor(4, FORWARD, 255);
}

void moveBackward() {
  m.motor(3, BACKWARD, 255);
  m.motor(4, BACKWARD, 255);
}

void stopMotor() {
  m.motor(3, FORWARD, 0);
  m.motor(4, FORWARD, 0);
}

void turnMotor(){
  m.motor(3, BACKWARD, 255);
  m.motor(4, FORWARD, 255);

}


void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 20) {  
    stopMotor();       
    delay(500);         
    moveBackward();     
    delay(1000);        
    turnMotor();
    delay(1000);
    

  } else {
    moveForward();
  }

  
}

