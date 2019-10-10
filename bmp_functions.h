//
// Created by Людмила on 10.10.2019.
//

#ifndef DC_LAB2_BMP_FUNCTIONS_H
#define DC_LAB2_BMP_FUNCTIONS_H

#include <stdint.h>
#include <stdio.h>

typedef struct bmp_header {
    uint16_t bfType;
    uint32_t bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} __attribute__((packed)) bmp_header;

typedef struct pixel_t {
    uint8_t b, g, r;
} pixel_t;

typedef struct image_t {
    uint32_t width, height;
    struct pixel_t *data;
} image_t;
typedef enum {
    READ_OK,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER
} read_status;

read_status from_bmp(FILE *in, image_t *const read);

int *occurrence_counter(const image_t image, int *array);

#endif //DC_LAB2_BMP_FUNCTIONS_H
