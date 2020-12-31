#include "read_bmp.h"

enum read_status from_bmp(FILE *in, struct image *img)
{
	uint64_t w = img->width;
	uint64_t h = img->height;
	uint64_t pw = (w * 3) % 4 ? 4 - (w * 3) % 4 : 0;
	struct pixel buffer[h*w];
	//int8_t filler = 0;
	fseek(in, sizeof(struct bmp_header), SEEK_CUR);
	//fread(buffer, sizeof(struct pixel), w * h, in);
	for (uint64_t height = 0; height < h; ++height) {
		for (uint64_t width = 0; width < w; ++width)
			fread(buffer+(w * height + width), sizeof(struct pixel), 1, in);
		fseek(in, pw, SEEK_CUR);
	}
	int c = sizeof (buffer)/sizeof (uint8_t);
	img->data = buffer;
	return READ_OK;
}
