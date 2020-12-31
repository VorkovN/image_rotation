#include "read_bmp.h"

enum read_status from_bmp(FILE *in, struct image *img, struct bmp_header *header)
{
	if(header->bOffBits != sizeof(struct bmp_header))
	{
		printf("Invalid size of header");
		return READ_INVALID_HEADER;
	}

	if(header->biBitCount != 24){
		printf("Invalid count of bits for one pixel");
		return READ_INVALID_BITS;
	}


	const size_t w = header->biWidth;
	const size_t h = header->biHeight;
	const size_t padding = (w * 3) % 4 ? 4 - (w * 3) % 4 : 0;
	img->width = w;
	img->height = h;

	struct pixel buffer[h * w];

	size_t char_count = 0;

	fseek(in, header->bOffBits, SEEK_CUR);
	for (size_t height = 0; height < h; ++height) {
		for (size_t width = 0; width < w; ++width)
			char_count += fread(buffer + (w * height + width), sizeof(struct pixel), 1, in);
		fseek(in, padding, SEEK_CUR);
	}

	if (char_count != w * h)
	{
		printf("More read objects were expected");
		return READ_INVALID_OBJECTS_COUNT;
	}

	img->data = buffer;
	return READ_OK;
}
