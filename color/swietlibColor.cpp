#include <swietlibColor.hpp>

namespace swietlib {

	rgbColor hsvColor::toRGB() {
		rgbColor result = {0, 0, 0};

	    int f = (this->hue % 60) * 255 / 60;
	    int p = (this->value * (255 - this->saturation)) / 255;
	    int q = (this->value * (255 - (this->saturation * f) / 255)) / 255;
	    int t = (this->value * (255 - (this->saturation * (255 - f)) / 255)) / 255;

	    switch (this->hue / 60) {
	        case 0: result.red = this->value; result.green = t; 		  result.blue = p; 			 break;
	        case 1: result.red = q; 		  result.green = this->value; result.blue = p; 		   	 break;
	        case 2: result.red = p; 		  result.green = this->value; result.blue = t; 		 	 break;
	        case 3: result.red = p; 		  result.green = q; 		  result.blue = this->value; break;
	        case 4: result.red = t; 		  result.green = p; 		  result.blue = this->value; break;
	        case 5: result.red = this->value; result.green = p; 		  result.blue = q; 			 break;
	    }

	    return result;
	}

	inline uint16_t _min(uint16_t a, uint16_t b) { return a < b ? a : b; }
	inline uint16_t _max(uint16_t a, uint16_t b) { return a > b ? a : b; }
	hsvColor rgbColor::toHSV() {
		hsvColor result = {0, 0, 0};

		uint16_t max_color = _max(this->red, _max(this->green, this->blue));
		uint16_t min_color = _min(this->red, _min(this->green, this->blue));

		result.value = (max_color * 255) / 255; // Scaling to [0, 255]

		if (max_color == 0) {
			result.saturation = 0;
		} else {
			result.saturation = ((max_color - min_color) * 255) / max_color;
		}

		if (result.saturation == 0) {
			result.hue = 0;
		} else {
			if (max_color == this->red) {
				result.hue = (60 * (this->green - this->blue)) / (max_color - min_color);
			} else if (max_color == this->green) {
				result.hue = 120 + (60 * (this->blue - this->red)) / (max_color - min_color);
			} else {
				result.hue = 240 + (60 * (this->red - this->green)) / (max_color - min_color);
			}
		}

		if (result.hue < 0) {
			result.hue += 360;
		}

		return result;
	}

}
