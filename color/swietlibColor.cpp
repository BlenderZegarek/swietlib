#include <swietlibColor.hpp>

namespace swietlib {

	rgbColor hsvColor::toRGB() {
		rgbColor result = {0, 0, 0};

	    int f = (this->hue % 10922) * 255 / 10922;
	    int p = (this->value * (255 - this->saturation)) / 255;
	    int q = (this->value * (255 - (this->saturation * f) / 255)) / 255;
	    int t = (this->value * (255 - (this->saturation * (255 - f)) / 255)) / 255;

	    switch (this->hue / 10922) {
	        case 0: result.red = this->value; result.green = t;           result.blue = p; 	         break;
	        case 1: result.red = q;           result.green = this->value; result.blue = p;           break;
	        case 2: result.red = p;           result.green = this->value; result.blue = t; 	         break;
	        case 3: result.red = p;           result.green = q;           result.blue = this->value; break;
	        case 4: result.red = t;           result.green = p;           result.blue = this->value; break;
	        case 5: result.red = this->value; result.green = p;           result.blue = q; 	         break;
	    }

	    return result;
	}

	inline uint16_t _min(uint16_t a, uint16_t b) { return a < b ? a : b; }
	inline uint16_t _max(uint16_t a, uint16_t b) { return a > b ? a : b; }
	hsvColor rgbColor::toHSV() {
		hsvColor result = {0, 0, 0};
		int32_t calc = 0;

		uint16_t max_color = _max(this->red, _max(this->green, this->blue));
		uint16_t min_color = _min(this->red, _min(this->green, this->blue));

		result.value = (max_color * 255) / 255; // Scaling to [0, 255]

		if (max_color == 0) {
			result.saturation = 0;
		} else {
			result.saturation = ((max_color - min_color) * 255) / max_color;
		}

		if (result.saturation == 0) {
			calc = 0;
		} else {
			if (max_color == this->red) {
				calc = (10922 * (this->green - this->blue)) / (max_color - min_color);
			} else if (max_color == this->green) {
				calc = 21845 + (10922 * (this->blue - this->red)) / (max_color - min_color);
			} else {
				calc = 43690 + (10922 * (this->red - this->green)) / (max_color - min_color);
			}
		}

		if (calc < 0) {
			calc += 65535;
		}

		result.hue = calc;

		return result;
	}

}
