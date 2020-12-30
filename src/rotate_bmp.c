#include "rotate_bmp.h"

struct image rotate(struct image const source)
{
	struct image source2;
	source2.width = source.height;
	source2.height = source.width;
	uint64_t w = source.width;
	uint64_t h = source.height;
	uint64_t w2 = w%4? w+(4-w%4): w;
	uint64_t h2 = h%4? h+(4-h%4): h;

	struct pixel buffer[h*w2*2];
	source2.data = buffer;


	for (uint64_t height = 0; height < h; ++height)
		for (uint64_t width = 0; width < w; ++width)
			source2.data[(h-height-1)+h*width] = source.data[w2 * height + width];
	return source2;
};