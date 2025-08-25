# Miniature Crane – Arduino Motor Control System

This project implements the control system for a **miniature crane** designed to lift a load of up to **2 kg vertically by 300 mm**.  
The system combines **PWM motor control**, **switch/button inputs**, **potentiometer-based load measurement**, and an **OLED display** for real-time monitoring.

---

## Features
- **Motor Control**
  - PWM speed regulation using an H-bridge motor driver
  - Direction control (Up/Down/Stop) via push buttons and switches

- **Sensor Feedback**
  - Potentiometer input to estimate load weight (in kilograms) and calculate force (Newtons)
  - Turn counter logic using motor feedback pins

- **OLED Display**
  - Displays crane direction (Up/Down/Stopped)
  - Shows load weight (kg), force (N), and motor turns

---

## Project Structure
- `crane_control.ino` – main Arduino code (setup, loop, motor control, sensor reading, display output)

---

## Technologies Used
- **Arduino C++**
- **Adafruit SH1107 OLED display** (`Adafruit_SH110X.h`, `Adafruit_GFX.h`)
- **PWM motor driver control**
- Digital I/O for switches and feedback
- Analog input for potentiometer-based load sensing
