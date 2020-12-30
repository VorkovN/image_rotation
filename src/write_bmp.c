#include "write_bmp.h"

enum write_status to_bmp( FILE* out, struct image const* img )
{
	int w = img->width;
	int h = img->height;
	uint64_t w2 = w%4? w+(4-w%4): w;
	uint64_t h2 = h%4? h+(4-h%4): h;
	fwrite(img->data, sizeof(struct pixel), w2 * h, out);
	printf("\n");

	return WRITE_OK;
}