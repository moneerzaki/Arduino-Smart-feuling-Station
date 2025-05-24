# project

# Smart Banzina - Embedded Systems Project

*An embedded system for streamlined fuel selection and dispensing.*

## 📖 Overview
**Smart Banzina** is an Arduino-based embedded system designed to automate fuel station operations. It uses ultrasonic sensors to detect vehicles, a servo-controlled gate for access, an LCD/keypad interface for user input, and RGB LEDs for real-time status updates. The project simulates a fuel station workflow with dynamic pricing, unit conversions, and hardware optimizations.

## 🚀 Features
- **Vehicle Detection**: Ultrasonic sensor triggers servo-controlled gate.
- **User Interface**: 
  - 16x2 LCD (I2C) displays fuel types, prices, and instructions.
  - 4x4 matrix keypad for fuel selection and quantity input.
- **Status Indicators**: RGB LEDs (red/green) show lane availability.
- **Custom Hardware Control**:
  - Register-level PWM for servo motor (no `Servo.h` dependency).
  - Median filtering for ultrasonic sensor noise reduction.
- **Power Management**: Current draw optimization (56 mA idle, 556 mA peak).

## 🛠️ Hardware Components
| Component              | Details                                                                 |
|------------------------|-------------------------------------------------------------------------|
| **Microcontroller**    | Arduino Mega 2560 (ATmega2560, 8-bit AVR, 16 MHz, 8KB SRAM)            |
| **Input Devices**      | HC-SR04 Ultrasonic Sensor, 4x4 Keypad (GPIO matrix)                    |
| **Output Devices**     | SG90 Servo Motor (PWM), 16x2 LCD (I2C), RGB LEDs                       |
| **Power**              | 5V regulated via Arduino, 7–12V input (supports ≥1A peak load)         |

## 💻 Software
- **Language**: C++ (Arduino Framework).
- **Key Libraries**:
  - `LiquidCrystal_I2C` for LCD communication.
  - Custom keypad matrix scanning (adapted from existing libraries).
- **Original Code**:
  - Servo control logic (register-level PWM timing).
  - State machines for workflow (detection → selection → dispensing).
  - Sensor fusion (ultrasonic + servo + LED synchronization).

## 🔧 Setup & Installation
1. **Arduino IDE**: Install [Arduino IDE](https://www.arduino.cc/en/software).
2. **Libraries**: Install via Library Manager:
   - `LiquidCrystal_I2C`
   - `Keypad`
3. **Hardware Connections**:  
   Refer to the [Circuit Design](#circuit-design) section in the [Project Report](https://docs.google.com/document/d/1NTYLodnASU8HxHYVh4s2Tff2L0fprDjRHNhaNvJoEf0).
4. **Upload Code**: Clone this repo and upload `SmartBanzina.ino` to the Arduino Mega.

## 🎥 Demo & Documentation
- **Video Demo**: [Watch Here](https://drive.google.com/file/d/1E7Bo0DQ7smLnztnDFemcEOtmZzSjLCGL/view?usp=drive_link).
- **Full Report**: [Google Docs](https://docs.google.com/document/d/1fz35-EM4pPZMkG0CflypKnJzA1uq7UddoBSqJs_Gv50/edit?usp=sharing).

## ❗ Known Issues
- **Keypad Row 3**: Non-functional due to hardware wiring (code skips affected inputs).
- **Single-Lane Limitation**: Requires RTOS for multi-lane concurrency (future work).

## 👥 Contributors
- **Moneer Zaki**: Custom servo control, sensor filtering.
- **Andrew Aziz**: LCD/keypad interface, state machines.
- **Michael Reda**: Hardware prototyping, power management, documentation.

## 🔮 Future Work
- Integrate RTOS for multi-lane support.
- Add wireless connectivity (Bluetooth/Wi-Fi).
- Replace keypad with touchscreen/membrane matrix.
- Implement energy-saving sleep modes.

## 📜 License
All rights reserved. For academic use only.  
*License details to be determined.*

---

**🏷️ Tags**: `Arduino`, `Embedded Systems`, `C++`, `Automation`, `IoT`
