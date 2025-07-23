#include <Servo.h>
Servo Myservo;

#define trigPin 9           // Trig Pin Of HC-SR04
#define echoPin 8           // Echo Pin Of HC-SR04
#define MLa 4               // Left motor 1st pin
#define MLb 5               // Left motor 2nd pin
#define MRa 6               // Right motor 1st pin
#define MRb 7               // Right motor 2nd pin
#define PWMPin 10           // PWM pin for motor speed control

long duration, distance;
int motorSpeed = 0;

void setup() {
  Serial.begin(9600);
  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(PWMPin, OUTPUT);
  Myservo.attach(10);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  Serial.println(distance);
  delay(10);

  if (distance > 15) {    // No obstacle
    Myservo.write(90);

    // Gradually increase speed to a lower max speed
    for (motorSpeed = 0; motorSpeed <= 100; motorSpeed += 5) {
      analogWrite(PWMPin, motorSpeed);
      digitalWrite(MRb, HIGH);
      digitalWrite(MRa, LOW);
      digitalWrite(MLb, HIGH);
      digitalWrite(MLa, LOW);
      delay(50);  // Slightly longer delay to slow down speed increase
    }

    // Gradually decrease speed from the lower max speed
    for (motorSpeed = 100; motorSpeed >= 0; motorSpeed -= 5) {
      analogWrite(PWMPin, motorSpeed);
      digitalWrite(MRb, HIGH);
      digitalWrite(MRa, LOW);
      digitalWrite(MLb, HIGH);
      digitalWrite(MLa, LOW);
      delay(50);  // Slightly longer delay to slow down speed decrease
    }
    
  } else if (distance < 10 && distance > 0) {  // Obstacle detected
    analogWrite(PWMPin, 0);  // Stop motors
    digitalWrite(MRb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MLa, LOW);
    delay(100);

    Myservo.write(0);
    delay(500);
    Myservo.write(180);
    delay(500);
    Myservo.write(90);
    delay(500);

    // Reverse at a very low speed
    analogWrite(PWMPin, 50);  // Low speed for reverse
    digitalWrite(MRb, LOW);
    digitalWrite(MRa, HIGH);
    digitalWrite(MLb, LOW);
    digitalWrite(MLa, HIGH);
    delay(500);

    analogWrite(PWMPin, 0); // Stop
    delay(100);

    // Move left at low speed
    analogWrite(PWMPin, 50);
    digitalWrite(MRb, HIGH);
    digitalWrite(MRa, LOW);
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW);
    delay(500);
    
    analogWrite(PWMPin, 0); // Stop
  }
}
