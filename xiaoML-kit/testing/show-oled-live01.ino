
/*
 * 

 * Make sure you compile the code with PSRAM set to OPI-PSRAM
 * 
 * Most of the below do not work with the esp32s3sense camera which likes JPEG format with 320x240 as the smallest resolution
 * 
 * 
 * ESP32S3 only these work
 * 
FRAMESIZE_UXGA (1600 x 1200)
FRAMESIZE_QVGA (320 x 240)
FRAMESIZE_CIF (352 x 288)
FRAMESIZE_VGA (640 x 480)
FRAMESIZE_SVGA (800 x 600)
FRAMESIZE_XGA (1024 x 768)
FRAMESIZE_SXGA (1280 x 1024)
 * 
 * 
 * 
 * 
typedef enum {
    FRAMESIZE_96X96,     // 96x96
    FRAMESIZE_QQVGA,     // 160x120
    FRAMESIZE_QCIF,      // 176x144
    FRAMESIZE_HQVGA,     // 240x176
    FRAMESIZE_240X240,   // 240x240
    FRAMESIZE_QVGA,      // 320x240
    FRAMESIZE_CIF,       // 400x296
    FRAMESIZE_HVGA,      // 480x320
    FRAMESIZE_VGA,       // 640x480
    FRAMESIZE_SVGA,      // 800x600
    FRAMESIZE_XGA,       // 1024x768
    FRAMESIZE_HD,        // 1280x720
    FRAMESIZE_SXGA,      // 1280x1024
    // 3MP Sensors
    FRAMESIZE_FHD,       // 1920x1080
    FRAMESIZE_P_HD,      //  720x1280
    FRAMESIZE_P_3MP,     //  864x1536
    FRAMESIZE_QXGA,      // 2048x1536
    // 5MP Sensors
    FRAMESIZE_QHD,       // 2560x1440
    FRAMESIZE_WQXGA,     // 2560x1600
    FRAMESIZE_P_FHD,     // 1080x1920
    FRAMESIZE_QSXGA,     // 2560x1920
    FRAMESIZE_INVALID
} framesize_t;
*
*
*
typedef enum {
    PIXFORMAT_RGB565,    // 2BPP/RGB565
    PIXFORMAT_YUV422,    // 2BPP/YUV422
    PIXFORMAT_YUV420,    // 1.5BPP/YUV420
    PIXFORMAT_GRAYSCALE, // 1BPP/GRAYSCALE
    PIXFORMAT_JPEG,      // JPEG/COMPRESSED
    PIXFORMAT_RGB888,    // 3BPP/RGB888
    PIXFORMAT_RAW,       // RAW
    PIXFORMAT_RGB444,    // 3BP2P/RGB444
    PIXFORMAT_RGB555,    // 3BP2P/RGB555
} pixformat_t;

*

*/




#include "esp_camera.h"
#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include <U8g2lib.h>
#include <Wire.h>

// Initialize the OLED display for a 72x40 monochrome screen
U8G2_SSD1306_72X40_ER_1_HW_I2C u8g2(U8G2_R2, U8X8_PIN_NONE);

// Camera pin definitions for XIAO ESP32S3
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

// Simple flag to track if the camera is initialized
bool myCameraIsReady = false;

// Counter for display
int myOledCount = 0;

// This function takes a camera framebuffer and draws it to the OLED
void myDrawImageToOled(camera_fb_t *myFb) {
  // Get the image dimensions from the frame buffer
  int myImageWidth = myFb->width;
  int myImageHeight = myFb->height;

  // Get OLED dimensions from the u8g2 object
  int myOledWidth = u8g2.getDisplayWidth();
  int myOledHeight = u8g2.getDisplayHeight();
  
  // Allocate a new buffer in PSRAM for the uncompressed RGB888 image
  // Each pixel in RGB888 format is 3 bytes (Red, Green, Blue)
  size_t myRgbBufferSize = myImageWidth * myImageHeight * 3;
  uint8_t *myRgbBuffer = (uint8_t *)ps_malloc(myRgbBufferSize);
  
  if (myRgbBuffer == NULL) {
    Serial.println("Failed to allocate memory for RGB888 buffer in PSRAM.");
    return;
  }

  // Convert the JPEG data to the new RGB888 buffer
  // The first parameter is the source (JPEG) buffer.
  // The fourth parameter is the destination (RGB888) buffer.
  bool conversionSuccess = fmt2rgb888(myFb->buf, myFb->len, myFb->format, myRgbBuffer);
  
  if (!conversionSuccess) {
    Serial.println("Failed to convert JPEG to RGB888.");
    free(myRgbBuffer);
    return;
  }
  
  // Calculate the scaling factors for width and height
  int myScaleX = myImageWidth / myOledWidth;
  int myScaleY = myImageHeight / myOledHeight;

  // The OLED display must be updated inside the firstPage/nextPage loop
  u8g2.firstPage();
  do {
    // Loop through each pixel on the OLED display
    for (int myOledY = 0; myOledY < myOledHeight; myOledY++) {
      for (int myOledX = 0; myOledX < myOledWidth; myOledX++) {
        // Map the OLED pixel coordinates to the camera image coordinates
        int myImageX = myOledX * myScaleX;
        int myImageY = myOledY * myScaleY;
        
        // Calculate the byte index for the corresponding pixel in the RGB888 buffer
        // Each pixel has 3 bytes (R, G, B)
        size_t myPixelIndex = (myImageY * myImageWidth + myImageX) * 3;

        // Check to make sure we don't go out of bounds
        if (myPixelIndex + 2 < myRgbBufferSize) {
          // Get the color values for the pixel
          uint8_t myRed = myRgbBuffer[myPixelIndex];
          uint8_t myGreen = myRgbBuffer[myPixelIndex + 1];
          uint8_t myBlue = myRgbBuffer[myPixelIndex + 2];
          
          // Convert the color pixel to a single brightness value (monochrome)
          // We can do this by taking a weighted average for better results
          uint8_t myBrightness = (myRed * 0.299) + (myGreen * 0.587) + (myBlue * 0.114);

          // The OLED pixel is either ON or OFF. We need a threshold to decide.
          if (myBrightness > 128) {
            u8g2.drawPixel(myOledX, myOledY);
          }
        }
      }
    }
    
    // Draw the counter on top
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.setColorIndex(0); // Set color to black for the box
    u8g2.drawBox(0, 0, 20,15);
    u8g2.setColorIndex(1); // Set color back to white for the text
    u8g2.setCursor(3, 10);
    u8g2.print(String(myOledCount));
    
  } while (u8g2.nextPage());

  // Free the PSRAM buffer to prevent memory leaks
  free(myRgbBuffer);
}

