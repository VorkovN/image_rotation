#include "write_bmp.h"

enum write_status to_bmp(FILE *out, struct image const *img)
{
	uint64_t w = img->width;
	uint64_t h = img->height;
	uint64_t pw = (w * 3) % 4 ? 4 - (w * 3) % 4 : 0;
	int8_t filler = 0;
	for (uint64_t height = 0; height < h; ++height) {
		for (uint64_t width = 0; width < w; ++width)
			fwrite(img->data+(w * height + width), sizeof(struct pixel), 1, out);
		fwrite(&filler, sizeof(uint8_t), pw, out);
	}
	fclose(out);

	return WRITE_OK;
}

//#include "write_bmp.h"
//
//enum write_status to_bmp( FILE* out, struct image const* img )
//{
//	uint64_t w = img->width;
//	uint64_t h = img->height;
//	uint64_t pw = (w * 3) % 4 ? 4 - (w * 3) % 4 : 0;
//	fwrite(img->data, sizeof(struct pixel), (w+pw) * h, out);
//
//	return WRITE_OK;
//}