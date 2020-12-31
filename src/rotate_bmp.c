#include "rotate_bmp.h"

struct image rotate(struct image const source, struct bmp_header *header)
{
	struct image source2;

	const uint64_t w = source.width;
	const uint64_t h = source.height;
	header->biHeight = w;
	header->biWidth = h;
	source2.height = w;
	source2.width = h;

	struct pixel buffer[h * w * 2];

	for (uint64_t height = 0; height < h; ++height)
		for (uint64_t width = 0; width < w; ++width)
			buffer[(h - 1 - height) + h * width] = source.data[w * height + width];

	source2.data = buffer;

	return source2;
}