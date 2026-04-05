# Arduino Projects — Task 1 Submission

## Goal
Foundational control logic and circuit design for robotics and aerospace applications.
This repository contains Tinkercad simulations, circuit diagrams, and Arduino source 
code for Task 1, progressing from basic LED control to a fully interactive system.

---

## Section A — Core Logic and Sensor Math

### Question 1: Non-Blocking LED Control
**Tinkercad Link:** https://www.tinkercad.com/things/17Rnpr7hSQp-brave-habbi-maimu

The traditional delay() function freezes the entire Arduino program while waiting.
This project replaces it with a non-blocking approach using millis(), which acts like
a continuous stopwatch. The Arduino checks elapsed time on every loop and toggles the
LED only when the required interval has passed — keeping the rest of the code free to
run simultaneously.

---

### Question 2: Multi-Output Control (Potentiometer & RGB LED)
**Tinkercad Link:**  https://www.tinkercad.com/things/6z0LdRCBtsW-spectacular-fyyran

Building on the non-blocking logic from Question 1, this circuit reads an analog input
from a potentiometer using analogRead() and simultaneously controls two outputs.
The pot value dynamically adjusts the blink rate of a standard LED, while a map()
function crossfades a PWM RGB LED through color zones (Red → Green → Blue) based
on the knob position — all without any blocking delays.

---

### Question 3: Reaction Time Tester
**Tinkercad Link:** https://www.tinkercad.com/things/2tJsoAlLS0i-surprising-blad

This circuit operates as a two-stage state machine. It uses random() with millis()
to wait an unpredictable amount of time before turning on an LED. The user must press
a pushbutton as fast as possible. INPUT_PULLUP is used so no external resistor is
needed — the pin reads HIGH by default and LOW when pressed.

**Sensor Math:**
Reaction Time (ms) = millis() at button press − millis() when LED turned ON

---

## Section B — Mini Project

### Automatic Night Lamp (LDR + Potentiometer)
**Tinkercad Link:** https://www.tinkercad.com/things/1NW3DqwFM6x-surprising-borwo

This project uses an LDR (Light Dependent Resistor) to detect ambient light levels
and automatically controls LED brightness using PWM. A potentiometer is added to
allow manual adjustment of the sensitivity threshold without changing the code.

**Components Used:**
- Arduino Uno — reads sensor values and controls LED brightness
- LDR (Photoresistor) — detects ambient light level
- 10kΩ resistor — forms a voltage divider with the LDR
- 10kΩ Potentiometer — adjusts the sensitivity threshold via A1
- LED + 220Ω resistor — output lamp controlled by PWM
- Breadboard + jumper wires — distribute power and signals

**How the circuit works:**
The LDR and 10kΩ resistor form a voltage divider connected to analog pin A0.
As ambient light decreases, the LDR resistance increases, causing the voltage
at A0 to drop. The potentiometer connected to A1 acts as an adjustable threshold
— turning the knob makes the lamp more or less sensitive to darkness.

**Sensor Math:**
Voltage at A0 = 5V × (10kΩ / (LDR resistance + 10kΩ))

As light decreases → LDR resistance increases → voltage at A0 decreases
→ Arduino reads lower analogRead() value → LED brightness increases

**PWM Brightness Mapping:**
brightness = map(lightValue, 0, threshold, 255, 0)
brightness = constrain(brightness, 0, 255)
analogWrite(9, brightness)

- lightValue ranges from 0 to 1023 (analogRead)
- brightness ranges from 0 to 255 (analogWrite PWM)
- Darker room = higher brightness output
- Potentiometer dynamically sets the upper threshold
---

## Repository Structure
```
Arduino-Projects/
├── README.md
├── Task_1/
│   ├── Section_A/
│   │   ├── Blinking_Light/
│   │   │   └── BLINKING_LED.ino
│   │   ├── Reaction_time_sensor/
│   │   │   └── REACTION_TIME_SENSOR.ino
│   │   └── RGB_light/
│   │       └── RGB_LIGHT.ino
│   └── Section_B/
│       └── MINI_Project.ino
```
