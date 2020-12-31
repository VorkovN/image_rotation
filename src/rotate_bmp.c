#include "rotate_bmp.h"

struct image rotate(struct image const source, struct bmp_header *header)
{
	struct image source2;

	const size_t w = source.width;
	const size_t h = source.height;
	header->biHeight = w;
	header->biWidth = h;
	source2.height = w;
	source2.width = h;

	struct pixel buffer[h * w * 2];

	for (size_t height = 0; height < h; ++height)
		for (size_t width = 0; width < w; ++width)
			buffer[(h - 1 - height) + h * width] = source.data[w * height + width];

	source2.data = buffer;

	return source2;
}