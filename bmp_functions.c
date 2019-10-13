//
// Created by Людмила on 10.10.2019.
//
#include "bmp_functions.h"
#include <stdlib.h>
#include <stdio.h>
#include "bmp_functions.h"
#include <math.h>

read_status from_bmp(FILE *in, image_t *const read) {
    bmp_header header;
    fread(&header, sizeof(header), 1, in);
    if (header.bfType != 19778) {
        return READ_INVALID_SIGNATURE;
    }
    if (header.biBitCount != 24) {
        return READ_INVALID_BITS;
    }
    read->width = header.biWidth;
    read->height = header.biHeight;
    read->data = malloc(read->width * read->height * sizeof(pixel_t));
    int padding = (4 - (read->width * sizeof(pixel_t)) % 4) % 4;
    pixel_t *data = read->data;
    for (int i = 0; i < read->height; ++i) {
        for (int j = 0; j < read->width; ++j) {
            fread(data, sizeof(pixel_t), 1, in);
            data++;
        }
        fseek(in, padding, SEEK_CUR);
    }
    return READ_OK;
}

int *occurrence_counter(int *in_arr, int *out_arr) {
    for (int j = 0; j < 14; ++j) {
        out_arr[j] = 0;
    }
    for (int i = 0; i < 128; i++) {
        int temp = round(in_arr[i] / 20);
        out_arr[temp]++;
    }
    return out_arr;
}

int *get_arr(const image_t image, int *array) {
    for (int i = 0; i < image.width; i++) {
        pixel_t temp = image.data[image.width * image.width / 2 + i];
        array[i] = round((0.299 * temp.r + 0.587 * temp.g + 0.114 * temp.b) / 20) * 20;
    }
    return array;
}