// SD card write file
void writeFile(fs::FS &fs, const char * path, uint8_t * data, size_t len){
    Serial.printf("Writing file: %s\n", path);
    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.write(data, len) == len){
      Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}

// Save pictures to SD card
void photo_save(const char * fileName) {
  // Take a photo
  camera_fb_t *fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Failed to get camera frame buffer");
    return;
  }
  // Save photo to file
  writeFile(SD, fileName, fb->buf, fb->len);

  // Calculate file size in KB
  float fileSizeKB = fb->len / 1024.0;
  
  // Print the file size
  Serial.printf("File size: %.2f KB\n", fileSizeKB);
  
  // Release image buffer
  esp_camera_fb_return(fb);

  Serial.println("Photo saved to file");
}

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  
  // Initialize and clear the OLED
  u8g2.begin();
  u8g2.clearDisplay();
  
  // Display initial message
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.setCursor(3, 20);
    u8g2.print("Squeeze");
  } while (u8g2.nextPage());
  
  delay(1000);
  
  // Camera configuration
  camera_config_t myConfig;
  myConfig.ledc_channel = LEDC_CHANNEL_0;
  myConfig.ledc_timer = LEDC_TIMER_0;
  myConfig.pin_d0 = Y2_GPIO_NUM;
  myConfig.pin_d1 = Y3_GPIO_NUM;
  myConfig.pin_d2 = Y4_GPIO_NUM;
  myConfig.pin_d3 = Y5_GPIO_NUM;
  myConfig.pin_d4 = Y6_GPIO_NUM;
  myConfig.pin_d5 = Y7_GPIO_NUM;
  myConfig.pin_d6 = Y8_GPIO_NUM;
  myConfig.pin_d7 = Y9_GPIO_NUM;
  myConfig.pin_xclk = XCLK_GPIO_NUM;
  myConfig.pin_pclk = PCLK_GPIO_NUM;
  myConfig.pin_vsync = VSYNC_GPIO_NUM;
  myConfig.pin_href = HREF_GPIO_NUM;
  myConfig.pin_sscb_sda = SIOD_GPIO_NUM;
  myConfig.pin_sscb_scl = SIOC_GPIO_NUM;
  myConfig.pin_pwdn = PWDN_GPIO_NUM;
  myConfig.pin_reset = RESET_GPIO_NUM;
  myConfig.xclk_freq_hz = 20000000;
  myConfig.frame_size = FRAMESIZE_VGA;     // FRAMESIZE_QVGA; //works quality 10, breaks in bright sounlight, but resets
  myConfig.pixel_format = PIXFORMAT_JPEG; 
  myConfig.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  myConfig.fb_location = CAMERA_FB_IN_PSRAM;
  myConfig.jpeg_quality = 12;
  myConfig.fb_count = 1;
  
  // if PSRAM IC present, init with higher JPEG quality for a larger pre-allocated frame buffer.
  if (psramFound()) {
    Serial.println("PSRAM has been successfully detected.");
    myConfig.jpeg_quality = 12;
    myConfig.fb_count = 2;
    myConfig.grab_mode = CAMERA_GRAB_LATEST;
  } else {
    Serial.println("PSRAM was NOT detected.");
    myConfig.frame_size = FRAMESIZE_SVGA;
    myConfig.fb_location = CAMERA_FB_IN_DRAM;
  }

  // camera init
  esp_err_t myErr = esp_camera_init(&myConfig);
  if (myErr != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x\n", myErr);
    return;
  }
  myCameraIsReady = true;

  // Initialize SD card
  if (!SD.begin(21)) {
    Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("No SD card attached");
    return;
  }
}

void loop() {
  // Only proceed if the camera is ready
  if (myCameraIsReady) {
    // Take a picture
    camera_fb_t *myFb = esp_camera_fb_get();
    if (!myFb) {
      Serial.println("Failed to get camera frame buffer");
      return;
    }

    // Continuously pass the framebuffer to the drawing function
    myDrawImageToOled(myFb);

    // Release the framebuffer to free up memory
    esp_camera_fb_return(myFb);
    
    // Check if the A0 pin is "squeezed" to trigger a photo save
    int myA0 = analogRead(A0);
    if (myA0 > 1000) {
      digitalWrite(LED_BUILTIN, LOW); // onboard LED on
      Serial.println("Picture taken since A0 was: " + String(myA0));
      
      char filename[32];
      sprintf(filename, "/image%d.jpg", myOledCount);
      photo_save(filename);
      
      myOledCount++;
      // Wait a moment to avoid multiple increments from a single press
      delay(500);
      digitalWrite(LED_BUILTIN, HIGH); // onboard LED off
    }
  }
}
