// static blick, serial print, OLED
// Much easier than proper way to do it with timers.

#include <U8g2lib.h>
#include <Wire.h>

// Initialize the OLED display
//U8G2_SSD1306_72X40_ER_1_HW_I2C u8g2(U8G2_R2, U8X8_PIN_NONE);  // efficient buffer   
// u8g2.firstPage(); do { } while (u8g2.nextPage());

U8G2_SSD1306_72X40_ER_F_HW_I2C u8g2(U8G2_R2, U8X8_PIN_NONE); // full buffer
// u8g2.sendBuffer(); // Transfer the internal memory to the display

int myA0;
bool myLedOff = true;

void setup() {
  Serial.begin(115200);
  if (!Serial) {delay(5000);}  // to give 5 seconds to plugin serial but not demand it.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT); 
  u8g2.begin();
}

void loop() {
  myA0 = analogRead(A0);
  u8g2.clearDisplay();
  
  // u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setCursor(8, 20);
  u8g2.print("A0 :"); 
  u8g2.setCursor(8, 40);
  u8g2.print(String(myA0)); 
  u8g2.drawPixel(random(72), random(40));     // random pixel
  
  u8g2.sendBuffer();
  
  Serial.println("A0: " + String(myA0)+", on core " + String(xPortGetCoreID()) ); 

  if (myLedOff) {  //flip LED on/off
    digitalWrite(LED_BUILTIN, HIGH); // actually many boards have the LED on by grounding it to LOW
    myLedOff = false;
  } else {
      digitalWrite(LED_BUILTIN, LOW);
      myLedOff = true;
  }

  delay(200);  // slowness of everything 1000 = 1s delay

}
