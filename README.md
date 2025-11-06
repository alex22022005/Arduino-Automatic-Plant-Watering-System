# 🌿 Arduino Automatic Plant Watering System

A simple Arduino project to automate plant watering. This sketch reads data from a soil moisture sensor and activates a water pump (via a relay or motor driver) when the soil becomes too dry.

## 🚀 Features
* **Real-time Monitoring:** Continuously checks the soil moisture level.
* **Automatic Control:** Automatically turns a water pump ON when soil is dry and OFF when it's wet.
* **Adjustable Threshold:** Easily change the `threshold` variable in the code to match your plant's needs.
* **Serial Feedback:** Prints the current moisture value to the Serial Monitor for easy calibration and debugging.

## Hardware Required
* Arduino (e.g., Uno, Nano)
* Capacitive Soil Moisture Sensor (Analog)
* 5V Relay Module (or a transistor like a TIP120)
* Small Water Pump (e.g., 5V submersible pump)
* Jumper Wires
* (Optional) Separate power supply for the pump

## 🔌 Wiring Diagram

### 1. Soil Moisture Sensor
* `VCC` -> `5V` on Arduino
* `GND` -> `GND` on Arduino
* `AOUT` (Analog Out) -> `A0` on Arduino

### 2. Relay Module & Pump
* `VCC` -> `5V` on Arduino
* `GND` -> `GND` on Arduino
* `IN` (Input) -> `Pin 8` on Arduino

> **Warning:** Never connect a motor or pump directly to an Arduino's digital pin. Always use a relay or transistor to handle the higher current.

* Connect the **+** wire of your pump to the `NO` (Normally Open) terminal on the relay.
* Connect the **-** wire of your pump to the `GND` of its power supply (this can be the Arduino's `GND` if it's a very small 5V pump).
* Connect the `COM` (Common) terminal on the relay to the `+` (positive) of the pump's power supply (e.g., `5V` on the Arduino or an external source).

## 💡 How to Use

1.  **Assemble** the circuit as shown in the wiring section.
2.  **Upload** the code from `main.ino` to your Arduino.
3.  **Calibrate the Sensor:**
    * Open the Arduino IDE's **Serial Monitor** (set to 9600 baud).
    * With the sensor in the air, note the value (e.g., `800+`).
    * Place the sensor in a glass of water and note the value (e.g., `350`).
    * Test the sensor in your plant's soil when it feels "dry" and "wet".
    * Based on these tests, change the `int threshold = 500;` line in the code to your desired trigger point. (Note: For many capacitive sensors, a *lower* number means *wetter*).
4.  Re-upload the code with your new `threshold`.
5.  Place the sensor in your plant pot and the pump in your water reservoir.

## 💻 The Code

```arduino
const int soilMoisturePin = A0;  // Analog pin for soil moisture sensor
const int motorPin = 8;          // Digital pin to control motor/relay
int soilMoistureValue = 0;       // Variable to store moisture value
int threshold = 500;             // Adjust this threshold based on your soil and sensor

void setup() {
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW);   // Make sure motor is OFF initially
  Serial.begin(9600);
}

void loop() {
  soilMoistureValue = analogRead(soilMoisturePin);
  Serial.print("Soil Moisture Value: ");
  Serial.println(soilMoistureValue);

  // Note: On many capacitive sensors, LOW value means WET
  // Check your sensor's behavior
  if (soilMoistureValue < threshold) {
    digitalWrite(motorPin, HIGH);  // Turn ON motor
    Serial.println("Soil is dry. Pump ON.");
  } else {
    digitalWrite(motorPin, LOW);   // Turn OFF motor
    Serial.println("Soil is wet. Pump OFF.");
  }
  delay(1000);  // Wait for a second before next reading
}
```
---
## 📄 License
This project is open-source and available under the MIT License.
