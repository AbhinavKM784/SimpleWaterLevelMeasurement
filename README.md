#  Water Level Monitoring System
This project is a neat, automated way to keep tabs on your water levels. It uses an ultrasonic sensor to 'see' where the water is, an Arduino to calculate the depth, and an OLED display to show you the exact water level the second it changes
<img width="2752" height="1536" alt="imagees" src="https://github.com/user-attachments/assets/87d7f248-6d19-44b9-a3a7-efd39a458df8" />
---
# Components Used

| Component | Quantity |
|---|---|
| Arduino Uno/Nano | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| 0.96" OLED Display (I2C SSD1306) | 1 |
| Jumper Wires | Few |

---

#  Working Principle

The **HC-SR04 ultrasonic sensor** measures the distance from the sensor to the water surface using ultrasonic waves.

The Arduino monitors water levels by sending an ultrasonic trigger pulse, measuring the echo return time to calculate distance, converting that distance into a water level reading, and finally displaying the live results onto an OLED screen.

---

#  Circuit Connections

<img width="1680" height="1117" alt="image" src="https://github.com/user-attachments/assets/503d5f7c-3760-4582-a007-05f85ad7bbab" />


---

#  Project Preview

<img width="1280" height="720" alt="WhatsApp Image 2026-05-27 at 16 30 09" src="https://github.com/user-attachments/assets/0973cc99-3c8c-4804-b546-8b7d04aa7f85" />
Booting process


https://github.com/user-attachments/assets/d72b4f6a-3e16-4e79-9ae6-1df065d3e32d

