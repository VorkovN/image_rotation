#ifndef READ_BMP_H
#define READ_BMP_H

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include "bmp.h"

enum read_status  {
	READ_OK = 0,
	READ_INVALID_SIGNATURE,
	READ_INVALID_BITS,
	READ_INVALID_HEADER
	/* коды других ошибок  */
};
enum read_status from_bmp( FILE* in, struct image* img, struct bmp_header *header);
/*  serializer   */

#endif //READ_BMP_H
