# automatic-object-sensing-Robot
**# Obstacle Avoiding Robot using Arduino 🚗🤖

This project is an **Obstacle Avoiding Robot** built using an **Arduino Uno**, an **HC-SR04 ultrasonic sensor**, **L298N motor driver (or equivalent H-bridge wiring)**, and a **servo motor**. The robot uses distance sensing to detect nearby obstacles and navigates around them.

## 🔧 Components Used

- Arduino Uno
- HC-SR04 Ultrasonic Distance Sensor
- L298N Motor Driver or equivalent (using 4 motor control pins)
- Servo Motor (SG90 or similar)
- 2 DC Motors + Wheels
- Chassis (2WD)
- Jumper Wires
- Power Supply (Battery Pack)
- Breadboard (optional)

## 🧠 Features

- Obstacle detection using ultrasonic sensor
- Forward motion with smooth acceleration and deceleration
- Obstacle scanning with servo-mounted ultrasonic sensor
- Intelligent reversing and left turn when obstacle is detected
- PWM-based speed control
- Serial Monitor output of distance data

## 📁 Arduino Code Overview

### Pin Definitions:

```cpp
#define trigPin 9     // Ultrasonic Trigger Pin
#define echoPin 8     // Ultrasonic Echo Pin
#define MLa 4         // Left Motor A
#define MLb 5         // Left Motor B
#define MRa 6         // Right Motor A
#define MRb 7         // Right Motor B
#define PWMPin 10     // Motor speed control via PWM
**
