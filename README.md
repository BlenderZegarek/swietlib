<div align="center">
  <h1>SwietLib</h1>
  <p>STM32 library for WS28xx LED control.</p>
</div>



# 👋 Introduction

### Compatibility with Boards
Currently, the library is available and tested for STM32F4 microcontrollers, but it may also be compatible with other STM32 microcontrollers.

### Compatibility with LEDs
The library has been tested with WS2815 and WS2812 LEDs. It is highly likely to also work with WS2813 and WS2812B, or similar variants. It might not work with WS2811 LEDs.

### Performance
In testing, the library demonstrated a refresh rate of approximately **19.5 LEDs per millisecond**.



# ⚙️ Required Settings

### Clock Configuration
You need to change clock speed for HCLK to 51.2MHz,
[like here](https://raw.githubusercontent.com/BlenderZegarek/swietlib/main/clock_configuration.png).

### SPI Settings
First, enable SPI you want and set settings to:

These are tested settings, I encourage you to experiment with them.

![SPI Settings](https://raw.githubusercontent.com/BlenderZegarek/swietlib/main/spi_settings.png)



# 🔌 Connection
Connect the strip control pin to the pin described as SPIx_MOSI in the pinout view.



# 💽 Installation
Lorem ipsum


# 🖥️ Usage
Lorem ipsum


# 💡 Examples
Lorem ipsum
