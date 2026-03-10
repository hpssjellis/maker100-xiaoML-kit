
Lots of cool stuff can be done with this LoRa and esp32S3 board

Too bad we lose the Camera and microphone, but we could connect the Grove Vision AI V2.






## Straight out of the box

| Pin Label | GPIO | Internal Usage / LoRa Conflict | Status |
| :--- | :--- | :--- | :--- |
| **D0 / A0** | GPIO 1 | None | ✅ SAFE |
| **D1 / A1** | GPIO 2 | None | ✅ SAFE |
| **D2 / A2** | GPIO 3 | Strapping Pin (Keep HIGH/Float at boot) | ✅ SAFE |
| **D3 / A3** | GPIO 4 | None | ✅ SAFE |
| **D4 / A4** | GPIO 5 | Available for I2C | ✅ SAFE |
| **D5 / A5** | GPIO 6 | Available for I2C | ✅ SAFE |
| **D6** | GPIO 43 | Available (UART0 TX) | ✅ SAFE |
| **D7** | GPIO 44 | Available (UART0 RX) | ✅ SAFE |
| **D8 / A8** | GPIO 7 | **Internal SPI SCK** (Shared with LoRa) | ⚠️ SHARED |
| **D9 / A9** | GPIO 8 | **Internal SPI MISO** (Shared with LoRa) | ⚠️ SHARED |
| **D10 / A10** | GPIO 9 | **Internal SPI MOSI** (Shared with LoRa) | ⚠️ SHARED |
| **N/A** | GPIO 41 | **LoRa NSS** (Chip Select - Internal) | 🔒 BUSY |
| **N/A** | GPIO 42 | **LoRa BUSY** (Internal) | 🔒 BUSY ||





## If trying to use the xiaoML kit IMU and OLED module


| Pin Label | GPIO | Hardware Conflict | Status |
| :--- | :--- | :--- | :--- |
| **D0 / A0** | GPIO 1 | None | ✅ SAFE |
| **D1 / A1** | GPIO 2 | None | ✅ SAFE |
| **D2 / A2** | GPIO 3 | Strapping Pin | ✅ SAFE |
| **D3 / A3** | GPIO 4 | **Buzzer / User Button** (Expansion Board) | ⚠️ SHARED |
| **D4 / A4** | GPIO 5 | **I2C SDA** (OLED & IMU) | ⚠️ SHARED |
| **D5 / A5** | GPIO 6 | **I2C SCL** (OLED & IMU) | ⚠️ SHARED |
| **D6** | GPIO 43 | None | ✅ SAFE |
| **D7** | GPIO 44 | None | ✅ SAFE |
| **D8 / A8** | GPIO 7 | **SPI SCK** (LoRa & SD Card) | 🔒 BUSY |
| **D9 / A9** | GPIO 8 | **SPI MISO** (LoRa & SD Card) | 🔒 BUSY |
| **D10 / A10** | GPIO 9 | **SPI MOSI** (LoRa) / **SD CS** (SD Card) | 🔒 BUSY |
| **N/A** | GPIO 21 | **User LED** (XIAO) | 🔒 BUSY |
| **N/A** | GPIO 41 | **LoRa NSS** (Internal B2B) | 🔒 BUSY |

