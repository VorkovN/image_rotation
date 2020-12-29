#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

struct pixel { uint8_t b, g, r; };

struct image {
	uint64_t width, height;
	struct pixel* data;
};

enum read_status  {
	READ_OK = 0,
	READ_INVALID_SIGNATURE,
	READ_INVALID_BITS,
	READ_INVALID_HEADER
	/* коды других ошибок  */
};
enum read_status from_bmp( FILE* in, struct image* img );
/*  serializer   */
enum  write_status  {
	WRITE_OK = 0,
	WRITE_ERROR
	/* коды других ошибок  */
};
/*  serializer   */
enum write_status to_bmp( FILE* out, struct image const* img );

/* создаёт копию изображения, которая повёрнута на 90 градусов */
struct image rotate( struct image const source );


#endif //IMAGE_H
