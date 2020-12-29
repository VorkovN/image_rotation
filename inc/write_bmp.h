#ifndef WRITE_BMP_H
#define WRITE_BMP_H

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include "bmp.h"

enum  write_status  {
	WRITE_OK = 0,
	WRITE_ERROR
	/* коды других ошибок  */
};
/*  serializer   */
enum write_status to_bmp( FILE* out, struct image const* img );


#endif //WRITE_BMP_H
