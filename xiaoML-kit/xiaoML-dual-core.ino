#include "Arduino.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


// The size of the stack for the Core 0 task, in words.
const UBaseType_t myStackWords = 739;  // the output will give you suggestions on this

// We need a task handle to get information about the task, like its stack usage.
TaskHandle_t TaskCore0Handle = NULL;



// The function for Core 0 - blinks the LED
void TaskCore0( void * pvParameters ) {
  
  // Initialize the LED pin for this task
  pinMode(LED_BUILTIN, OUTPUT);

  for(;;) {
    digitalWrite(LED_BUILTIN, HIGH); 
    // Use vTaskDelay for FreeRTOS tasks
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, LOW); 
    vTaskDelay(500 / portTICK_PERIOD_MS); 
  }
}

// The setup() function, which runs on Core 1 by default
void setup() {
  Serial.begin(115200);
  
  // Wait for the serial port to be ready
  delay(1000);

  Serial.print("Setup is running on Core ");
  Serial.println(xPortGetCoreID());

  // Create the LED task and pin it to Core 0
  // Note the addition of &TaskCore0Handle to store the task handle
  xTaskCreatePinnedToCore(
    TaskCore0,          // Task function
    "LedTask",          // Task name
    myStackWords,       // Stack size in words, using our new variable
    NULL,               // Task input parameter
    1,                  // Task priority
    &TaskCore0Handle,   // Task handle (now stored in our global variable)
    0                   // Core to run the task on (Core 0)
  );
}

// The loop() function, which also runs on Core 1 by default
void loop() {
  Serial.print("Loop is running on Core ");
  Serial.println(xPortGetCoreID());
  
  // A simple serial print to show that Core 1 is busy
  Serial.println("Hello from Core 1! The LED is controlled by Core 0");
  
  // Check if the task handle is valid before getting the stack information
  if(TaskCore0Handle != NULL) {
    // Get and print the remaining stack for the Core 0 task
    UBaseType_t remainingStack = uxTaskGetStackHighWaterMark(TaskCore0Handle);
    //Serial.print("LED Task remaining stack (words): ");
    //Serial.println(remainingStack);
    
    // Calculate the suggested stack size with a 10% safety buffer.
    UBaseType_t suggestedSize = (myStackWords - remainingStack) * 1.1;    
    Serial.print("You set a stacksize for core 0 of (words): ");
    Serial.println(myStackWords);
    Serial.print("Suggested stack size for core 0 (words): ");
    Serial.println(suggestedSize);
    Serial.println("---------------------------");
    Serial.println();
  }
  
  delay(1000);
}
