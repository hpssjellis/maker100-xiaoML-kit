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



**Teacher Extras:** [See Appendix A](#appendix-a)

---

**Teacher Tips:** [See Appendix B](#appendix-b)

---

**Why Maker100-xiaoML-kit?** [See Appendix C](#appendix-c)

---

**How much cheaper is the XIAOML kit version?** [See Appendix D](#appendix-d)

---

**Useful Links:** [See Appendix E](#appendix-e)

---




## Example Projects from the Portenta Course (for reference)

List here  for future planning. Notes: This is not the final list for this course and maybe removed






---


---

## Seeedstudio XIAO-ML Kit (Xiao-Esp32s3 with IMU and OLED module) Currciulum



For Arduino IDE Boards for both the Xioa-Esp32s3 and XIAO ML Kit Search for ESP32 and install the board, then look for XIAO ESP32S3 specific board
Note: No Preferences needed the Espressif board is properly listed. Do not install the Arduino ESP32 board just the official Espressif board.


Video showing how to setup the XiaoEsp32s3. There are also lots of other instructions online to help with setup.

<img src="https://img.youtube.com/vi/u-H3OpFcPss/hqdefault.jpg" width=600 />



------------------------------------------------------------------------------------------------------------

# Assignments done in order of our class in 2026, not the curriculum order.

-------------------------------------------------------------------------------------------------------------









Note: soldered headers not needed, but a USB-C cable and computer or laptop to run the code is needed
| Topic | Example Code| Video | Instructions and Prompt|
|:---|:---|:---|:---|
| <a name="a01-ml16" href="README.md#a01-ml16">`a01-ml16-on-device-machine-learning`</a>  Platformio and Arduino IDE on-devise-ml with u8g2 oled include library  | Great hard first day: [esp-all-menu-A0-image-train-infer.txt](https://github.com/hpssjellis/my-examples-of-tensorflowjs-for-tinytorch/blob/main/esp-on-device-train-one-program/esp-all-menu-A0-image-train-infer.txt), or try the easier first day which is the same as assignment a03-base06 but on both platformIO and the Arduino IDE  [seeed-blink-serial.ino](seeed-sketches/seeed-blink-serial.ino) | This assignment covers the [Maker100-Curriculum Basics](https://github.com/hpssjellis/maker100-curriculum#basics) Base01-base05, base07 Assignments   |   See [Tutorial ml16](#tutorial-ml16)  |
| <a name="a02-ml01" href="README.md#a02-ml01">`a02-ml01 Seeed ML SenseCraft`</a>  Follow the Sensecraft Vision example  |  [wiki.seeedstudio.com/sscma/](https://wiki.seeedstudio.com/sscma/) direct webpage [https://sensecraft.seeed.cc/ai/#/home](https://sensecraft.seeed.cc/ai/#/home)  | This assignment covers the start of the [Maker100-curriculum Machine Learning](https://github.com/hpssjellis/maker100-curriculum#machine-learning)  |      |
|   <a name="a03-base06" href="README.md#a03-base06">`a03-base06-blink-serial-print`</a>  Xiao Esp32s3 LED Blink and Serial Print  | [seeed-blink-serial.ino](seeed-sketches/seeed-blink-serial.ino) | ![blink-serial3](https://github.com/user-attachments/assets/eae5ad75-3f34-40c6-8f20-8f4a9b95b8fb) <br> [wokwi Serial](https://wokwi.com/projects/454549337599230977) <br>  <img src="https://img.youtube.com/vi/0OLsLl-CBHQ/hqdefault.jpg" width=100 />    <img src="https://img.youtube.com/vi/3E5KUT115xY/hqdefault.jpg" width=600 />         |         Print other things and change the pattern of blinking delay times. This is the code you should always leave on the XIAO ML Kit so that you know it works when you first get it.  |
| <a name="a04-ml02" href="README.md#a04-ml02">`a04-ml02 EdgeImpulse Vision Model`</a>  Follow the EdgeImpulse Vision Classification Machine Learning model   | You make the code and download it as an Arduino Library from Edge Impulse |  [https://edgeimpulse.com/](https://edgeimpulse.com/)     This is a full playlist so many other videos here might help  <img src="https://img.youtube.com/vi/wbX_-No8kIw/hqdefault.jpg" width=600 />              |      This website is a good starting point [https://hpssjellis.github.io/multi-language-edgeimpulse-tutorial-vision-cell-phone/](https://hpssjellis.github.io/multi-language-edgeimpulse-tutorial-vision-cell-phone/). For this assignment we are not using the microcontroller.    [See Appendix F - EdgeImpulse Instructions and Prompt](#appendix-f) |
|   <a name="a04-base08" href="README.md#a04-base08">`a04-base08-serial-putty`</a> Serial-putty or Linux "screen"         | This is a program to load on your computer that replaces the arduino serial monitor           |      |      Fairly easy once putty is installed. Load power shell and type mode with your Portenta programmed with a serial monitor program find the port. Then switch to Serial on Putty and Correct the COM port. Open and see if you can see serial output from the Esp32s3        |
|   <a name="a05-code10" href="README.md#a05-code10">`a05-code10-SOS`</a>  Flash SOS                           |     [dot71-sos](https://github.com/hpssjellis/portenta-pro-community-solutions/blob/main/examples/dot7-coding-curriculum/dot71-sos/dot71-sos.ino)                                                                                                                                                                         |   <img src="https://img.youtube.com/vi/lvEuArebVuA/hqdefault.jpg" width=600 />      <img src="https://img.youtube.com/vi/iDC3vuBGGcg/hqdefault.jpg" width=600 />          | This is your first Code example from the [Maker100-Curriculum on Coding](https://github.com/hpssjellis/maker100-curriculum#coding)                   Get the code running to flash the LED_BUILTIN, then have it flash an SOS. 3 short flashes, 3 long flashes, 3 short flashes then a 5 second rest.     |
|  <a name="a06-sense04" href="README.md#a06-sense04">`a06-Sense04-button`</a>.  Button causes LED to blink          |       [seeed-led-button.ino](seeed-sketches/seeed-led-button.ino) | This is your first [maker100-curriculum sensor](https://github.com/hpssjellis/maker100-curriculum#sensors) assignment  <img src="https://img.youtube.com/vi/SkTqOthK3JM/hqdefault.jpg" width=600 />     <img src="https://img.youtube.com/vi/wFw-AF8gwiY/hqdefault.jpg" width=600 />           |                   <img src="media/b-b-h-button-control-led.jpg" width = 200/>  <br>        Control the LED with the button, then control multiple LED's with Multiple Buttons. Note: Can't control large current flow devices, WHY? Could you make the external LED interact like the internal LED?  Did you realise that this is actaully a sensor and actuator assignment?  |
|  <a name="a07-act01" href="README.md#a07-act01">`a07-act01-servo`</a> Servo                           |      [seeed-servo-needs-ESP32Servo-include.ino](seeed-sketches/seeed-servo-needs-ESP32Servo-include.ino)       | This is your first [Maker100-Curiculum Actuator] Assignment.  <img src="https://img.youtube.com/vi/c3j7Vi28n24/hqdefault.jpg" width=600 />      <img src="https://img.youtube.com/vi/4p3yIF_4pk8/hqdefault.jpg" width=600 />          |                 MUST HAVE AN EXTERNAL BATTERY TO RUN THE 6 VOLT SERVO! Need the negative GND from the external battery to run to both the XIAO and the servo. Also you need to find the library and include it  ```#include <ESP32Servo.h>```  I have the Pololu Servo Product number 1057, Power HD High-Torque Servo 1501MG [here](https://www.pololu.com/product/1057).  <br> To connect XIAO D5 (orange wire) GND (brown wire) to the servo, <br> 6 volt battery positive (red) and Negative (brown) to servo.   |
|  <a name="a08-webAI06" href="README.md#a08-webAI06">`a08-webAI06-Hand Pose`</a> HandPose            |   Make a video of this webpage working [handpose](https://hpssjellis.github.io/beginner-tensorflowjs-examples-in-javascript/tfjs-models/handpose/index.html)           | This is your first [Maker100- Curriculum-WebAI](https://github.com/hpssjellis/maker100-curriculum?tab=readme-ov-file#webai-edgeai) assignment working presently only on your cell phone or desktop/laptop computer, eventually TinyML will be powerrful enough to run this code. Note: Several Raspberry Pis and the Arduino UnoQ can already run this code out of a web browser on the Linux tiny device.   |       |
|  <a name="a09-iot02" href="README.md#a09-iot02">`a09-iot02-Camera-web-server`</a> Camera web server            |   Make a video of the default ESP32S3 Camera sgreaming webserver. You can use the class hotspot or your own cell phone hotspot and enter the SSID and password. Ask the teacher to put those on the board.           | This is your first [Maker100- Curriculum-IOT]() assignment which has some kind of communication between devices.   |       |




.




.






.




.






.






.




.




# The following will eventually be in the above table when the assignments are completed


# One Day Conference using the XiaoEsp32s3-sense
Note: soldered headers are not needed, but a cell phone or webCam laptop is needed, along with a usb-C to USB-A cable
Students are encouraged to work ahead.

| Topic | Example Code| Video | Instructions and Prompt |
|:---|:---|:---|:---|
|  <a name="a02" href="README.md#a02">`a02-cell-classify`</a>   Make a vision classification machine learning model using your cell phone    |     [edgeimpulse.com](https://studio.edgeimpulse.com/login)              |  <img src="https://img.youtube.com/vi/7Aucyd10Mtw/hqdefault.jpg" width=600 />       This is a full playlist so many other videos here might help  <img src="https://img.youtube.com/vi/wbX_-No8kIw/hqdefault.jpg" width=600 />              |      This website is a good starting point [https://hpssjellis.github.io/multi-language-edgeimpulse-tutorial-vision-cell-phone/](https://hpssjellis.github.io/multi-language-edgeimpulse-tutorial-vision-cell-phone/). For this assignment we are not using the microcontroller.    [See Appendix F](#appendix-f) |
|   <a name="a03" href="README.md#a03">`a03-blink-serial-print`</a>  Xiao Esp32s3 LED Blink and Serial Print  | [seeed-blink-serial.ino](seeed-sketches/seeed-blink-serial.ino) |     <img src="https://img.youtube.com/vi/0OLsLl-CBHQ/hqdefault.jpg" width=600 />    <img src="https://img.youtube.com/vi/3E5KUT115xY/hqdefault.jpg" width=600 />         |                     Print other things and change the pattern of blinking delay times  |
|  <a name="a04" href="README.md#a04">`a04-xiao-classify`</a> BONUS. PRESENTLY NOT WORKING! Put the above classify Vision model on the XiaoEsp32s3 Using the Arduino IDE  | Needs board version 2.0.15   [seeed-edgeimpulse-vision-fomo.ino](./seeed-sketches/seeed-edgeimpulse-vision-fomo.ino)  Advanced fix the code for the latest board >= 3.2.0  |      <img src="https://img.youtube.com/vi/i2xg_wxBGdc/hqdefault.jpg" width=600 />    |  Set Arduino Tools-->PSRAM-->OPI PSRAM and presently for Vision must use the OLD Arduino IDE  ~1.8.19 Note: on edge impulse turn off the EON compiler before exporting the library.   |
|   <a name="a05" href="README.md#a05">`a05-sensecraft`</a>  Put the above Vision model on the XiaoEsp32s3 Using SenseCraft  |  Note updated link Feb 28, 2025  direct webpage [https://sensecraft.seeed.cc/ai/#/home](https://sensecraft.seeed.cc/ai/#/home)    |   | On edgeimpulse dashboard export your model using Int8 quantized and upload using Sensecraft    |
|   <a name="a06" href="README.md#a06">`a06-cell-FOMO`</a>  Using your cell phone to make a FOMO model   |      |     | No unknown and must choose bounding boxes. Still use grayscale and 96x96 resolution   |
|  <a name="a07" href="README.md#a07">`a07-XIAO-FOMO`</a>  Put the FOMO model onto the XiaoEsp32s3  | Needs board version 2.0.17 WORKS ON BOTH NEW AND OLD ARDUINO IDE  [seeed-edgeimpulse-vision-fomo.ino](./seeed-sketches/seeed-edgeimpulse-vision-fomo.ino)  Advanced fix the code for the latest board >= 3.2.0   |  Unlike Classify, FOMO works on the new Arduino IDE, same code as for vision.   <img src="https://img.youtube.com/vi/i2xg_wxBGdc/hqdefault.jpg" width=600 />    | Must download the deployment Arduino library from EdgeImpulse and see the example to get the include filename. then copy that include file name to the code to the left.  |







# Second Day Conference using the XiaoEsp32s3-sense
Note: soldered headers not needed, but a cell phone or webCam laptop is needed, along with a USB-C to USB-A cable and a micro sd-card
Students are encouraged to work ahead.

| Topic | Example Code| Video | Instructions and Prompt |
|:---|:---|:---|:---|
|   <a name="a08" href="README.md#a08">`a08-cell-wake-word`</a>  Use your cell phone to make a Yes, No, unknown Sound Model   |      |     |   Follow the wizard on Edgeimpulse to make a verbal Machine Learning model using your cell phone. Then download the Arduino deployment, install the zipped Arduino library and choose the default Portenta Sound example. Then talk into your Portenta and view the Serial Monitor. Then get the onboard LED to respond to your voice.            |
|   <a name="a09" href="README.md#a09">`a09-xiao-wake-word`</a>  Put the sound (wake word) model onto your XiaoEsp32s   | As far as I can tell student Riley fixed this one as well. Can someone check it?  [seeed-edgeimpulse-sound.ino](./seeed-sketches/seeed-edgeimpulse-sound.ino)   |     | Make the normal edgeimpulse.com sound model. then deplyment -->Arduino and add the zipped library to the arduino IDER. Then view the example to get the proper include filename and use that include file name with the code provided.    |
|  <a name="a10" href="README.md#a10">`a10-cli`</a>  (optional) Try the Edgeimpulse connection method  |   [edgeimpulse.com](https://studio.edgeimpulse.com/login)      |     |    |
|   <a name="a11" href="README.md#a11">`a11-nothing`</a> Nothing Yet           | |     | |
|   <a name="a12" href="README.md#a12">`a12-nothing`</a> Nothing Yet           | |     | |
|  <a name="a13" href="README.md#a13">`a13-nothing`</a> XiaoEsp32s3 camera to micro sd-card to FOMO model to XiaoEsp32s3   |  [seeed-cam-to-sd-card.ino](seeed-sketches/seeed-cam-to-sd-card.ino)  then [seeed-edgeimpulse-vision-fomo.ino](./seeed-sketches/seeed-edgeimpulse-vision-fomo.ino)   |     | Must download the deployment Arduino library from EdgeImpulse and see the example to get the include filename. Then copy that include file name to the code to the left. [See Appendix G - Camera SD Card Instructions](#appendix-g)  |
|   <a name="a14" href="README.md#a14">`a14-cell-motion`</a>  EdgeImpulse cell phone motion x,y,z model   |      |     | Do this for later in the course when we use the RAK2270StickerTracker to get an idea of what we are doing. If you have a motion sensor for the XiaoEsp32s3-sense then you could upload this model to it but that is optional  |
|   <a name="a15" href="README.md#a15">`a15-vision-regression`</a>  Vision regression Analysis  |   Have it work on your cell phone only. Regression means every label is an integer.   |   | Same as Vision Classification except no unknown and each label is an integer value. At the ```Add a Learning block``` add the normal "Transfer Learning" but also add Regression. For regression you train each label as an integer value reflecting some size amounts. We will do the distance to a computer mouse from above. Try to train 1m, 2m and 3m. Then on classification the model should estimate the distance.  |
|   <a name="a16" href="README.md#a16">`a16-anamoly`</a> Vision Anomaly Detection |  Have it work on your cell phone only. Anamoly simply means it is a measure of how different it is than the changing set.    |     | This time you visually train on what you expect. You can do 0unknown and 1pen like the first vision classification example. Anomoly rates how different the result is from the training as a digital percent.  At the ```Add a Learning block``` add the normal "Transfer Learning" but also click "Show all blocks" and find ```Anomoly```.  Then on classification the model should detect the pen and rate it's anomoly.    |


 
using one RAK2270 as the P2P receiver






# One Day Conference using the RAK2270StickerTracker
Note: Each person or group will need the [RAK2270 Sticker Tracker Developer kit](https://store.rakwireless.com/products/rak2270-rak-sticker-tracker?variant=43046273220806) with serail rig called the clip

Needs testing, might need a Linux computer to run the ML programs.

| Topic | Example Code| Video | Instructions and Prompt |
|:---|:---|:---|:---|
|  <a name="a55" href="README.md#a55">`a55-rak-hello`</a>  RAK Read values and Hello Serial Monitor  |  [rack-send08-receive.ino](rak-sketches/rack-send08-receive.ino) <br>also for AT commands  look at [rak-at-commands.md](rak-sketches/rak-at-commands.md)   |     <img src="https://img.youtube.com/vi/aFy9q_klaOc/hqdefault.jpg" width=600 />       <img src="https://img.youtube.com/vi/Eye5zlfl3I8/hqdefault.jpg" width=600 />    <img src="https://img.youtube.com/vi/lDYUIPRGT6k/hqdefault.jpg" width=600 />    | Get used to uploading code by serial monitor "AT+BOOT". To reset code typoe "AT+RUN" Use the RAK rig and connect to the Arduino serial monitor to read all the present set LoRa and LoRaWan variables   <img src="https://github.com/hpssjellis/Maker100-xiaoML-kit/assets/5605614/c4991ceb-7a8f-47d3-89d7-a3d7b361a824" width = "600%" />  |
|   <a name="a56" href="README.md#a56">`a56-rak-LoRaWan-setup`</a>  (Optional) RAK2270StickerTracker [trackpac.io](https://trackpac.eu.auth0.com/u/login) setup   |      |     |  If you have the original RAK2270 Sticker Tracker with TrackPac.io then set it up and monitor your deivce   |
|  <a name="a57" href="README.md#a57">`a57rak-motion`</a>  Machine learning motion x,y,z two label tinyML model   | Reminder put RAK2270 into AT+BOOT for boot mode. Load [d05-webSerial-works.ino](rak-sketches/d05-webSerial-works.ino)  Then go to the static webpage at   [tinyMLjs for the RAK2270StickerTracker](https://hpssjellis.github.io/tinyMLjs/public/acceleration/a00-best-acceleration-rak2270-sticker-tracker.html)  which will walk you through making the c-header code for a machine learning model   |     |   This is advanced and uses webserial to get data from the RAK, then TensorflowJS to make a machine learning model, then [iPython Notebook](https://colab.research.google.com/drive/1OgCcKhklL3EH_SdWHdtlb5dbtYvjGQnn?usp=sharing) to convert TFJS to Keras then to tFlite then to a c-header file. That test c-header file can then be included in the arduino code for exercise A59. (This is advanced) |
|   <a name="a58" href="README.md#a58">`a58rak-lora-receive`</a>  LoRa webSerial reciever   | Install on the RAK2270 use AT+BOOT [l10-lora-p2p-receive-working.ino](rak-sketches/l10-lora-p2p-receive-working.ino). Run https://hpssjellis.github.io/mcu-stable-edu-launch/rak2270-sticker-tracker/html/lora-webpage-best.html webpage and connect the RAK2270 to it using webSerial. Any RAK2270 or other LoRa P2P devices will send to this website. This webpage will receive any RAK p2p data sent from the other assignments such as A55  [rack-send08-receive.ino](rak-sketches/rack-send08-receive.ino)   |     <img src="https://img.youtube.com/vi/dXM0W2zT288/hqdefault.jpg" width=600 />      <img src="https://img.youtube.com/vi/kTSe-4Z0Ewo/hqdefault.jpg" width=600 />       <img src="https://img.youtube.com/vi/4gubEe5WZXw/hqdefault.jpg" width=600 />          | Another advanced use of a static website and webSerial to connect one sticker tracker to receive P2P LoRa information from the other motion machine learning trained devices  [See Appendix H - LoRa Receiver Website Instructions](#appendix-h) |
|   <a name="a59" href="README.md#a59">`a59-rocksetta-tinyML`</a>  RocksettaTinyML   | Not as hard as it looks. Uses the website from A58 to record machine learning motion on the RAK2270. Download this github as a zip file [https://github.com/hpssjellis/RocksettaTinyML](https://github.com/hpssjellis/RocksettaTinyML) and install on the arduino IDE usinging the menu "sketch" --> "Include Library" --> "Add .Zip Library" <br> After the RocksettaTinyML library is installed, load the example: "File" --> "Examples" --> "RocksettaTinyML" --> "RAK2270"-->"ml"-->"RAK2270-motion-2-label" Compile it and seee if it works. Note: must have LoRa P2P support but not LoRaWan support. When you have proof that this runs, then change the main code to -->   [rak2270-motion-2-label-p2p-serial-WORKS2.ino](rak-sketches/rak2270-motion-2-label-p2p-serial-WORKS2.ino)  This code should work with A58 sending the machine learning data to the P2P website that receives the data | ![image](https://github.com/hpssjellis/Maker100-xiaoML-kit/assets/5605614/044e0f38-e535-4bab-a6f2-0553b708ff95) <br> ![image](https://github.com/hpssjellis/maker100-eco/assets/5605614/d6fb67a3-99c0-45a4-acfc-020ce430b31c)    |  Note: You can use the machine learning model you made in assignment A57 but easier for testing just to use the default ML code included with the RocksettaTinyML example.    |


## In-person course using the RAK2270StickerTracker
Students are encouraged to work ahead of the class.

| Topic | Example Code| Video | Instructions |
|:---|:---|:---|:---|
|  <a name="a60" href="README.md#a60">`a60-rak-p2p-LoRa-LoRaWan`</a> LoRaWan and LoRa P2P Test   |  [rak-hack06.ino](rak-sketches/rak-hack06.ino)   |   <img src="https://img.youtube.com/vi/7RiPQgiWXkc/hqdefault.jpg" width=600 />     | Shows many AT commands and switches between LoRaWan and LoRa settings. Your device should be able to send data to your teachers device over a local P2P LoRa network Students can try send there teacher their first names.<br> AT+PSEND=41426162207A3132 should be "ABab z12" <br>See chart <br>  <img src="https://github.com/hpssjellis/Maker100-xiaoML-kit/assets/5605614/cd2d5268-04ae-4e6d-a632-f3762a557026" width = "400px" />  |
|  <a name="a61" href="README.md#a61">`a61-rak-temp-battery`</a>  Run NTC Temperature and Battery Voltage   |  [RAK-NTC-temp.ino](rak-sketches/RAK-NTC-temp.ino)   |   <img src="https://img.youtube.com/vi/1eSEkwWMcjE/hqdefault.jpg" width=600 />     |  Code prints out the battery voltage and board temperature. This gives us a chance to test other battery sources. Reminder anything over 5V may damage this board and even 5V might not work well. Research max and minimum acceptable votages.   |
|   <a name="a62" href="README.md#a62">`a62-rak-LoRaWan-test`</a>  LoRaWan Test   |   [lorawan-test-08-byte-xyz-mapped.ino](rak-sketches/lorawan-test-08-byte-xyz-mapped.ino) with this js decoder file for datacake configuration [cayenneLPP.js](rak-sketches/cayenneLPP.js)   |   <img src="https://github.com/hpssjellis/maker100-eco/assets/5605614/d4bc64f0-9286-4989-a951-14f3b3f97f88" width = "400px" />    |  Get a test login to the console for either [meteoscientific.com](https://console.meteoscientific.com/front/)  or [helium-iot.eu](https://console.helium-iot.xyz/front/) and 1. set a device-profile for US915 and a codeC "cayenneLPP". then an application and on integration switch to datacake Devices, LoRaWan "show setup instructions" switch back and paste that HTTP URL. The back to applications and make a device with DevEUI, AppEUI (called Join eui) and then APpKey. Power up the RAK2270 and monitor debug windows etc. Back on Datacake go to configurations and decoder and past the cayenneLPP.js decoder and try some raw data. if that works then click the fileds and see if you can auto add them. then make a dashboard on datacake with the new fields.   Note: I think the acceleration actual data has issues see if someone can fix it.  |
|   <a name="a63" href="README.md#a63">`a63-rak-motion`</a>  Run xyz acceleration   | [rak-accel-imu.ino](rak-sketches/rak-accel-imu.ino)     |    <img src="https://img.youtube.com/vi/hr-YT-qImJ4/hqdefault.jpg" width=600 />   | Fairly easy acceleration x, y, z example. Only problem here is the Rak clip does not work well with motion. the teacher should have a few boards with soldered wires that can be used well with motion.   |
|   <a name="a64" href="README.md#a64">`a64-rak-fusion`</a>  Sensor Fusion   |      |     |You make this file. you have the code above. Run code with all the Sensors on the RAK2270: temperature, Humidity, 3 axis IMU: motion (xyz)  |
|   <a name="a65" href="README.md#a65">`a65rak-raw`</a> LoRaWan-raw-number   |    [lorawan-test-send-2-bytes.ino](rak-sketches/lorawan-test-send-2-bytes.ino)   with a simple js decoder [2-bytes.js](rak-sketches/2-bytes.js)       |                    |  Theoretically this should be easier than the cayenneLPP setup, but we need simple code and a javascript decoder. See what you can do.  |
|   <a name="a66" href="#a66">`a66-rak-stLink`</a>  STM32CubeProgrammer with STLINK V2 |   Try this blank sketch compiled binary file which allows theAT commands only <br> [rak-only-at-commands.hex](rak-sketches/rak-only-at-commands.hex)   |   <img src="https://img.youtube.com/vi/fUlx79bOjNs/hqdefault.jpg" width=600 />     |  Use the rak clip to access a few of the pins on the RAK2270 to see if you can program thme  |
|   <a name="a67" href="README.md#a67">`a67-rak-pins`</a>  Easy and Hard pins test   |      |     |Use the RAKClip or Solder wires to the pads on the rak2270 and do some pin testing like you would for an Arduino   |
|   <a name="a68" href="README.md#a68">`a68-rak-nothing`</a>  []()   |      |     |    |




## Final Course Projects (Student must complete an individual final project to pass my in-person course, your teacher might have different ideas)

| Topic | Example Code| Video | Instructions |
|:---|:---|:---|:---|
| <a name="FP1" href="README.md#FP1">`FP1`</a>  One sensor with one actuator final project  |      |     |   [See Appendix I - Final Project 1](#appendix-i)  |
| <a name="FP2" href="README.md#FP2">`FP2`</a>  complex sensor, ML, actuator final project  |      |     |   [See Appendix J - Final Project 2](#appendix-j)  |
| <a name="FP3" href="README.md#FP3">`FP3`</a>  group final project, proof of concept for a viable product  |      |     |   [See Appendix K - Final Project 3](#appendix-k)  |


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

 ## Tutorial ml16
 
 Arduino IDE, load board xiao esp32s3, PSRAM -OPI-PSRAM, plugin XIAO ml Kit to USBA Tools Port, upload , reset board, type T or L in serial monitor.  
 For PlatformIO, install VS Code, PlatformIO extension, new progect, board XIAO ESP32S3, load code into main.cpp, fix platformio.ini file, upload, serial monitor, T (tap) or L (longpress). Code to load on platformio and the arduino IDE:  [https://github.com/hpssjellis/my-examples-of-tensorflowjs-for-tinytorch/blob/main/esp-on-device-train-one-program/esp-all-menu-A0-image-train-infer.txt](https://github.com/hpssjellis/my-examples-of-tensorflowjs-for-tinytorch/blob/main/esp-on-device-train-one-program/esp-all-menu-A0-image-train-infer.txt)



 
 
 # Prompt Help me load this code https://github.com/hpssjellis/my-examples-of-tensorflowjs-for-tinytorch/blob/main/esp-on-device-train-one-program/esp-all-menu-A0-image-train-infer.txt onto both the arduino IDE and Platformio to be able to compare them 





 
#### Jeremy Ellis, ex: Rocksetta now <a href="https://ca.linkedin.com/in/jeremy-ellis-4237a9bb">LinkedIn</a>
#### High School Coding (35 Years), Robotics, Web Design, Animation and 3D Printing Teacher, BC Canada
#### Use this in-person course at your own risk!



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

---

# Appendices

## Appendix A: Teacher Extras - Why Not use the XIAO Expansion board and Round Display?

The Seeedstudio [$16.40 USD Expansion board](https://wiki.seeedstudio.com/Seeeduino-XIAO-Expansion-Board/) and [$18.00 USD Round Display](https://wiki.seeedstudio.com/get_start_round_display/) are amazing inexpensive addons to the XIAO-ESP32s3-sense and are very well explained on the Getting started sites listed above.

I have both for my classrooms and may use them as the year goes on, but I have testing to do to find out if the color round display is as fast as my grayscale OLED and I do not like students using I2C and SPI connectors that come with the expansion board because the students naturally begin to feel that they can only use sensors and actuators that come with the correct connectors.

The students for their final projects stay away from new or unusual sensors/actuators because those sensors do not come with the correct connectors. A possible solution is to have the [grove-4-pin-female-jumper-wire](https://ca.robotshop.com/products/grove-4-pin-female-jumper-wire) I would prefer the male pins but it is electrically safer to have the female pins. It also does not help that so many boards use different connectors. I have lots of sensors with connectors that don't work with the grove systems. If you are just starting a course and know that you are going to stick with the [Grove sensor actuator system](https://wiki.seeedstudio.com/Grove_System/) and have a few extra connectors on bare wires ordered for new devices then the expansion board might be a great way to teach.

If you choose to use the expansion board this ebook [here](https://mjrovai.github.io/XIAO_Big_Power_Small_Board-ebook/) covers working with it very well.

---

## Appendix B: Teacher Tips - Teaching Guidelines and Best Practices

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

## Appendix D: Price Comparison - How much cheaper is the XIAOML kit version?

The [Arduino PortentaH7](https://store-usa.arduino.cc/products/portenta-h7) costs $113.90 USD the [LoRa Vision Shield](https://store-usa.arduino.cc/products/arduino-portenta-vision-shield-lora%C2%AE) Costs $69 USD


The [XiaoEsp32s3-sense](https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html) costs $13.99

The [https://www.seeedstudio.com/The-XIAOML-Kit.html](https://www.seeedstudio.com/The-XIAOML-Kit.html) is $22 USD without cables, and micro sd card

The [https://www.seeedstudio.com/The-XIAOML-Kit.html](https://www.seeedstudio.com/The-XIAOML-Kit.html) is $38.90 with everything 
(Esp32S3 Sense with camera microphone SD Card module and IMU OLED module and cables, sd Card reader and micro sd card. You can start learning immediately)




Very hard to compare the XIAO class set of 15 x $38.90 USD = $583.5 USD with a class set of PortentaH7's ($15 x $182.90) = $2743.50 USD

---

## Appendix E: Useful Links

1. Simplified course layout and organization [course-order.md](course-order.md)

2. The original Maker100 Course is https://github.com/hpssjellis/maker100

3. Excellent reference for the Xiao Esp32s3 section of this course [XIAO_Big_Power_Small_Board-ebook](https://mjrovai.github.io/XIAO_Big_Power_Small_Board-ebook/)

4. SeeedStudio Link to the XiaoEsp32s3-Sense store https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html     Note: It needs headers soldered to do many of the assignments.

5. The original XiaoEsp32s3 and RAK2270 research is at https://github.com/hpssjellis/mcu-stable-edu-launch

6. TinyMLjs is at https://github.com/hpssjellis/tinyMLjs

7. RocksettaTinyML Library is at https://github.com/hpssjellis/RocksettaTinyML

---

## Appendix F: EdgeImpulse Vision Model - Instructions and ChatGPT Prompt

**More Instructions:**

Connect your cell phone to EdgeImpulse, take 30 images of pens on various backgrounds, then take 50 images of various backgrounds, create your impulse (96 x 96), generate features, train and then switch to classification on your cell phone

**ChatGPT Prompt:**

Give me the steps to make a vision classification model on edgeimpulse.com with only an unknown label for the background and pens for the object. We will only be using our cell phone to collect the images, so it will need to be connected to the edgeimpulse site. The cell phone will allow the image labelling before I take the images. After the images are taken explain how to setup the impulse machine learning model.

---

## Appendix G: Camera SD Card Instructions - More Details

```
#define PWDN_GPIO_NUM     -1
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM     10
#define SIOD_GPIO_NUM     40
#define SIOC_GPIO_NUM     39
#define Y9_GPIO_NUM       48
#define Y8_GPIO_NUM       11
#define Y7_GPIO_NUM       12
#define Y6_GPIO_NUM       14
#define Y5_GPIO_NUM       16
#define Y4_GPIO_NUM       18
#define Y3_GPIO_NUM       17
#define Y2_GPIO_NUM       15
#define VSYNC_GPIO_NUM    38
#define HREF_GPIO_NUM     47
#define PCLK_GPIO_NUM     13
```



---

## Appendix H: LoRa Receiver Website - More Instructions

The website is from my page, if you want to edit it, just download the entire Maker100-xiaoML-kit repository and go to the folder [rak-sketches/rak-html/lora-webpage-best.html](/rak-sketches/rak-html/lora-webpage-best.html) from your computer so you can make changes. Typically these websites need to run from an https webpage but I think these run fine from your own computer even if the internet is shut off

---


