// ACS712 Current Sensor with LCD and Relay
// Author: Sashwath Narayanan (2025)
// Description: Monitors current using ACS712, displays it on LCD, and turns off relay if current exceeds threshold

#include <LiquidCrystal_I2C.h>

// LCD setup (I2C address may vary: 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins
const int sensorPin = A0;     // ACS712 output connected to A0
const int relayPin = 7;       // Relay control pin
const float sensitivity = 0.185;  // For ACS712-5A version: 185 mV per A

// Variables
float voltage = 0;
float current = 0;
float thresholdCurrent = 1.5;  // Set your limit in Amps

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  
  digitalWrite(relayPin, HIGH);  // Keep relay ON initially
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // Raw value from 0–1023
  voltage = (sensorValue * 5.0) / 1023.0;   // Convert to volts (0–5V)
  current = (voltage - 2.5) / sensitivity;  // Centered around 2.5V

  // Print to serial monitor
  Serial.print("Raw: ");
  Serial.print(sensorValue);
  Serial.print("  Voltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V  Current: ");
  Serial.print(current, 2);
  Serial.println(" A");

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("V:");
  lcd.print(voltage, 2);
  lcd.print(" A:");
  lcd.print(current, 2);
  
  lcd.setCursor(0, 1);
  if (current > thresholdCurrent) {
    lcd.print("Overload!");
    digitalWrite(relayPin, LOW); // Turn OFF relay
  } else {
    lcd.print("Current Normal");
    digitalWrite(relayPin, HIGH); // Turn ON relay
  }

  delay(500);
}
