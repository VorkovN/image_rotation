#include "write_bmp.h"

enum write_status to_bmp(FILE *out, struct image const *img)
{
	const uint64_t w = img->width;
	const uint64_t h = img->height;
	const uint64_t pw = (w * 3) % 4 ? 4 - (w * 3) % 4 : 0;

	for (uint64_t height = 0; height < h; ++height) {
		for (uint64_t width = 0; width < w; ++width)
			fwrite(img->data+(w * height + width), sizeof(struct pixel), 1, out);
		fwrite("0", sizeof(uint8_t), pw, out);
	}

	return WRITE_OK;
}
