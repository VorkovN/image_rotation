#include "read_bmp.h"

enum read_status from_bmp(FILE *in, struct image *img, struct bmp_header *header)
{
	const uint64_t w = header->biWidth;
	const uint64_t h = header->biHeight;
	img->width = w;
	img->height = h;
	const uint64_t pw = (w * 3) % 4 ? 4 - (w * 3) % 4 : 0;

	struct pixel buffer[h * w];

	fseek(in, sizeof(struct bmp_header), SEEK_CUR);
	for (uint64_t height = 0; height < h; ++height) {
		for (uint64_t width = 0; width < w; ++width)
			fread(buffer + (w * height + width), sizeof(struct pixel), 1, in);
		fseek(in, pw, SEEK_CUR);
	}

	img->data = buffer;

	return READ_OK;
}
