/*
 * webSerial for testing javascript connection with an arduino
 * 
* Latest WebSerial ML Arduino work at   https://github.com/hpssjellis/tinyMLjs
*  
* 
* RocksettaTinyML by Jeremy Ellis,keyfreemusic@gmail.com
*
* Based on the Arduino Library
* EloquentTinyML by Simone Salerno,eloquentarduino@gmail.com
* https://github.com/eloquentarduino/EloquentTinyML
* 
* 
* 
* Passed from the main program
* #define NUMBER_OF_INPUTS 8
* #define TYPE_OF_INPUTS int32             // uint8_t | int32 | float | bool | double | String 
* 
* #define NUMBER_OF_OUTPUTS 4
* #define TYPE_OF_OUTPUTS float            // uint8_t |int32 | float | bool | double | String 
* 
* #define RETURN_TYPE_FROM_PREDICT float    // void | uint8_t | int32 | float | bool | double | String 
* 

 */



#include <Arduino.h> // Only needed for https://platformio.org/
#include <RocksettaTinyML.h>
#include "xiaoMLMotion.h"

#define NUMBER_OF_INPUTS 72   // 36 x 2
#define NUMBER_OF_OUTPUTS 2
#define RETURN_TYPE_FROM_PREDICT float
#define TENSOR_ARENA_SIZE 8*1024  

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;
int myCurrentIndex = 0;
float myInput[NUMBER_OF_INPUTS];
float myOutput[NUMBER_OF_OUTPUTS];
//bool myPredictProximity = false;
bool myPredictMotion = true;




// REV 2 CHANGES HERE 

/* For LSM9DS1 9-axis IMU sensor */
//#include <Arduino_LSM9DS1.h>         // nano33 REV 1
//#include "Arduino_BMI270_BMM150.h"   // nano33 REV 2

#include <LSM6DS3.h>   // for xiaoML kit
#include <Wire.h>      // for xiaoML kit



/* For HTS221 Temperature and humidity sensor */
/* not needed here */
//#include <Arduino_HTS221.h>          // nano33 REV 1
//#include <Arduino_HS300x.h>          // nano33 REV 2
//#define HTS HS300x                   // nano33 For REV 2 to work with old REV1 code



// GLOBAL VAERIABLES
//VL53L1X proximity;


LSM6DS3 myIMU(I2C_MODE, 0x6A);

#define FREQUENCY_HZ        36     // how many samples per second 
#define COLLECTION_SECONDS  1     // how many seconds to collect samples
#define INTERVAL_MS  (1000 / (FREQUENCY_HZ + 1)) // need for the timer 
#define CONVERT_G_TO_MS2    9.80665f   // accleration conversion

int myMaxData = FREQUENCY_HZ * COLLECTION_SECONDS;
int myCount = 0;
int myDelay = INTERVAL_MS;   // non-block delay in milliseconds
unsigned long myStart; 

//bool mySendData = true;
/*
String readString;

bool mySendProximity = false;
int myProximityReading = 0;
*/

void setup() { 
  ml.begin(model_tflite);  // Not the name of the header file, name of the unsigned char Array
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // onboard LED, HIGH = off
  //while (!Serial) {}                 // do nothing and wait
  if (!Serial){delay(3000);}

    
  myStart = millis();   // set delay
  randomSeed(analogRead(A0));  // AO pin on XIAO does not have to be connected to anything
  Serial.println("accX,accY,accZ");  // CSV file heading titles
  


  // Initialize the IMU
  if (myIMU.begin() != 0) {
      Serial.println("ERROR: IMU initialization failed!");
      while(1) delay(1000);
  } else {
     Serial.println("accX,accY,accZ");  // CSV file heading titles
  }

  // Initilize the Proximity sensor and com using wire1
  Wire1.begin();
  Wire1.setClock(400000); // use 400 kHz I2C


  
  // initialize buffer to zeros
  for (int i = 0; i < NUMBER_OF_INPUTS; i++) {
    myInput[i] = 0.0;
  }

}

void loop() {
 // float x, y, z;
 // myProximityReading = proximity.read();


//  if (myIMU.accelerationAvailable()) {
  //  IMU.readAcceleration(x, y, z);
    // Read IMU data
    float x = myIMU.readFloatAccelX();
    float y = myIMU.readFloatAccelY();
    float z = myIMU.readFloatAccelZ();

    x *= CONVERT_G_TO_MS2; 
    y *= CONVERT_G_TO_MS2;
    z *= CONVERT_G_TO_MS2;
  //}
  myInput[myCurrentIndex] = x;
  myInput[myCurrentIndex+1] = y;
  myInput[myCurrentIndex+2] = z;
  myCurrentIndex = (myCurrentIndex + 3) % NUMBER_OF_INPUTS; // Wrap around to the beginning when the end is reached.


  if ( (millis() - myStart ) >= myDelay) {       
     myStart = millis();      //  reset the delay time
     myCount += 1;
    float x = myIMU.readFloatAccelX();
    float y = myIMU.readFloatAccelY();
    float z = myIMU.readFloatAccelZ();

    x *= CONVERT_G_TO_MS2; 
    y *= CONVERT_G_TO_MS2;
    z *= CONVERT_G_TO_MS2;

    if (myPredictMotion) {
      myCurrentIndex = (myCurrentIndex + 3) % NUMBER_OF_INPUTS; // Wrap around to the beginning when the end is reached.

 
      if (myCurrentIndex % NUMBER_OF_INPUTS == 0) {   // slows down showing the results

        // note myPredicted is myOutput[0] less confusing just to use myOutput[0]
        float myPredict = ml.predict(myInput, myOutput); // make the proximity prediction on the last 36 samples


         // might work faster without all these println's
        // Serial.print("label[0]: "+String(myOutput[0]) + ",  label[1]:" + String(myOutput[1]) + ",  label[2]:" + String(myOutput[2]) + ",  label[3]:" + String(myOutput[3]) );  
         Serial.print("label[0]: "+String(myOutput[0]) + ",  label[1]:" + String(myOutput[1])  );  
        if (myOutput[0] > 0.50) {  
          digitalWrite(LED_BUILTIN, LOW);    // on for portenta, off for Nano33BleSense
          Serial.print(" Detection");
          //delay(5);   // just so you can see the LED
      }
      else {
          digitalWrite(LED_BUILTIN, HIGH);
        }
      Serial.println();    
    //  delay(40);
      }




    }  


    }




}

    
