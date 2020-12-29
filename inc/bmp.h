#ifndef _BMP_H_
#define _BMP_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define FOR_BMP_HEADER( FOR_FIELD ) \
        FOR_FIELD( uint16_t,bfType)\
        FOR_FIELD( uint32_t,bfileSize)\
        FOR_FIELD( uint32_t,bfReserved)\
        FOR_FIELD( uint32_t,bOffBits)\
        FOR_FIELD( uint32_t,biSize)\
        FOR_FIELD( uint32_t,biWidth)\
        FOR_FIELD( uint32_t,biHeight)\
        FOR_FIELD( uint16_t,biPlanes)\
        FOR_FIELD( uint16_t,biBitCount)\
        FOR_FIELD( uint32_t,biCompression)\
        FOR_FIELD( uint32_t,biSizeImage)\
        FOR_FIELD( uint32_t,biXPelsPerMeter)\
        FOR_FIELD( uint32_t,biYPelsPerMeter)\
        FOR_FIELD( uint32_t,biClrUsed)\
        FOR_FIELD( uint32_t,biClrImportant)

#define DECLARE_FIELD( t, n ) t n ;

struct __attribute__((packed)) bmp_header
{
   FOR_BMP_HEADER( DECLARE_FIELD )
};

struct pixel { uint8_t b, g, r; };

struct image {
	uint64_t width, height;
	struct pixel* data;
};

struct __attribute__ ((packed)) bmp_header2
{
uint16_t bfType;
uint32_t  bfileSize;
uint32_t bfReserved;
uint32_t bOffBits;
uint32_t biSize;
uint32_t biWidth;
uint32_t  biHeight;
uint16_t  biPlanes;
uint16_t biBitCount;
uint32_t biCompression;
uint32_t biSizeImage;
uint32_t biXPelsPerMeter;
uint32_t biYPelsPerMeter;
uint32_t biClrUsed;
uint32_t  biClrImportant;
};


void bmp_header_print( struct bmp_header const* header, FILE* f );
bool read_header_from_file( const char* filename, struct bmp_header* header );

#endif
