## Maker100-xiaoML-kit   (Economy) Robotics, IoT and TinyML Machine Learning course is almost ready to be used!

## 2026 Version


## [XIAOML-Kit youtube playlist](https://www.youtube.com/watch?v=EvNXQ0sk5Ec&list=PL57Dnr1H_egtkBZJku20Bo2zaR8KUJGpa&index=1&pp=gAQBiAQB)

## [2026 Price List](https://hpssjellis.github.io/maker100-xiaoML-kit/price-2026-00.html)

This course is all about the Seeedstudio  
$38.90 USD [The-XIAOML-Kit.html which has the $22 dollar kit with a $16.90  sdCard + Cables kit,  
<img width=400 src="https://github.com/user-attachments/assets/03d4d927-a35c-40cd-be88-ebe627d7b040">  
](https://www.seeedstudio.com/The-XIAOML-Kit.html)

For which the main Getting Started page is at [xiao_esp32s3_getting_started](https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/)  
Any specialty code for this specific ML kit will be here on this page or at the Harvard [mlsysbook.ai]([https://mlsysbook.ai/](https://mlsysbook.ai/contents/labs/seeed/xiao_esp32s3/xiao_esp32s3.html)) free online book labs section.

# General

The currciulum for this course is at [maker100-curriculum](https://github.com/hpssjellis/maker100-curriculum)

The old version of this course  Seeedstudio [maker100-eco](https://github.com/hpssjellis/maker100-eco)

An economical version of my successful Arduino PortentaH7 [Maker100](https://github.com/hpssjellis/maker100) Robotics, IoT and TinyML Machine Learning in-person course this time using less expensive hardware such as the [$13.99 USD Seeedstudio XiaoEsp32s3](https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/) for the course basics and some [EdgeImpulse.com](https://edgeimpulse.com/) cell phone assisted machine learning. 


Views better using the README.md [here](README.md)

This is not an online course, it is expected to be taught by a teacher or professor. Some students might be able to  do the course on their own, but many components of learning opportunities may be missed.

Price list for the equipment I will be using in 2026 [price-2026-00.html](price-2026-00.html) (Many other devices could be used but the videos then will not be accurate for those devices)



**Teacher Extras:** [See Appendix A - Why Not use the XIAO Expansion board and Round Display?](#appendix-a)

---

**Teacher Tips:** [See Appendix B - Teaching Guidelines and Best Practices](#appendix-b)

---

**Why Maker100-xiaoML-kit?** [See Appendix C](#appendix-c)

---

**How much cheaper is the XIAOML kit version?** [See Appendix D - Price Comparison](#appendix-d)

---


## Example Projects from the Portenta Course (for reference)

List here  for future planning. Notes: This is not the final list for this course and maybe removed






---


## Course Content Links


| Link and Video | About    |
|:---|:---|
| [a00](README.md#a00) Introduction Video |  Intro from Jeremy |
| [a01](README.md#a01) [Rocksetta Site](http://rocksetta.com) |  Early Web Computational Presentations by Jeremy <br> Good for ideas  |
| [a01](README.md#a01) [Rocksetta Site](http://rocksetta.com)  | [a02](README.md#a02) [The 2024 Course Site curriculum](https://github.com/hpssjellis/maker100-eco)   |
| [a03](README.md#a03) [Arduino IDE](https://www.arduino.cc/en/software) |  Download the Arduino IDE 1.8.19  or later for Windows, Mac or Linux |
| [a04](README.md#a04)  [Installing the XIAO Board Manager ]( https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/#software-setup)  | Arduino Board Manager, search esp32, install v2.0.7 or later    |
| [a05](README.md#a05) [Setup Arduino for the XIAO](https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/#software-setup)   |   At Arduino tools board manager select  "XIAO_ESP32S3"  |
| [a06](README.md#a06) [Install Edge Impulse CLI  ](https://docs.edgeimpulse.com/docs/tools/edge-impulse-cli/cli-installation)  | Optional: 3 ways to do TinyML with EdgeImpulse    |
| [a07](README.md#a07) [CLI-Daemon connection](https://docs.edgeimpulse.com/docs/tools/edge-impulse-cli/cli-daemon) |  Connect the XIAO to EdgeImpulse using the Edge Impulse CLI    |
| [a08](README.md#a08) [Examples on EdgeImpulse](https://edgeimpulse.com/account/projects/)   |  Public Projects   |
| [a09](README.md#a09)  Setting up [Wokwi.com](https://wokwi.com)   |   Create an account, search for the XIAO-ESP32s3 PSRAM. Run the Program   |
| [a10](README.md#a10) [General Help for Computer Science Students](https://github.com/hpssjellis/maker101)   |  Github site about main CS topics   |




---

## XIAO-esp32s3-sense  Assignments


| Assignment Topic | Example Code | Video | Instructions |
|:---|:---|:---|:---|
|  <a name="a11" href="README.md#a11">`a11-helloWorld-serial`</a>  Hello World in C++ |   [a11-helloWorld-serial.ino](xiao-code/a11-helloWorld-serial.ino)   |     |    Serial Monitor, PSRAM Hello World, blink.  |
|  <a name="a12" href="README.md#a12">`a12-input-BOOT`</a>  Digital Input on BOOT button    |  [a12-input-Boot.ino](xiao-code/a12-input-Boot.ino)    |     |    Load code, look for the white oval boot button, what does pressing it do. Make a small circuit diagram of what this button is connected to, Hint: D1, could D1 be used for something else?  |
|  <a name="a13" href="README.md#a13">`a13-output-LED`</a>  Digital Output (LED)   |   [a13-output-LED.ino](xiao-code/a13-output-LED.ino)   |     |   Load code, try to understand it and change a few things. FYI the color LED is no longer active (on some XIAO boards) and the red LED is at pin 21, that is also the same pin for the sdCard. Use another digital pin for a student supplied LED and resistor. |
|  <a name="a14" href="README.md#a14">`a14-analog-input`</a>  Analog Input (flex sensor)   |  [a14-analog-input.ino](xiao-code/a14-analog-input.ino)    |    |  Very important concept. Voltage divider curcuit using 10k potentiometer or equivalent sensor (such as a flex sensor). If you change the top 5V to a DAC output pin it could become a crude DC to DC converter. A voltage divider is a very important concept for analog sensors. There are lots of videos explaining this concept on youtube if you are having a hard time understanding it. You can use a search for "voltage divider and flex sensor" to see a visual of this circuit. Try varying the 10k resistor with all kinds of values 100 ohm, 1k, 10k, 20k, 200k etc. What happens to your readings?   |
|  <a name="a15" href="README.md#a15">`a15-analog-output-DAC`</a>  Analog Output (DAC Pin) |  [a15-analog-output-DAC.ino](xiao-code/a15-analog-output-DAC.ino)    |    |   Use a multimeter to read the analog values across the range you have written to the DAC. a DAC is slow but useful for many things including speaker or motor control.  I do not see a PWM pin showing on the pinout so we will just make one. Note: many of the xiao pins are PWM (8 bit) so other pins could also be used, especially the LED output pin D21  |
|  <a name="a16" href="README.md#a16">`a16-Transistor-DC-Motor`</a>  Transistor DC Motor  |  [a16-Transistor-DC-motor.ino](xiao-code/a16-Transistor-DC-motor.ino)   |    |  You do not have to use a transistor you could use a MOSFET, H-Bridge (L293D two dc motors or TB6612 faster 2 DC motor control), servo, continuous servo, steper motor. Try out [Wokwi](https://wokwi.com/projects/new/esp32-s3) to see if the diagram works, (Also note that on wokwi the bootS3 button, IO0, and GND pins are in the wrong location) Then actually make a diagram of your real circuit. |
|  <a name="a17" href="README.md#a17">`a17-Actuators`</a>  Actuators Lab (Flash, LED, Servo, MOSFET-DC-motor, H-Bridge-2-DC-motors, SoundSpeaker, SD-card-write)  |  |    |   You make this code. Try each item. Record what worked and what had issues  |
|  <a name="a18" href="README.md#a18">`a18-Sensors`</a>  Sensors Lab (Flex, Light, Button, Button-Pullup, Sound, Ultrasonic, Temperature, DHT22-Temp-Humidity, IMU-accel-gyro-mag, microSD-read, analog devices at home or school)   |    |    |   You make this code. Try each item. Record what worked and what had issues  |
|  <a name="a19" href="README.md#a19">`a19-dual-core-speed`</a> Dual Core Speed    |    [a19-dual-core-speed.ino](xiao-code/a19-dual-core-speed.ino)    |     |    Why use two cores and how do you activate them in code? Also explore ways to push the ESP32S3 fast.  |
|  <a name="a20" href="README.md#a20">`a20-i2c-OLED`</a>  I2C OLED   |  [a20-i2c-oled.ino](xiao-code/a20-i2c-oled.ino)     |     |  OLED screen, also add some of your sensors and actuators. I mainly added the oled screen because it is useful for troubleshooting LoRa or other IoT devices   |
|  <a name="a21" href="README.md#a21">`a21-serialPassthrough`</a>  Serial Passthrough  |    [a21-serialPassthrough.ino](xiao-code/a21-serialPassthrough.ino)    |     |    Serial passthrough code, works for any serial device! So useful.  |
|  <a name="a22" href="README.md#a22">`a22-SPI-SD-card`</a>  SPI  (SD Card for the XIAO Sense)  |  [a22-SPI-SD-card.ino](xiao-code/a22-SPI-SD-card.ino)   |     |  sd card programming using SPI. This device uses the SPI library to control an sd card.  |
|  <a name="a23" href="README.md#a23">`a23-PIR-interrupt`</a>  Interrupts (PIR sensor)  |   [a23-PIR-interrupt.ino](xiao-code/a23-PIR-interrupt.ino)     |     |  Sensors, actuators anything that uses interrupts, Note PIR has a 10-15 second warmup, and is not advised for speed checking   |
|  <a name="a24" href="README.md#a24">`a24-wifi-webserver`</a> WIFI Web Server  |  [a24-wifi-webserver.ino](xiao-code/a24-wifi-webserver.ino)    |     |   Web Server or Wifi, just understand it is possible. Note: Possibly the greatest control method when off the internet.  |
|  <a name="a25" href="README.md#a25">`a25-wifi-mqtt`</a>  WIFI MQTT   |   [a25-MQTT.ino](xiao-code/a25-MQTT.ino)   |     |  MQTT example   |
|  <a name="a26" href="README.md#a26">`a26-BLE-beacon-scanner`</a>  BLE Beacon Scanner   |  [a26-BLE-beacon-scanner.ino](xiao-code/a26-BLE-beacon-scanner.ino)   |    |  Bluetooth Devices   |
|  <a name="a27" href="README.md#a27">`a27-Bluetooth-app-serial`</a>  Bluetooth Serial   |   [a27-Bluetooth-app-serial.ino](xiao-code/a27-Bluetooth-app-serial.ino)    |     |  Bluetooth   |
|  <a name="a28" href="README.md#a28">`a28-Wifi-BLE`</a>  More Wifi and BLE    |      |     |    You make this code.  |
|  <a name="a29" href="README.md#a29">`a29-microphone`</a>  Microphone |  [a29-microphone.ino](xiao-code/a29-microphone.ino)     |     |  Make a cool sound sensor from the microphone (loud sound detector for robot, baby monitor,  etc. Can you control a servo using the microphone?  |
|  <a name="a30" href="README.md#a30">`a30-camera`</a>  Camera SD-card-save  |  [a30-camera.ino](xiao-code/a30-camera.ino)    |     |  Try to save a picture to the SD card   |
|  <a name="a31" href="README.md#a31">`a31-camera-read-serial`</a> Camera Serial read   |  [a31-camera-serial.ino](xiao-code/a31-camera-serial.ino)    |     |   Read an image from the SD card  |
|  <a name="a32" href="README.md#a32">`a32-6dof-IMU`</a> 6 DOF IMU  |  [a32-6dof-IMU.ino](xiao-code/a32-6dof-IMU.ino)    |     |  Accelerometer and Gyroscope    |
|  <a name="a33" href="README.md#a33">`a33-6dof-tap`</a>  6 DOF Tap Detection   |  [a33-6dof-tap.ino](xiao-code/a33-6dof-tap.ino)   |      |   Detect a single or double tap  |
|  <a name="a34" href="README.md#a34">`a34-6dof-interrupt`</a>  6 DOF Interrupt  |   [a34-6dof-interrupt.ino](xiao-code/a34-6dof-interrupt.ino)     |     |   Check interrupts with IMU  |
|  <a name="a35" href="README.md#a35">`a35-all-in-one-tester`</a>  All-in-one-tester    | [a35-all-in-one-tester.ino](xiao-code/a35-all-in-one-tester.ino)      |     |  You make this code Try: PSRAM, Heap Stacks 1 and 2, flash, led, BOOT button, mic, camera, sd, oled, temp, gyro   |
|  <a name="a36" href="README.md#a36">`a36-vision-accel-fusion`</a>  Vision Accel Fusion   |   [a36-vision-accel-fusion.ino](xiao-code/a36-vision-accel-fusion.ino)    |     |  You make this code. Run camera and accelerometer at the same time. add in anything else you want  |
|  <a name="a37" href="README.md#a37">`a37-github`</a>  Start Github   |      |     |   Make a new repository on github  |
|  <a name="a38" href="README.md#a38">`a38-github-pages`</a> Github Pages   |      |     |  Activate Github Pages   |
|  <a name="a39" href="README.md#a39">`a39-nothing`</a>  []()   |      |     |    |
|  <a name="a40" href="README.md#a40">`a40-nothing`</a>  []()   |      |     |    |




---


## EdgeImpulse.com tinyML vision-sound-motion Assignments

| Assignment Topic | Example Code | Video | Instructions |
|:---|:---|:---|:---|
|  <a name="a41" href="README.md#a41">`a41-ei-sound`</a>  EdgeImpulse Sound Test (may save as tflite and reload onboard XIAO)  |  Look at the other EdgeImpulse examples to understand this one     |     |  3 ways to do EdgeImpulse tinyML: full upload, test only upload, and tflite to XIAO. In all 3 versions you start by making a free account at EdgeImpulse, then make a new project and give it a unique name. Then for the full upload method the easiest is to install the CLI and run edge-impulse-daemon and follow the prompts. This method is full integration and if it works very well. It often has issues. The test only version only works on certain devices and you use the serial monitor to connect to edgeimpulse and run the machine learning on edgeimpulse so it is very very slow, probably about once per second. The 3rd method is to upload many samples manually and then generate a tflite file and load it to the xiao and run it there. This is likely the best method as no machine learning provider is needed to run new data. First try all 3 ways using sound, Note: the microphone works much better with the latest version of the Arduino Esp board manager. That version has a working PDM (Pulse Density Modulation) microphone code. Try "yes" and "no", perhaps "go" and "stop". Try words you say yourself. The easiest letters to recognize are "a", "e" and "o". See if you can make a model for 3 words and run it on the device (XIAO). Note: I use the pre-made github sketch at https://github.com/edgeimpulse/firmware-seeed-xiao-esp32s3-sense that was pre-made to run edgeImpulse for this  type of board. Make sure on  edgeimpulse "edit impulse" you choose at least MFE features and the tinyML transfer model NN Classifier for sound. The harder 3rd method might need these libraries: EloquentTinyMl, tflite-micro-esp-examples, tensorflow-lite,   |
|  <a name="a42" href="README.md#a42">`a42-ei-vision`</a>  EdgeImpulse Vision Test (full upload to run on XIAO device)   |  Look at other tinyML vision models to start    |     |   You will need the firmware for the XIAO from: [firmware-seeed-xiao-esp32s3-sense github repo](https://github.com/edgeimpulse/firmware-seeed-xiao-esp32s3-sense) as an entire project at https://github.com/edgeimpulse/firmware-seeed-xiao-esp32s3-sense upload it to the xiao connect to edgeimpulse using the terminal in linux, mac or even windows with cygwin64 terminal. If you can see the camera window then it is all working. Do about 30 pictures  (typically I do 60 per class) for each of the 2 or three classes you want. Try edgeimpulse transfer learning MobileNetV1 or MobileNetV2 (other pretrained image models are also being made available) and about 60 cycles. Download as Arudino Library and unzip to your arduino/libraries folder. Then follow the examples for the static buffer, be careful with the resolution either 96x96 or 160x120. Possibly use the serial monitor "3" input to take pictures on the device instead of using edgeimpulse. See if you can get it running a tinyML classification on the XIAO    |
|  <a name="a43" href="README.md#a43">`a43-ei-accel`</a>  EdgeImpulse Acceleration (full upload to run on XIAO device)  |  Look at the other examples for help    |     |   Either Test the built in motion or make your own model with movements: hit, rotate, tap, etc and get it running on the XIAO  |
|  <a name="a44" href="README.md#a44">`a44-ei-test-fusion`</a>  EdgeImpulse Test Sensor Fusion (just test no model on XIAO)  |      |     |  You can easily test a few sensors working with edgeimpulse and the tester method. Make a project and try to classify sound and motion at the same time or camera and motion.   |
|  <a name="a45" href="README.md#a45">`a45-ei-full-fusion`</a>  EdgeImpulse Sensor Fusion (full upload to run on XIAO device)  |  [FOMO-accel](https://github.com/edgeimpulse/example-custom-ml-block-fomo-accel/tree/main)    |     |   Sensor fusion is very difficult. edgeimpulse either needs a new model (like FOMO or yolov7 (they work well but are for special cases)) or you have to generate two tflite models and load them at different times to run or join the models using the EON Tuner. (see the ML expert assignments). Much of this content is over most students heads. I still find it confusing. Some progress is being made by edgeimpulse on sensor fusion and the model types to use. I will update this assignment when those can easily be done. The link for a44 shows one way to do sensor fusion. |
|  <a name="a46" href="README.md#a46">`a46-nothing`</a>  []()   |      |     |    |
|  <a name="a47" href="README.md#a47">`a47-nothing`</a>  []()   |      |     |    |
|  <a name="a48" href="README.md#a48">`a48-nothing`</a>  []()   |      |     |    |
|  <a name="a49" href="README.md#a49">`a49-nothing`</a>  []()   |      |     |    |
|  <a name="a50" href="README.md#a50">`a50-nothing`</a>  []()   |      |     |    |



---

## Rak2270 sticker Tracker  IoT LoRaWan Assignments   (advanced but available)


| Assignment Topic | Example Code | Video | Instructions |
|:---|:---|:---|:---|
|   <a name="a60" href="README.md#a60">`a60-rak-temperature-humidity`</a>  Run Temperature and Humidity  | [RAK-DHT-temp-humid.ino](rak-sketches/RAK-DHT-temp-humid.ino)    |  [<img src="https://img.youtube.com/vi/8RD5a0SQK74/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=8RD5a0SQK74&list=PL57Dnr1H_egsfctG_K8AQ9uGhaLsTth6x&index=1&pp=iAQB)     | This code checks the DHT sensor on the RAK2270 board and works out the box. Note some of the sensors might be stuck together for shipping. Carefully separate them. Run this code. Some students will want to add to this code and change a few things to make it their own.  |
|  <a name="a61" href="README.md#a61">`a61-rak-temp-battery`</a>  Run NTC Temperature and Battery Voltage   |  [RAK-NTC-temp.ino](rak-sketches/RAK-NTC-temp.ino)   |   [<img src="https://img.youtube.com/vi/1eSEkwWMcjE/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=1eSEkwWMcjE&list=PL57Dnr1H_egsfctG_K8AQ9uGhaLsTth6x&index=2&pp=iAQB)     |  Code prints out the battery voltage and board temperature. This gives us a chance to test other battery sources. Reminder anything over 5V may damage this board and even 5V might not work well. Research max and minimum acceptable votages.   |
|   <a name="a62" href="README.md#a62">`a62-rak-LoRaWan-test`</a>  LoRaWan Test   |   [lorawan-test-08-byte-xyz-mapped.ino](rak-sketches/lorawan-test-08-byte-xyz-mapped.ino) with this js decoder file for datacake configuration [cayenneLPP.js](rak-sketches/cayenneLPP.js)   |   <img src="https://github.com/hpssjellis/maker100-eco/assets/5605614/d4bc64f0-9286-4989-a951-14f3b3f97f88" width = "400px" />    |  Get a test login to the console for either [meteoscientific.com](https://console.meteoscientific.com/front/)  or [helium-iot.eu](https://console.helium-iot.xyz/front/) and 1. set a device-profile for US915 and a codeC "cayenneLPP". then an application and on integration switch to datacake Devices, LoRaWan "show setup instructions" switch back and paste that HTTP URL. The back to applications and make a device with DevEUI, AppEUI (called Join eui) and then APpKey. Power up the RAK2270 and monitor debug windows etc. Back on Datacake go to configurations and decoder and past the cayenneLPP.js decoder and try some raw data. if that works then click the fileds and see if you can auto add them. then make a dashboard on datacake with the new fields.   Note: I think the acceleration actual data has issues see if someone can fix it.  |
|   <a name="a63" href="README.md#a63">`a63-rak-motion`</a>  Run xyz acceleration   | [rak-accel-imu.ino](rak-sketches/rak-accel-imu.ino)     |    [<img src="https://img.youtube.com/vi/hr-YT-qImJ4/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=hr-YT-qImJ4&list=PL57Dnr1H_egsfctG_K8AQ9uGhaLsTth6x&index=3&pp=iAQB)   | Fairly easy acceleration x, y, z example. Only problem here is the Rak clip does not work well with motion. the teacher should have a few boards with soldered wires that can be used well with motion.   |
|   <a name="a64" href="README.md#a64">`a64-rak-fusion`</a>  Sensor Fusion   |      |     |You make this file. you have the code above. Run code with all the Sensors on the RAK2270: temperature, Humidity, 3 axis IMU: motion (xyz)  |
|   <a name="a65" href="README.md#a65">`a65rak-raw`</a> LoRaWan-raw-number   |    [lorawan-test-send-2-bytes.ino](rak-sketches/lorawan-test-send-2-bytes.ino)   with a simple js decoder [2-bytes.js](rak-sketches/2-bytes.js)       |                    |  Theoretically this should be easier than the cayenneLPP setup, but we need simple code and a javascript decoder. See what you can do.  |
|   <a name="a66" href="#a66">`a66-rak-stLink`</a>  STM32CubeProgrammer with STLINK V2 |   Try this blank sketch compiled binary file which allows theAT commands only <br> [rak-only-at-commands.hex](rak-sketches/rak-only-at-commands.hex)   |   [<img src="https://img.youtube.com/vi/fUlx79bOjNs/hqdefault.jpg" width=600 />](https://www.youtube.com/watch?v=fUlx79bOjNs&list=PL57Dnr1H_egsfctG_K8AQ9uGhaLsTth6x&index=8&pp=iAQB)     |  Use the rak clip to access a few of the pins on the RAK2270 to see if you can program thme  |
|   <a name="a67" href="README.md#a67">`a67-rak-pins`</a>  Easy and Hard pins test   |      |     |Use the RAKClip or Solder wires to the pads on the rak2270 and do some pin testing like you would for an Arduino   |
|   <a name="a68" href="README.md#a68">`a68-rak-nothing`</a>  []()   |      |     |    |




## Final Course Projects (Student must complete an individual final project to pass my in-person course, your teacher might have different ideas)

| Topic | Example Code| Video | Instructions |
|:---|:---|:---|:---|
| <a name="FP1" href="README.md#FP1">`FP1`</a>  One sensor with one actuator final project  |      |     |   [See Appendix E - More Instructions](#appendix-e)  |
| <a name="FP2" href="README.md#FP2">`FP2`</a>  complex sensor, ML, actuator final project  |      |     |   [See Appendix F - More Instructions](#appendix-f)  |
| <a name="FP3" href="README.md#FP3">`FP3`</a>  group final project, proof of concept for a viable product  |      |     |   [See Appendix G - More Instructions](#appendix-g)  |


## Unsorted Rak2270 Videos


   
## View the old [maker100](https://github.com/hpssjellis/maker100#latest-portenta-pinout) course for the Portenta Pinout Diagram

## XIAO esp32s3-sense  Pinout Diagram



 <img src="https://github.com/hpssjellis/maker100-eco-change/assets/5605614/c818e03f-562f-40df-8726-f0e5d5903596" width = "100%" /> 



## RAK2270 Sticker Tracker Pinout Diagram



 <img src="https://github.com/hpssjellis/maker100-eco/assets/5605614/a285279d-19f9-47ff-9b64-00c4b8f26087" width = "100%" /> 

 


 .



 .




 .





 .






 # Tutorials If Needed

 <a href="ml16">ml16</a>
 Arduino IDE, load board xiao esp32s3, PSRAM -OPI-PSRAM, plugin XIAO ml Kit to USBA Tools Port, upload , reset board, type T or L in serial monitor.  
 For PlatformIO, install VS Code, PlatformIO extension, new progect, board XIAO ESP32S3, load code into main.cpp, fix platformio.ini file, upload, serial monitor, T (tap) or L (longpress). Code to load on platformio and the arduino IDE:  [https://github.com/hpssjellis/my-examples-of-tensorflowjs-for-tinytorch/blob/main/esp-on-device-train-one-program/esp-all-menu-A0-image-train-infer.txt](https://github.com/hpssjellis/my-examples-of-tensorflowjs-for-tinytorch/blob/main/esp-on-device-train-one-program/esp-all-menu-A0-image-train-infer.txt)



 
 
 # Prompt Help me load this code https://github.com/hpssjellis/my-examples-of-tensorflowjs-for-tinytorch/blob/main/esp-on-device-train-one-program/esp-all-menu-A0-image-train-infer.txt onto both the arduino IDE and Platformio to be able to compare them 





 
#### Jeremy Ellis, ex: Rocksetta now <a href="https://ca.linkedin.com/in/jeremy-ellis-4237a9bb">LinkedIn</a>
#### High School Coding (35 Years), Robotics, Web Design, Animation and 3D Printing Teacher, BC Canada
#### Use this in-person course at your own risk!




---

---

# Appendices

## Appendix A: Why Not use the XIAO Expansion board and Round Display?

The Seeedstudio [$16.40 USD Expansion board](https://wiki.seeedstudio.com/Seeeduino-XIAO-Expansion-Board/) and [$18.00 USD Round Display](https://wiki.seeedstudio.com/get_start_round_display/) are amazing inexpensive addons to the XIAO-ESP32s3-sense and are very well explained on the Getting started sites listed above.

I have both for my classrooms and may use them as the year goes on, but I have testing to do to find out if the color round display is as fast as my grayscale OLED and I do not like students using I2C and SPI connectors that come with the expansion board because the students naturally begin to feel that they can only use sensors and actuators that come with the correct connectors.

The students for their final projects stay away from new or unusual sensors/actuators because those sensors do not come with the correct connectors. A possible solution is to have the [grove-4-pin-female-jumper-wire](https://ca.robotshop.com/products/grove-4-pin-female-jumper-wire) I would prefer the male pins but it is electrically safer to have the female pins. It also does not help that so many boards use different connectors. I have lots of sensors with connectors that don't work with the grove systems. If you are just starting a course and know that you are going to stick with the [Grove sensor actuator system](https://wiki.seeedstudio.com/Grove_System/) and have a few extra connectors on bare wires ordered for new devices then the expansion board might be a great way to teach.

If you choose to use the expansion board this ebook [here](https://mjrovai.github.io/XIAO_Big_Power_Small_Board-ebook/) covers working with it very well.

---

## Appendix B: Teaching Guidelines and Best Practices

1. Students work on term assignments in partners and make very short videos that teach what they did for each assignment.
2. I expect all students to try to improve and change each assignment. "Until you change computer code do not expect to understand it"
3. MAKE EACH STUDENT DRAW THEIR OWN CIRCUIT DIAGRAM FOR EACH ASSIGNMENT. For easy assignments I make it hard for the students to know how to connect the wires. I only give students clear diagrams for the difficult connections. Let students think. These are not fully made recipes!
4. For 2026 I will be using wokwi for diagrams. Students can look at the diagram but must still make their own drawing that they understand. (All connections labelled and perhaps include wire color)
5. I expect all students to draw circuit diagrams before connecting wires and have someone check the diagram and then to connect the wires and have someone also check before students connect power to the device.
6. I teach one assignment per class but expect several students to work ahead and solve missing parts of the process in small groups, also some students will fall behind, this allows us to have fewer sensors and actuators since the class rarely uses them at the same time. I can often get away with 4 sensors for an entire 30 person class
7. All assignments should be complete individually so that each student does the entire pipeline, students may work in partners but take turns at the computer
8. Students should wipe the code after they have made their video so that the next student needs to program it from scratch
9. This Github of very fast instructions allow more dedicated students to work ahead and helps student who missed a class or are good reminders for students who need extra time. THE VIDEOS ARE NOT EXPECTED TO BE AN ONLINE COURSE. THIS IS AN IN-PERSON COURSE! Educators can add important information and problem solve many issues that are very difficult to solve when at home by yourself in a fast paced changing technological landscape.
10. The faster students finish the course the more time they have for their final projects
11. To pass the course everyone must complete at least one final project using a sensor connected to an actuator of their choice
12. Students plan 2 individual main projects and possibly one group project. Each main project must include at least one sensor with one actuator
13. Many student's will only complete one main project and that is fine. "Robotics projects are very difficult to finish"
14. Many final projects will need structures built to support them. Any safe material is fine, we typically 3D print the structures although cardboard and or wood is often used
15. Final projects typically do not involve high voltage, water or drones for the obvious safety reasons.
16. I tell students that if every term assignment is complete, the individual final project is their full mark if that helps their grade
17. Teacher's may decide to make several of the advanced assignments optional or even set for bonus marks
18. Use an LLM such as: (What I do with the free versions) [Claude.io](https://claude.ai/new) for all help, [Gemini](https://gemini.google.com/app) for all research, [chatGPT](https://chatgpt.com/) for advanced critique, [CoPilot](https://www.copilot.com/) for creative solutions to help understand what the code does or how to improve the assignment

---

## Appendix C: Why Maker100-xiaoML-kit?

The arduino PortentaH7 with LoRa Vision Shield is an incredible TinyML device that can do amazing things and has been a joy to teach, but I am part of an international group trying to bring tinyML to the students in developing countries called [tinyML4D](https://tinyml.seas.harvard.edu/team) and the Arduino PortentaH7 is just too expensive for student explorations. Also when you fry one of these boards it is very upsetting.

---

## Appendix D: Price Comparison

The [Arduino PortentaH7](https://store-usa.arduino.cc/products/portenta-h7) costs $113.90 USD the [LoRa Vision Shield](https://store-usa.arduino.cc/products/arduino-portenta-vision-shield-lora%C2%AE) Costs $69 USD


The [XiaoEsp32s3-sense](https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html) costs $13.99

The [https://www.seeedstudio.com/The-XIAOML-Kit.html](https://www.seeedstudio.com/The-XIAOML-Kit.html) is $22 USD without cables, and micro sd card

The [https://www.seeedstudio.com/The-XIAOML-Kit.html](https://www.seeedstudio.com/The-XIAOML-Kit.html) is $38.90 with everything 
(Esp32S3 Sense with camera microphone SD Card module and IMU OLED module and cables, sd Card reader and micro sd card. You can start learning immediately)

---

## Appendix E: Final Project 1 - More Instructions

*[The content from the original details tag for FP1 would go here - it appears to be placeholder content that says "..." in the original]*

**ChatGPT Prompt:** *[The content from the original ChatGPT Prompt details tag would go here]*

---

## Appendix F: Final Project 2 - More Instructions

*[The content from the original details tag for FP2 would go here - it appears to be placeholder content that says "..." in the original]*

**ChatGPT Prompt:** *[The content from the original ChatGPT Prompt details tag would go here]*

---

## Appendix G: Final Project 3 - More Instructions

*[The content from the original details tag for FP3 would go here - it appears to be placeholder content that says "..." in the original]*

**ChatGPT Prompt:** *[The content from the original ChatGPT Prompt details tag would go here]*

---
