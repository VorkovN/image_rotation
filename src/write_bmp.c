#include "write_bmp.h"

enum write_status to_bmp( FILE* out, struct image const* img )
{
	int mx = img->width;
	int my = img->height;
	fwrite(img->data, sizeof(struct pixel), mx * my, out);
	printf("\n");
	for (size_t height = 0; height < my; ++height) {
		for (size_t width = 0; width < mx; ++width) {
			printf("%" PRIu8, img->data[height*mx+width].b);
			printf("%" PRIu8, img->data[height*mx+width].g);
			printf("%" PRIu8 " ", img->data[height*mx+width].r);
		}
		printf("\n");
	}

	return WRITE_OK;
}