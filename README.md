# Auto Mapping Robot

A robotics project built from scratch and developed iteratively.

## V1 - Obstacle Avoider
A basic obstacle avoiding robot built with:
- Arduino Uno
- Yellow TT motors + L293D motor driver
- HC-SR04 ultrasonic sensor with servo scanning
- 3D printed chassis with TPU tyres

 ## V1 Demo
[Watch V1 Demo on YouTube](https://youtube.com/shorts/Y9Q5X9wWSWw?feature=share)

## V1 Wiring Diagram
[View Interactive Wiring Diagram on Tinkercad](https://www.tinkercad.com/things/75Oj16kDxqk-robot-v1?sharecode=yF1RWpoD56LifieOwd04A0fuAOCS2tub_IfE0-5JYVY)

## CAD
- Main chassis: designed in Fusion (original design)
  
  <img width="1553" height="799" alt="image" src="https://github.com/user-attachments/assets/4f9e0489-0589-4c9a-af01-494db660cc42" />

- Servo/HC-SR04 mount: downloaded from (https://www.printables.com/model/84061-ultrasonic-sensor-hc-sr04-mount-on-servo)
- Wheels/tyres: downloaded from (https://makerworld.com/en/models/620695-tt-motor-wheel?from=search#profileId-544703)

## V2 - Autonomous Mapping Robot (In Development)
Rebuilt from a salvaged Eufy RoboVac with:
- Arduino Uno + ESP32 (WiFi + Bluetooth)
- Eufy vacuum drive motors with built in encoders
- MPU6500 IMU for heading
- HC-SR04 ultrasonic sensor with servo scanning
- Xbox Series controller via Bluetooth
- Real time room mapping transmitted to PC
- 3D printed chassis with TPU tyres
## V2 Roadmap
- [x] Basic obstacle avoidance (V1)
- [x] Servo scanning with HC-SR04
- [x] IMU integration
- [ ] Encoder odometry
- [x] Increase scanning resolution
- [ ] ESP32 WiFi integration
- [ ] Xbox controller via Bluetooth
- [ ] Room mapping algorithm
- [ ] Real time map transmission to PC
- [ ] Python map visualisation
- [ ] Pathfinding to target coordinates
- [ ] 3D printed V2 chassis
- [ ] TB6612FNG motor driver upgrade
## Status
V1 complete. V2 actively in development.
