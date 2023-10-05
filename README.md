<div align="center">
  <img src="https://raw.githubusercontent.com/BlenderZegarek/swietlib/main/title.png" alt="Logo" width="100%">
  <b>STM32 library for WS28xx LED control.</b>

  ------
  
  ![GitHub last commit (branch)](https://img.shields.io/github/last-commit/blenderzegarek/swietlib/main)
  ![STM32](https://img.shields.io/badge/STM32-blue)
  ![GitHub top language](https://img.shields.io/github/languages/top/blenderzegarek/swietlib)
  ![GitHub Repo stars](https://img.shields.io/github/stars/blenderzegarek/swietlib)
  ![WS281x](https://img.shields.io/badge/WS281x-purple)

</div>

![a](http://eryk.terebecki.pl/licznik)

# 👋 Introduction

### Features
- **WS281x** led control
- **HSV to RGB** and **RGB to HSV**
- **Filling** and **Clearing**
- **Brightness** control
  
### Compatibility with Boards
Currently, the library is available and tested for **STM32F4** microcontrollers, but it may also be compatible with other STM32 microcontrollers.

### Compatibility with LEDs
The library has been tested with **WS2815** and **WS2812** LEDs. It is highly likely to also work with **WS2813** and **WS2812B**, or similar variants. It might not work with **WS2811** LEDs.

### Performance
In testing, the library demonstrated a refresh rate of approximately **19.5 LEDs per millisecond**.



# ⚙️ Required Settings

### Clock Configuration
You need to change clock speed for **HCLK to 51.2MHz**.
<details><summary><b>Clock config screenshot</b></summary>

![Clock config screenshot](https://raw.githubusercontent.com/BlenderZegarek/swietlib/main/clock_configuration.png)
(click to zoom)

</details>

### SPI Settings
First, enable SPI you want and set settings to:

These are tested settings, I encourage you to experiment with them.

<details><summary><b>SPI Settings Screenshot</b></summary>
  
![SPI Settings](https://raw.githubusercontent.com/BlenderZegarek/swietlib/main/spi_settings.png)

</details>


# 🔌 Connection
Connect the strip control pin to the pin described as **SPIx_MOSI** in the pinout view.



# 💽 Installation
To install simply choose version for your CPU and insert the library among your other program files.
**Also install the files from the `color` folder.**


# 🖥️ Basic Usage

### Making Object
To use this library, create an object of the class **strip** from the **swietlib** namespace:
```cpp
swietlib::strip ledstrip(&hspi2, 120);
```
Replace `&hspi2` with a reference to the SPI handler you have chosen.
**(Remember to include `spi.h`)**

### Changing LED Color
Set LEDs color with this:
```cpp
ledstrip.setPixel(10, swietlib::rgbColor(255, 128, 0));
```
or
```cpp
ledstrip.setPixel(10, 255, 128, 0);
```
First argument means which LED in turn to change color, 

### Filling, Clearing
To clear the strip use:
```cpp
ledstrip.clear();
```

To fill all the strip use:
```cpp
ledstrip.fill(255, 128, 0);
```

### Refreshing
To refresh strip (send data to strip) you need to use:
```cpp
ledstrip.refresh();
```

**More info you can find [there](https://github.com/BlenderZegarek/swietlib/blob/main/USAGE.md).**

# 💡 Examples

### Rainbow
Simple moving rainbow effect using this library.
```cpp
#include <cstdint>
#include "swietlib.hpp"
#include "swietlibColor.hpp"
#include "stm32f4xx.h"
#include "spi.h"

#define LED_COUNT 120

...

swietlib::strip ledstrip(&hspi2, LED_COUNT);

// Change it to modify the density of the rainbow                              ↓↓↓
for (uint16_t hue = 0, i = 0; i <= LED_COUNT; i++, hue += (65535 / (LED_COUNT / 2))) {
    ledstrip.setPixel(i, swietlib::hsvColor(hue, 255, 255).toRGB());
}

ledstrip.setBrightness(64);

uint16_t offset = 1;
while (1) {
    ledstrip.refreshOffset(offset);
    HAL_Delay(20);
    if (offset >= LED_COUNT) offset = 0;
    offset++;
}
```
