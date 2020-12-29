#include "image.h"

enum read_status from_bmp(FILE *in, struct image *img)
{
	int mx = img->width;
	int my = img->height;
	int mx3 = (3 * mx + 3) & (-4);    // Compute row width in file, including padding to 4-byte boundary
	struct pixel **buffer = (struct pixel **)malloc(sizeof(struct pixel *) * my);  // читаем данные //todo mx3
	for (size_t height = 0; height < my; ++height) {
		buffer[height] = (struct pixel *)malloc(sizeof(struct pixel) * mx);
	}
	fread(buffer, sizeof(struct pixel), mx * my, in);
	for (size_t height = 0; height < my; ++height) {
		struct pixel *string = malloc(sizeof(struct pixel) * mx);
		for (size_t width = 0; width < mx; ++width) {
			//fread(&pixel, sizeof(struct pixel), 1, in);
			//img[i][j] = pixel;
			struct pixel t = buffer[height][width];
			printf("%" PRIu8, buffer[height][width].b);
			printf("%" PRIu8, buffer[height][width].g);
			printf("%" PRIu8 " ", buffer[height][width].r);
		}
		printf("\n");
	}


}