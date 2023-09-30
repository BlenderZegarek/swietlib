#include "swietlib.hpp"
#include <cstdlib>
#include "spi.h"
#include <stdio.h>

namespace swietlib {

strip::strip(SPI_HandleTypeDef *spiHandler, uint16_t ledCount) {
	this->spiHandler = spiHandler;
	this->ledCount = ledCount;
	this->colorsArray = (rgbColor_t*)calloc(this->ledCount, sizeof(rgbColor_t));
	this->buffer = (uint8_t*)calloc(ledCount, 24);
	this->brightness = 255;
}

strip::~strip() {
	free(this->colorsArray);
	free(this->buffer);
}

void strip::refreshOffset(uint16_t offset) {

	const uint8_t zero = 0b00011111;
 	const uint8_t one = 0b00000111;

 	uint8_t r, g, b;

 	uint16_t idx;

 	for (uint16_t i = this->ledCount, j = 0; i > 0; i--) {

 		idx = ((i + offset) % this->ledCount);

 		r = this->colorsArray[idx].red * this->brightness / 256;
 		g = this->colorsArray[idx].green * this->brightness / 256;
 		b = this->colorsArray[idx].blue * this->brightness / 256;

		// Red
		for (int16_t k = 7; k >= 0; k--) {
			if ((r & (1 << k)) == 0) this->buffer[j] = one;
			else this->buffer[j] = zero;
			j++;
		}

		// Green
		for (int16_t k = 7; k >= 0; k--) {
			if ((g & (1 << k)) == 0) this->buffer[j] = one;
			else this->buffer[j] = zero;
			j++;
		}

		// Blue
		for (int16_t k = 7; k >= 0; k--) {
			if ((b & (1 << k)) == 0) this->buffer[j] = one;
			else this->buffer[j] = zero;
			j++;
		}

	}

 	HAL_SPI_Transmit(this->spiHandler, buffer, this->ledCount * 24, 1000);
}

void strip::refresh() {
	this->refreshOffset(0);
}

void strip::setPixel(uint16_t diodeId, rgbColor_t color) {
	this->colorsArray[diodeId] = color;
}

void strip::setPixel(uint16_t diodeId, uint8_t r, uint8_t g, uint8_t b) {
	this->setPixel(diodeId, this->rgbColor(r, g, b));
}

void strip::fill(rgbColor_t color, uint16_t start, uint16_t end) {
	for(uint16_t i = start; i<=end; i++)
		this->setPixel(i, color);
}

void strip::fill(uint8_t r, uint8_t g, uint8_t b, uint16_t start, uint16_t end) {
	this->fill(this->rgbColor(r, g, b), start, end);
}

void strip::fill(rgbColor_t color) {
	this->fill(color, 0, this->ledCount);
}

void strip::fill(uint8_t r, uint8_t g, uint8_t b) {
	this->fill(this->rgbColor(r, g, b));
}

void strip::clear() {
	this->fill(0, 0, 0);
}

void strip::setBrightness(uint8_t brightness) {
	this->brightness = brightness;
}

uint8_t strip::getBrightness() {
	return this->brightness;
}

uint16_t strip::getLedCount() {
	return this->ledCount;
}

rgbColor_t strip::rgbColor(uint8_t r, uint8_t g, uint8_t b) {
	rgbColor_t color;
	color.red = r;
	color.green = g;
	color.blue = b;
	return color;
}

hsvColor_t strip::hsvColor(uint8_t h, uint8_t s, uint8_t v) {
	hsvColor_t color;
	color.hue = h;
	color.saturation = s;
	color.value = v;
	return color;
}

}
