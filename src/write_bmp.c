#include "write_bmp.h"

enum write_status to_bmp( FILE* out, struct image const* img )
{
	int w = img->width;
	int h = img->height;
	int w2 = (3 * w + 3) & (-4);    // Compute row width in file, including padding to 4-byte boundary
	fwrite(img->data, sizeof(struct pixel), w2 * h, out);
	printf("\n");

	return WRITE_OK;
}