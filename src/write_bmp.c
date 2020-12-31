#include "write_bmp.h"

enum write_status to_bmp(FILE *out, struct image const *img, struct bmp_header *header)
{
	fwrite(header, sizeof(struct bmp_header), 1, out);

	const size_t w = img->width;
	const size_t h = img->height;
	const size_t padding = (w * 3) % 4 ? 4 - (w * 3) % 4 : 0;

	size_t char_count = 0;

	for (size_t height = 0; height < h; ++height) {
		for (size_t width = 0; width < w; ++width)
			char_count += fwrite(img->data + (w * height + width), sizeof(struct pixel), 1, out);
		char_count += fwrite("0", sizeof(uint8_t), padding, out);
	}

	if (char_count == (w + padding) * h)
		return WRITE_OK;
	printf("More written objects were expected");
	return WRITE_ERROR;
}
