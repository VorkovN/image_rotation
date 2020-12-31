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


	const uint64_t w = header->biWidth;
	const uint64_t h = header->biHeight;
	img->width = w;
	img->height = h;
	const uint64_t pw = (w * 3) % 4 ? 4 - (w * 3) % 4 : 0;

	struct pixel buffer[h * w];

	uint64_t char_count = 0;

	fseek(in, header->bOffBits, SEEK_CUR);
	for (uint64_t height = 0; height < h; ++height) {
		for (uint64_t width = 0; width < w; ++width)
			char_count += fread(buffer + (w * height + width), sizeof(struct pixel), 1, in);
		fseek(in, pw, SEEK_CUR);
	}

	if (char_count != w * h)
	{
		printf("More read objects were expected");
		return READ_INVALID_OBJECTS_COUNT;
	}

	img->data = buffer;
	return READ_OK;
}
