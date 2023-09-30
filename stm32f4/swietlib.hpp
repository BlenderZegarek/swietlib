#ifndef INC_SWIETLIB_HPP_
#define INC_SWIETLIB_HPP_

#include "spi.h"

#ifdef __cplusplus
extern "C"
{
#endif

namespace swietlib {

	typedef struct rgbColor_t {
		 uint8_t red, green, blue;
	} rgbColor_t;

	typedef struct hsvColor_t {
		uint8_t hue, saturation, value;
	} hsvColor_t;

	class strip {
	public:
		strip(SPI_HandleTypeDef *spiHandler, uint16_t ledCount);
		virtual ~strip();

		void refresh();
		void refreshOffset(uint16_t offset);

		void setPixel(uint16_t diodeId, rgbColor_t color);
		void setPixel(uint16_t diodeId, uint8_t r, uint8_t g, uint8_t b);

		void fill(rgbColor_t color);
		void fill(rgbColor_t color, uint16_t start, uint16_t end);
		void fill(uint8_t r, uint8_t g, uint8_t b, uint16_t start, uint16_t end);
		void fill(uint8_t r, uint8_t g, uint8_t b);
		void clear();

		void setBrightness(uint8_t brightness);

		uint8_t getBrightness();
		uint16_t getLedCount();

		rgbColor_t rgbColor(uint8_t r, uint8_t g, uint8_t b);
		hsvColor_t hsvColor(uint8_t h, uint8_t s, uint8_t v);
	private:
		SPI_HandleTypeDef *spiHandler;
		uint16_t ledCount;
		rgbColor_t *colorsArray;
		uint8_t *buffer;
		uint8_t brightness;
	};

}

#ifdef __cplusplus
}
#endif

#endif /* INC_SWIETLIB_HPP_ */
