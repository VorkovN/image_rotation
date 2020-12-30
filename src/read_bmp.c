#include "read_bmp.h"

enum read_status from_bmp(FILE *in, struct image *img)
{
	uint64_t w = img->width;
	uint64_t h = img->height;
	uint64_t w2 = w%4? w+(4-w%4): w;
	uint64_t h2 = h%4? h+(4-h%4): h;
	struct pixel buffer[h*w2];
	fseek(in, sizeof(struct bmp_header), 0);
	fread(buffer, sizeof(struct pixel), w2 * h, in);
	img->data = buffer;
	return READ_OK;
}
