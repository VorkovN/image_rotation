#include "read_bmp.h"

enum read_status from_bmp(FILE *in, struct image *img)
{
	uint64_t w = img->width;
	uint64_t h = img->height;
	uint64_t w2 = (3 * w + 3) & (-4);    // Compute row width in file, including padding to 4-byte boundary
	//int h2 = (3 * h + 3) & (-4);
	struct pixel buffer[h*w2];
	fseek(in, sizeof(struct bmp_header), 0);
	fread(buffer, sizeof(struct pixel), w2 * h, in);
	img->data = buffer;
	return READ_OK;
}
