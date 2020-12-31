#include "write_bmp.h"

enum write_status to_bmp(FILE *out, struct image const *img)
{
	const uint64_t w = img->width;
	const uint64_t h = img->height;
	const uint64_t pw = (w * 3) % 4 ? 4 - (w * 3) % 4 : 0;

	uint64_t char_count = 0;

	for (uint64_t height = 0; height < h; ++height) {
		for (uint64_t width = 0; width < w; ++width)
			char_count += fwrite(img->data + (w * height + width), sizeof(struct pixel), 1, out);
		char_count += fwrite("0", sizeof(uint8_t), pw, out);
	}

	if (char_count == (w + pw) * h)
		return WRITE_OK;
	printf("More written objects were expected");
	return WRITE_ERROR;
}
