/*
 * Modified from original code to loop recording and saving.
 * * Must enable OPI PSRAM, and USB CDC on Boot (Tools menu at top)
 * Most code taken from the ESP_I2S example Record_to_WAV.ino
 * (https://github.com/Seeed-Studio/wiki-documents/blob/docusaurus-version/docs/Sensor/SeeedStudio_XIAO/SeeedStudio_XIAO_ESP32S3_Sense/XIAO_ESP32S3_Sense_mic.md)
 */

#include "ESP_I2S.h"
#include "FS.h"
#include "SD.h"

// Define constants for recording duration and file naming
#define RECORD_TIME 5
#define FILE_NAME "sample"

// Create an instance of the I2SClass
I2SClass i2s;

// Global counter for the file names
int imageCount = 1;

void setup() {
  // Initialize the serial port for communication
  Serial.begin(115200);
  while (!Serial) {
    delay(5000); // Wait for the serial port to connect
  }

  Serial.println("Initializing I2S bus...");

  // Set up the pins used for audio input (I2S PDM RX)
  i2s.setPinsPdmRx(42, 41);

  // Start I2S at 16 kHz with 16-bits per sample in mono mode
  if (!i2s.begin(I2S_MODE_PDM_RX, 16000, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO)) {
    Serial.println("Failed to initialize I2S!");
    while (1); // Stop execution if initialization fails
  }

  Serial.println("I2S bus initialized.");
  Serial.println("Initializing SD card...");

  // Set up the pins used for SD card access
  if (!SD.begin(21)) {
    Serial.println("Failed to mount SD Card!");
    while (1); // Stop execution if mounting fails
  }
  Serial.println("SD card initialized.");

  // Seed the random number generator for unique file names
  randomSeed(analogRead(0));
  imageCount = random(100000);
}

void loop() {
  // Create variables to store the audio data
  uint8_t *wav_buffer;
  size_t wav_size;

  Serial.printf("Recording %d seconds of audio data...\n", RECORD_TIME);

  // Record audio and save the raw file data to a buffer
  wav_buffer = i2s.recordWAV(RECORD_TIME, &wav_size);

  // Create a unique file name using the counter
  String fileName = "/" + String(FILE_NAME) + String(imageCount) + ".wav";

  // Open the file on the SD card for writing
  File file = SD.open(fileName.c_str(), FILE_WRITE);
  
  if (!file) {
    Serial.printf("Unable to open %s for writing.\n", fileName.c_str());
    // Continue the loop even if the file can't be opened, to try again
    delay(5000); 
    return;
  }

  Serial.println("Writing audio data to file...");

  // Write the audio data from the buffer to the file
  if (file.write(wav_buffer, wav_size) != wav_size) {
    Serial.println("Failed to write audio data to file!");
  } else {
    Serial.printf("Successfully wrote to %s\n", fileName.c_str());
  }

  // Close the file to save it
  file.close();

  // Increment the counter for the next recording
  imageCount++;

  Serial.println("Waiting for 5 seconds...");

  // Wait for 5 seconds before the next recording cycle
  delay(5000);
}
