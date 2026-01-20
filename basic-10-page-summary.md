This summary is designed to be copied directly into a markdown file (e.g., `README.md` or `STUDY_GUIDE.md`). It condenses the Maker100-xiaoML-kit curriculum into the essential knowledge required for a "Final Exam."

---

# Maker100: Robotics, IoT, and TinyML Study Guide

**Course Focus:** Economic hardware (XIAO ESP32S3 & RAK2270), Hands-on Machine Learning, and Real-world Interfacing.

---

## 1. Core Hardware & Philosophy

Students must understand the hardware ecosystem and the "Maker Mindset."

* **Primary MCU:** Seeedstudio **XIAO ESP32S3 Sense**.
* **Features:** Integrated camera, digital microphone, and SD card slot.
* **Setup:** Requires ESP32 board manager (v2.0.17 often preferred for stability over v3.x due to deprecation).


* **Secondary MCU:** **RAK2270 Sticker Tracker**.
* **Focus:** LoRa/LoRaWAN and low-power motion sensing.


* **The Golden Rule:** "Until you change computer code, do not expect to understand it."
* **Safety Protocol:** Always draw a circuit diagram **before** connecting wires. Have it checked before applying power.

---

## 2. Machine Learning (TinyML) Workflow

A major portion of the course involves deploying intelligence to the "Edge" using **Edge Impulse** and **SenseCraft**.

### A. Vision Models

| Model Type | Description | Best Use Case |
| --- | --- | --- |
| **Classification** | Identifies *what* is in the image (e.g., "Pen" vs "Background"). | Simple presence detection. |
| **FOMO (Faster Objects, More Objects)** | Detects *where* and *how many* objects are in the frame (Bounding boxes). | Counting items, tracking movement. |
| **Regression** | Outputs a continuous number instead of a label. | Estimating distance or weight via camera. |
| **Anomaly Detection** | Identifies how "different" an object is from the training set. | Quality control, detecting defects. |

### B. Sound & Motion

* **Wake Word Detection:** Using the digital mic to trigger actions (e.g., "Yes/No" detection).
* **Motion (x, y, z):** Using accelerometers to classify gestures or vibrations (deployed on XIAO or RAK2270).

---

## 3. Electronics & Circuit Logic

### A. Fundamentals

* **Ohm's Law:** Used to calculate resistance for LEDs and sensors: .
* **VIDEO-FLAC:** The programming building blocks: **V**ariables, **I**nput/Output, **D**ecisions, **E**vents, **O**bjects, **F**unctions, **L**oops, **A**rrays, **C**lasses.

### B. Input/Output (I/O)

* **Analog Input:** Using a **Voltage Divider** for variable resistors (photoresistors, flex sensors).
* **Pulse Width Modulation (PWM):** Used for dimming LEDs or controlling **Servos**.
* **Communication Protocols:**
* **I2C:** Used for OLEDs and Multiplexers (SDA/SCL pins).
* **UART:** Serial communication between two MCUs (TX/RX pins).
* **SPI:** High-speed communication used for the Pixy2 camera or SD cards.



---

## 4. Actuators & Power Management

Controlling the physical world requires understanding current and voltage limits.

* **Transistors (NPN/PNP):** Used as electronic switches to control high-current devices (motors) that the XIAO pins cannot power directly.
* **Motor Drivers:** * **DC Motors:** Controlled via H-Bridge drivers for speed and direction.
* **Steppers:** Used for precision rotation (requires 6V+ typically).


* **Servos:** Require external power (usually 5-6V) and a shared Ground (GND) with the MCU.

---

## 5. IoT & Connectivity

### A. WiFi & Web

* **Webservers:** Hosting a local page on the XIAO to view camera streams or toggle pins.
* **MQTT:** Using **Adafruit IO** as a dashboard to send/receive data over the internet.

### B. LoRa & LoRaWAN (RAK2270 Focus)

* **P2P (Peer-to-Peer):** Direct communication between two LoRa devices without a gateway.
* **LoRaWAN:** Connecting to a global network (like The Things Network) for long-range tracking.
* **AT Commands:** The standard method for configuring RAK modules (e.g., `AT+JOIN`, `AT+SEND`).

---

## 6. Prototyping & Advanced Tools

* **Data Logging:** Saving JPGs, AVI video, or sensor CSVs to a Micro SD card for offline analysis.
* **Lidar:** Using laser ranging for environment mapping or distance sensing.
* **PCB Design:** Using **EasyEDA** to move from breadboards to permanent printed circuit boards.
* **TinyMLjs:** A static web-based method for processing machine learning data using WebSerial.

---

## 7. Final Project Requirements

To pass Maker100, a student must demonstrate:

1. **Input:** At least one sensor (Machine Learning or Standard).
2. **Logic:** Code that processes the input (e.g., "If FOMO detects a pen...").
3. **Output:** At least one actuator (Motor, Servo, OLED, or LED).
4. **Structure:** A 3D printed, wood, or cardboard housing.
5. **Documentation:** A short video explaining the build and a clean circuit diagram.

---

### Study Checklist

* [ ] Can you explain the difference between I2C and UART?
* [ ] Can you deploy a FOMO model to the XIAO using the Arduino IDE?
* [ ] Do you know why you shouldn't power a large DC motor directly from the XIAO 3.3V pin?
* [ ] Can you write a `loop()` that blinks an LED based on a sensor threshold?

