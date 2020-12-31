#include <stdio.h>

#include "bmp.h"
#include "util.h"
#include "read_bmp.h"
#include "rotate_bmp.h"
#include "write_bmp.h"

void usage() {
	fprintf(stderr, "Usage: ./print_header BMP_FILE_NAME\n");
}

int main( int argc, char** argv ) {
	if (argc != 2) usage();
	if (argc < 2) err("Not enough arguments \n" );
	if (argc > 2) err("Too many arguments \n" );

	struct bmp_header h = { 0 };
	struct image img;
	if (read_header_from_file( argv[1], &h )) {
		bmp_header_print( &h, stdout );

		FILE* f_in = fopen( argv[1], "rb" );
		FILE* f_out = fopen( "../images/image2.bmp", "wb" );

		img.height = h.biHeight;
		img.width = h.biWidth;

		if(from_bmp(f_in, &img) != READ_OK)
			return 1;

		h.biHeight = img.width;
		h.biWidth = img.height;
		img = rotate(img);

		fwrite(&h, sizeof(struct bmp_header), 1, f_out);
		if(to_bmp(f_out, &img) != WRITE_OK)
			return 1;
	}
	else {
		err( "Failed to open BMP file or reading header.\n" );
	}

	return 0;
}