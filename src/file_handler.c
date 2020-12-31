#include "file_handler.h"

enum open_status open_bmp(FILE **file, const char *filename, const char *modes)
{
	*file = fopen(filename, modes);

	if (*file)
		return OPEN_OK;
	printf("open error\n");

	return OPEN_ERROR;
}

enum close_status close_bmp(FILE **file)
{
	if (fclose(*file) != EOF)
		return CLOSE_OK;
	printf("close error\n");

	return CLOSE_ERROR;
}

