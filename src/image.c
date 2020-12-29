#include "image.h"

enum read_status from_bmp(FILE *in, struct image *img)
{
	int mx = img->width;
	int my = img->height;
	int mx3 = (3 * mx + 3) & (-4);    // Compute row width in file, including padding to 4-byte boundary
	struct pixel buffer[my*mx];
	fseek(in, 18*3, 0);
	fread(buffer, sizeof(struct pixel), mx * my, in);
	for (size_t height = 0; height < my; ++height) {
		struct pixel *string = malloc(sizeof(struct pixel) * mx);
		for (size_t width = 0; width < mx; ++width) {
			//fread(&pixel, sizeof(struct pixel), 1, in);
			//img[i][j] = pixel;
			printf("%" PRIu8, buffer[height*mx+width].b);
			printf("%" PRIu8, buffer[height*mx+width].g);
			printf("%" PRIu8 " ", buffer[height*mx+width].r);
		}
		printf("\n");
	}
	img->data = buffer;

}