<div align="center">
  <h1>Usage</h1>
  <p>This file contains descriptions of functions available in the SwietLib library. Each function is described in terms of its functionality, input parameters, return values, and includes an example usage.</p>
</div>

<br>

# `strip` class
### `strip(SPI_HandleTypeDef *spiHandler, uint16_t ledCount);` (constructor)
This is constructor for strip object. It's taking the SPI handler reference (`SPI_HandleTypeDef`) and the number of LEDs (`uint16_t`) as arguments. Initializes the object and allocates memory.

------

### `void object.setPixel(uint16_t diodeId, rgbColor_t);`
Sets the pixel in `colorsArray` to provided color (`rgbColor_t`).

------

### `void object.setPixel(uint16_t diodeId, uint8_t r, uint8_t g, uint8_t b);`
Sets the pixel in `colorsArray` to provided values of color (3x `uint8_t`).

------

### `void object.fill(rgbColor_t color);`
Fills the entire strip to provided color (`rgbColor_t`).

------

### `void object.fill(uint8_t r, uint8_t g, uint8_t b);`
Fills the entire strip to provided values of color (3x `uint8_t`).

------

### `void object.fill(rgbColor_t color, uint16_t start, uint16_t end);`
Fills the given part of strip (start and end `uint16_t`) to provided color (`rgbColor_t`).

------

### `void object.fill(uint8_t r, uint8_t g, uint8_t b, uint16_t start, uint16_t end);`
Fills the given part of strip (start and end `uint16_t`) to provided values of color (3x `uint8_t`).

------

### `void object.clear();`
Fills the strip with black (#000000) color.

------

### `void object.setBrightness(uint8_t);`
Sets the brightness of strip.

------

### `uint8_t object.getBrightness();`
Gets the private brightness variable.

------

### `uint16_t object.getLedCount()`
Gets the count of leds set in constructor.

------
------

# Colors
## struct rgbColor
Lorem ipsum

## struct hsvColor
Lorem ipsum
