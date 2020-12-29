#include <stdbool.h>
#include <stdio.h>

#include "bmp.h"
#include "util.h"
#include "image.h"


void usage() {
	fprintf(stderr, "Usage: ./print_header BMP_FILE_NAME\n");
}

int main( int argc, char** argv ) {
	if (argc != 2) usage();
	if (argc < 2) err("Not enough arguments \n" );
	if (argc > 2) err("Too many arguments \n" );

	struct bmp_header h = { 0 };
	struct image img = { 0 };
	if (read_header_from_file( argv[1], &h )) {
		bmp_header_print( &h, stdout );

		img.height = h.biHeight;
		img.width = h.biWidth;
		FILE* f = fopen( argv[1], "rb" );
		from_bmp(f, &img);
	}
	else {
		err( "Failed to open BMP file or reading header.\n" );
	}

	return 0;
}