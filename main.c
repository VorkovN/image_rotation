#include <stdio.h>

#include "bmp.h"
#include "util.h"
#include "read_bmp.h"
#include "rotate_bmp.h"
#include "write_bmp.h"
#include "file_handler.h"


void usage()
{
	fprintf(stderr, "Usage: ./print_header BMP_FILE_NAME\n");
}

int main(int argc, char **argv)
{
	if (argc != 2) usage();
	if (argc < 2) err("Not enough arguments \n");
	if (argc > 2) err("Too many arguments \n");

	struct bmp_header h = {0};
	struct image img;
	if (read_header_from_file(argv[1], &h)) {
		bmp_header_print(&h, stdout);

		FILE *f_in = NULL;
		FILE *f_out = NULL;

		open_bmp(&f_in, argv[1], "rb");
		open_bmp(&f_out, "../images/image2.bmp", "wb");

		if (from_bmp(f_in, &img, &h) != READ_OK)
			return 1;

		img = rotate(img, &h);

		fwrite(&h, sizeof(struct bmp_header), 1, f_out);
		if (to_bmp(f_out, &img) != WRITE_OK)
			return 1;

		close_bmp(&f_in);
		close_bmp(&f_out);
	}
	else {
		err("Failed to open BMP file or reading header.\n");
	}

	return 0;
}