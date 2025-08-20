/*
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

//#define CAMERA_MODEL_XIAO_ESP32S3 // Has PSRAM



// Initialize the OLED display
U8G2_SSD1306_72X40_ER_1_HW_I2C u8g2(U8G2_R2, U8X8_PIN_NONE);  // efficient buffer  
// u8g2.firstPage(); do { } while (u8g2.nextPage());

// U8G2_SSD1306_72X40_ER_F_HW_I2C u8g2(U8G2_R2, U8X8_PIN_NONE); // full buffer
// u8g2.sendBuffer(); // Transfer the internal memory to the display

//#if defined(CAMERA_MODEL_XIAO_ESP32S3)
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

//#else
//#error "Camera model not selected"
//#endif

//#include "camera_pins.h"

//int myNextImage = 5000;    //seconds between images
unsigned long lastCaptureTime = 0; // Last shooting time
int imageCount = 1;              // File Counter
bool camera_sign = false;          // Check camera status
bool sd_sign = false;              // Check sd status

int myOledCount = 0;

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



  // ----- CODE ADDED FOR YOUR REQUEST -----
  // 1. Get the image dimensions from the frame buffer
  int myImageWidth = fb->width;
  int myImageHeight = fb->height;

  // 2. Allocate a new buffer in PSRAM for the uncompressed RGB888 image
  // Each pixel in RGB888 format is 3 bytes (Red, Green, Blue)
  size_t myRgbBufferSize = myImageWidth * myImageHeight * 3;
  uint8_t *myRgbBuffer = (uint8_t *)ps_malloc(myRgbBufferSize);
  
  if (myRgbBuffer == NULL) {
    Serial.println("Failed to allocate memory for RGB888 buffer in PSRAM.");
    esp_camera_fb_return(fb);  //deallocate the frame buffer before quitting
    return;
  }

  // 3. Convert the JPEG data to the new RGB888 buffer
  // The first parameter is the source (JPEG) buffer.
  // The fourth parameter is the destination (RGB888) buffer.
  bool conversionSuccess = fmt2rgb888(fb->buf, fb->len, fb->format, myRgbBuffer);
  
  if (conversionSuccess) {
    Serial.println("JPEG successfully converted to RGB888.");
    
    // 4. Test: Extract and print the values of a single pixel
    int myTestX = myImageWidth / 2;
    int myTestY = myImageHeight / 2;
    // Calculate the byte offset for the center pixel
    size_t myOffset = ((myTestY * myImageWidth) + myTestX) * 3;
    
    // Check if the offset is within the buffer bounds
    if (myOffset + 2 < myRgbBufferSize) {
      uint8_t myRed = myRgbBuffer[myOffset];
      uint8_t myGreen = myRgbBuffer[myOffset + 1];
      uint8_t myBlue = myRgbBuffer[myOffset + 2];
      Serial.printf("Center pixel (R, G, B) at (%d, %d): (%d, %d, %d)\n", myTestX, myTestY, myRed, myGreen, myBlue);
    }
  } else {
    Serial.println("Failed to convert JPEG to RGB888.");
  }
  
  // -------------------------------------------------------------
  // NEW CODE STARTS HERE: Drawing the image to the OLED
  // -------------------------------------------------------------

  // Get OLED dimensions from the u8g2 object
  int myOledWidth = u8g2.getDisplayWidth();
  int myOledHeight = u8g2.getDisplayHeight();

  // The camera image (320x240) is much larger than the OLED (72x40).
  // We need to scale it down. The simplest way is to sample pixels from the
  // large image to create the smaller one.
  //
  // Calculate the scaling factors for width and height
  // Since 320/72 is not an integer, we'll use integer division to
  // find a simple sampling rate. 320 / 72 = ~4.44, so we'll sample
  // about every 4 pixels horizontally.
  // 240 / 40 = 6, so we'll sample exactly every 6 pixels vertically.
  int myScaleX = myImageWidth / myOledWidth;
  int myScaleY = myImageHeight / myOledHeight;

  // The OLED display must be updated inside the firstPage/nextPage loop
  u8g2.firstPage();
  do {

    // Loop through each pixel on the OLED display
    for (int myOledX = 0; myOledX < myOledWidth; myOledX++) {
      for (int myOledY = 0; myOledY < myOledHeight; myOledY++) {
        
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
          // We can do this by taking the average of the R, G, and B values.
          uint8_t myBrightness = (myRed + myGreen + myBlue) / 3;

          // The OLED pixel is either ON or OFF. We need a threshold to decide.
          // If the brightness is above 128 (halfway), turn the pixel ON.
          if (myBrightness > 128) {   // 128 is in the middle, 100 OK, 80 too light
            u8g2.drawPixel(myOledX, myOledY);
          }
        }
      }
    }
    
    // Your existing code to draw the counter on top
    // The u8g2.firstPage()/nextPage() loop handles all drawing commands.
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.setColorIndex(0);
    u8g2.drawBox(0, 0, 20,15);
    u8g2.setColorIndex(1);
    u8g2.setCursor(3, 10);
    u8g2.print(String(myOledCount));

    
  } while (u8g2.nextPage());

  // -------------------------------------------------------------
  // NEW CODE ENDS HERE
  // -------------------------------------------------------------

  // 5. Free the PSRAM buffer
  free(myRgbBuffer);



  
  // Release image buffer
  esp_camera_fb_return(fb);

 // Serial.println("Photo saved to file");
}

// SD card write file
void writeFile(fs::FS &fs, const char * path, uint8_t * data, size_t len){
   // Serial.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("Failed to open file for writing");
        return;
    }
    if(file.write(data, len) == len){
      //  Serial.println("File written");
    } else {
        Serial.println("Write failed");
    }
    file.close();
}

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);    // when HIGH take picture
  pinMode(LED_BUILTIN,OUTPUT);
  randomSeed(analogRead(A0));  // Seed the random number generator
  imageCount = random(100000);  // so the filename count starts different each time
  if(!Serial){delay(3000);} // This is non-blocking. Does add a delay which can be useful when things go bad. 
  // while (!Serial) {delay(10);} // blocking


  u8g2.begin();


  
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.frame_size = FRAMESIZE_QVGA; // FRAMESIZE_HD;  1280x720 quality 10 // FRAMESIZE_VGA; 800 x 600 quality 8 // FRAMESIZE_QVGA; works--> 320x240 quality 3    //FRAMESIZE_UXGA; works  //1600 x 1200 // quality 10
  config.pixel_format = PIXFORMAT_JPEG; // for streaming  
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 12;    // 0 great to 63 poor many do not work
  config.fb_count = 1;
  
  // if PSRAM IC present, init with UXGA resolution and higher JPEG quality
  //                     for larger pre-allocated frame buffer.
  if(config.pixel_format == PIXFORMAT_JPEG){
    if (psramFound()) {
      Serial.println("PSRAM has been successfully detected.");
    } else {
      Serial.println("PSRAM was NOT detected.");
    }
    if(psramFound()){
      config.jpeg_quality = 10; // 6 and 8 work but not in bright light or give the camera time to adjust
      // quality 3 on FRAMESIZE_QVGA; works 320 x 240
      // FRAMESIZE_VGA; 800 x 600 works quality 8 
      // FRAMESIZE_HD;    1280x720 quality 10 works
      // quality 10 on FRAMESIZE_UXGA 1600 x 1200 
      // quality can be 0 high quality to 63 very low quality but memory is effected.
    
      config.fb_count = 2;
      config.grab_mode = CAMERA_GRAB_LATEST;
    } else {
      // Limit the frame size when PSRAM is not available
      config.frame_size = FRAMESIZE_SVGA;
      config.fb_location = CAMERA_FB_IN_DRAM;
    }
  } else {
    // Best option for face detection/recognition
    config.frame_size = FRAMESIZE_240X240;
#if CONFIG_IDF_TARGET_ESP32S3
    config.fb_count = 2;
#endif
  }

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }
  
  camera_sign = true; // Camera initialization check passes

  // Initialize SD card
  if(!SD.begin(21)){
    Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD.cardType();

  // Determine if the type of SD card is available
  if(cardType == CARD_NONE){
    Serial.println("No SD card attached");
    return;
  }

  Serial.print("SD Card Type: ");
  if(cardType == CARD_MMC){
    Serial.println("MMC");
  } else if(cardType == CARD_SD){
    Serial.println("SDSC");
  } else if(cardType == CARD_SDHC){
    Serial.println("SDHC");
  } else {
    Serial.println("UNKNOWN");
  }

  sd_sign = true; // sd initialization check passes

 u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.setCursor(3, 20);
    u8g2.print("Squeeze");

  } while (u8g2.nextPage());
}

void loop() {
    int myA0 = analogRead(A0);
  // Camera & SD available, start taking pictures
  if(camera_sign && sd_sign){
    if (myA0 > 1000){  // actually the max is 4095
      digitalWrite(LED_BUILTIN, LOW);  // onboard LED on (weird)
    
      Serial.println("Picture taken since A0 was: "+ String(myA0));
      char filename[32];
      sprintf(filename, "/image%d.jpg", imageCount);
      photo_save(filename);
      Serial.printf("Saved picture：%s\n", filename);
      imageCount++;
      myOledCount++;



      delay(500); // so we don't take too many images too fast
      digitalWrite(LED_BUILTIN, HIGH);  // on board LED off (weird)
      Serial.println();
  }
  }
}
