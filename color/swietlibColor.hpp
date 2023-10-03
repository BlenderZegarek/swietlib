#ifndef INC_SWIETLIBCOLOR_HPP_
#define INC_SWIETLIBCOLOR_HPP_

#include <cstdint>

namespace swietlib {

	struct rgbColor;
	struct hsvColor;

	struct rgbColor {
		 rgbColor(uint8_t r, uint8_t g, uint8_t b) : red(r), green(g), blue(b) {};
		 uint8_t red, green, blue;
		 hsvColor toHSV();
	};

	struct hsvColor {
		hsvColor(uint16_t h, uint8_t s, uint8_t v) : hue(h), saturation(s), value(v) {};
		uint16_t hue;
		uint8_t saturation, value;
		rgbColor toRGB();
	};

}

#endif /* INC_SWIETLIBCOLOR_HPP_ */
