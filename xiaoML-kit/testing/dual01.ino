// Define the LED pin. Use the built-in LED on your ESP32-S3 board.
// On some boards, this is pin 2, 4, 10, or 13.
#define LED_BUILTIN 21

// Task handles for each core
TaskHandle_t Task1;
TaskHandle_t Task2;

// The function for Core 0 (Task 1) - does serial printing
void Task1code( void * pvParameters ) {
  Serial.println("Task1 running on core " + String(xPortGetCoreId()));
  
  for(;;) {
    Serial.println("Hello from Core 0!");
    delay(1000); 
  }
}

// The function for Core 1 (Task 2) - blinks the LED
void Task2code( void * pvParameters ) {
  Serial.println("Task2 running on core " + String(xPortGetCoreId()));
  
  pinMode(LED_BUILTIN, OUTPUT);

  for(;;) {
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(500);
    digitalWrite(LED_BUILTIN, LOW); 
    delay(500); 
  }
}

void setup() {
  Serial.begin(115200);
  
  // Create the serial print task and pin it to Core 0
  // Note: Core 0 is responsible for most of the system tasks, like Wi-Fi and Bluetooth.
  // We pin this non-critical task here to demonstrate the concept.
  xTaskCreatePinnedToCore(
    Task1code,   // Task function
    "SerialTask",   // Task name
    10000,          // Stack size in words
    NULL,           // Task input parameter
    1,              // Task priority
    &Task1,         // Task handle
    0               // Core where the task should run (Core 0)
  );

  // Give the first task a moment to initialize
  delay(500);

  // Create the LED blink task and pin it to Core 1
  // Core 1 is often the "Application Core" and is a good place for your main logic.
  xTaskCreatePinnedToCore(
    Task2code,   // Task function
    "BlinkTask",   // Task name
    10000,          // Stack size in words
    NULL,           // Task input parameter
    1,              // Task priority
    &Task2,         // Task handle
    1               // Core where the task should run (Core 1)
  );
}

// The loop() function is not used in this example since the two tasks handle all the logic.
void loop() {
  // A dual-core application often does not use the main loop()
}
