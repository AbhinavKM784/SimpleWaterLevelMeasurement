# 💧 Water Level Monitoring System

A simple and efficient **Water Level Measuring System** built using an **Arduino**, **HC-SR04 Ultrasonic Sensor**, and **OLED Display**.  
The system measures the distance between the sensor and water surface, calculates the water level, and displays the information in real time.
<img width="2752" height="1536" alt="imagees" src="https://github.com/user-attachments/assets/87d7f248-6d19-44b9-a3a7-efd39a458df8" />
---

# 📌 Features

- 📏 Real-time water level measurement
- 📺 OLED display output
- 🔊 Non-contact ultrasonic sensing
- ⚡ Low-cost and beginner-friendly
- 🛠 Easy to build and customize

---

# 🧰 Components Used

| Component | Quantity |
|---|---|
| Arduino Uno/Nano | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| 0.96" OLED Display (I2C SSD1306) | 1 |
| Jumper Wires | Few |
| Breadboard for testing| 1 |
| USB Cable | 1 |

---

# 🖼 Working Principle

The **HC-SR04 ultrasonic sensor** measures the distance from the sensor to the water surface using ultrasonic waves.

The Arduino:
1. Sends a trigger pulse
2. Measures echo return time
3. Calculates distance
4. Converts it into water level
5. Displays the result on the OLED screen

---

# 🔌 Circuit Connections

## HC-SR04 Connections

| HC-SR04 | Arduino |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | D9 |
| ECHO | D10 |

---

## OLED Display Connections

| OLED | Arduino |
|---|---|
| VCC | 3.3v|
| GND | GND |
| SDA | A4 |
| SCL | A5 |


---

# 📷 Project Preview

<img width="1280" height="720" alt="WhatsApp Image 2026-05-27 at 16 30 09" src="https://github.com/user-attachments/assets/0973cc99-3c8c-4804-b546-8b7d04aa7f85" />
Booting process


https://github.com/user-attachments/assets/d72b4f6a-3e16-4e79-9ae6-1df065d3e32d






```md
![Project Image](images/project.jpg)
