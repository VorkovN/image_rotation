#include "rotate_bmp.h"

struct image rotate(struct image const source)
{
	struct image source2;
	source2.width = source.height;
	source2.height = source.width;
	uint64_t w = source.width;
	uint64_t h = source.height;
	uint64_t w2 = (3 * w + 3) & (-4);    // Compute row width in file, including padding to 4-byte boundary
	uint64_t h2 = (3 * h + 3) & (-4);

	struct pixel buffer[h2*w2];
	source2.data = buffer;


	for (uint64_t height = 0; height < h; ++height)
		for (uint64_t width = 0; width < w; ++width)
			source2.data[(h-height-1)+h*width] = source.data[w * height + width];
	return source2;
};