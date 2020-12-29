#include "rotate_bmp.h"

struct image rotate( struct image const source )
{
	struct image source2;
	int w = source.width;
	int h = source.height;
	int w2 = (3 * w + 3) & (-4);    // Compute row width in file, including padding to 4-byte boundary
	source2.width = source.height;
	source2.height = source.width;
	struct pixel buffer[h*w];
	source2.data = buffer;
	for (size_t height = 0; height < h; ++height) {
		for (size_t width = 0; width < w; ++width) {
			source2.data[height*w+width] = source.data[width*h+height];
		}
	}
	return source2;
};