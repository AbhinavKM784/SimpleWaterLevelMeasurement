#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 32
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define TRIG_PIN     9
#define ECHO_PIN     10
#define TANK_HEIGHT  18  // Total tank height in cm

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 not found");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(20, 12);
  display.println("Water Level Meter");
  display.display();
  delay(1500);
}

long measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return -1;
  return duration * 0.0343 / 2;
}

void loop() {
  long distance = measureDistance();

  display.clearDisplay();

  if (distance < 0 || distance > TANK_HEIGHT) {
    display.setTextSize(1);
    display.setCursor(22, 4);
    display.println("Sensor Error!");
    display.setCursor(16, 18);
    display.println("Check placement.");

  } else {
    long waterLevel = TANK_HEIGHT - distance;
    waterLevel = constrain(waterLevel, 0, TANK_HEIGHT);
    int percent = map(waterLevel, 0, TANK_HEIGHT, 0, 100);

    // ── Left block: label + water level cm ──
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Water Level");

    display.setTextSize(2);
    String lvlStr = String(waterLevel) + "cm";
    display.setCursor(0, 14);
    display.println(lvlStr);

    // ── Middle: percentage ──
    display.setTextSize(1);
    String pctStr = String(percent) + "%";
    display.setCursor(72, 14);
    display.println(pctStr);

    // ── Right: vertical tank graphic ──
    // Outer tank outline (10x28 px)
    display.drawRect(114, 2, 12, 28, SSD1306_WHITE);

    // Water fill from the bottom
    int fillHeight = map(percent, 0, 100, 0, 26);
    fillHeight = constrain(fillHeight, 0, 26);
    display.fillRect(115, 2 + (26 - fillHeight), 10, fillHeight, SSD1306_WHITE);

    // "FULL" / "LOW" label
    display.setTextSize(1);
    if (percent >= 80) {
      display.setCursor(68, 0);
      display.println("FULL");
    } else if (percent <= 20) {
      display.setCursor(72, 0);
      display.println("LOW");
    } else {
      display.setCursor(68, 0);
      display.println("OK");
    }
  }

  display.display();

  // Serial output
  if (distance >= 0 && distance <= TANK_HEIGHT) {
    long waterLevel = constrain(TANK_HEIGHT - distance, 0, TANK_HEIGHT);
    int percent = map(waterLevel, 0, TANK_HEIGHT, 0, 100);
    Serial.print("Distance: "); Serial.print(distance);   Serial.print(" cm | ");
    Serial.print("Water: ");    Serial.print(waterLevel); Serial.print(" cm | ");
    Serial.print("Level: ");    Serial.print(percent);    Serial.println("%");
  } else {
    Serial.println("Sensor error / out of range");
  }

  delay(500);
}