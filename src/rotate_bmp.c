#include "rotate_bmp.h"

struct image rotate(struct image const source)
{
	struct image source2;
	source2.width = source.height;
	source2.height = source.width;
	//source2.width = source.width;
	//source2.height = source.height;
	uint64_t w = source.width;
	uint64_t h = source.height;
	uint64_t pw = (w * 3) % 4 ? 4 - (w * 3) % 4 : 0;

	struct pixel buffer[h * w * 2];


	for (uint64_t height = 0; height < h; ++height)
		for (uint64_t width = 0; width < w; ++width)
			buffer[(h - 1 - height) + h * width] = source.data[w * height + width];
	source2.data = buffer;
	int c = sizeof(buffer) / sizeof(uint8_t);
	return source2;
}