#include <stdio.h>
#include <stdlib.h>
#include "bmp_functions.h"

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: file not found\n");
        return 2;
    }
    image_t *image = malloc(sizeof(image_t));
    read_status result = from_bmp(file, image);
    switch (result) {
        case READ_INVALID_HEADER: {
            printf("Error: invailid header\n");
            return 2;
        }
        case READ_INVALID_BITS: {
            printf("Error: invailid deep img\n");
            return 2;
        }
        case READ_OK: {
            printf("Read successfull\n");
            break;
        }
    }
    int array[128];
    get_arr(*image, array);
    for (int i = 0; i < 128; i++) {
        printf("%d ", array[i]);
    }
}