#include "rotate_bmp.h"

struct image rotate( struct image const source )
{
	struct image source2;
	int mx = source.width;
	int my = source.height;
	source2.width = source.width;
	source2.height = source.height;
	struct pixel buffer[my*mx];
	source2.data = buffer;
	for (size_t height = 0; height < my; ++height) {
		for (size_t width = 0; width < mx; ++width) {
			source2.data[height*mx+width] = source.data[width*my+height];
		}
		printf("\n");
	}
	return source2;
};