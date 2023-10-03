#ifndef INC_SWIETLIB_HPP_
#define INC_SWIETLIB_HPP_

#include "spi.h"
#include "swietlibColor.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

namespace swietlib {

	class strip {
	public:
		strip(SPI_HandleTypeDef *spiHandler, uint16_t ledCount);
		virtual ~strip();

		void refresh();
		void refreshOffset(uint16_t offset);

		void setPixel(uint16_t diodeId, rgbColor color);
		void setPixel(uint16_t diodeId, uint8_t, uint8_t g, uint8_t b);

		void fill(rgbColor color);
		void fill(rgbColor color, uint16_t start, uint16_t end);
		void fill(uint8_t r, uint8_t g, uint8_t b, uint16_t start, uint16_t end);
		void fill(uint8_t r, uint8_t g, uint8_t b);
		void clear();

		void setBrightness(uint8_t brightness);

		uint8_t getBrightness();
		uint16_t getLedCount();

	private:
		SPI_HandleTypeDef *spiHandler;
		uint16_t ledCount;
		rgbColor *colorsArray;
		uint8_t *buffer;
		uint8_t brightness;
	};

}

#ifdef __cplusplus
}
#endif

#endif /* INC_SWIETLIB_HPP_ */
