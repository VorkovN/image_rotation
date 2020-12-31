#include "file_handler.h"

enum open_status open_bmp( FILE** file, const char *filename, const char *modes)
{
	*file = fopen( filename, modes);

	return OPEN_OK;
}

enum close_status close_bmp( FILE** file)
{
	fclose(*file);

	return CLOSE_OK;
}

