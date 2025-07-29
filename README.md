# Overcurrent Monitor using Arduino Uno

This project uses an **ACS712 current sensor**, **Arduino Uno**, **relay module**, and **LCD display** to monitor real-time current. If the current exceeds a threshold, the relay automatically turns off the circuit to protect it.

## Components
- Arduino Uno  
- ACS712 5A Current Sensor  
- 16x2 LCD Display (I2C)  
- Relay Module (5V)  
- LED Load + 9V Battery  
- Jumper Wires, Potentiometer

## Features
- Real-time current and voltage display on LCD  
- Relay triggers OFF when overcurrent is detected  
- LCD shows messages like "Current Normal" or "Overload"  
- Calibrated using serial monitor and multimeter

## LCD Output Example
- V: 2.49 A: 0.11

## What I Learned
- Analog signal processing with sensors  
- Relay control and load protection logic  
- I2C LCD interfacing  
- Debugging sensor noise and calibration

## Future Ideas
- Add a buzzer for overload warning  
- Save readings to SD card or database  
- Add cloud alerts via IoT

---
