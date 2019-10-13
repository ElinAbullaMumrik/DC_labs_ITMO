#include <stdio.h>
#include <stdlib.h>
#include "bmp_functions.h"
#include <math.h>
#include "fano_func.h"

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
    int sum = 0;
    int char_array[128];
    int array_occ[14];
    get_arr(*image, char_array); //char_array -- массив, где лежат числа, кратные 2
    occurrence_counter(char_array, array_occ); // array_occ -- массив, где лежит количество встречаний каждого элемента
    for (int i = 0; i < 14; i++) {
        printf("%d ", array_occ[i]);
        sum += array_occ[i];
    }
    double entropy = 0;
    for (int i = 0; i < 14; i++) {
        double temp = (double) array_occ[i] / 128;
        if (temp != 0) {
            entropy = entropy - temp * log2(temp);
        }
    }
    printf("entropy %lf\n entropy length  %lf\n", entropy * 128);
//    printf("%d ", sum);//sum -- переменная, которая считает длину считанной последовательности. была нужна для дебага
    int array1[128];
    get_arr(*image, array1);
    char ready_fano[768] = "";
    get_fano(char_array, ready_fano);
    printf("\nShannon-Fano coding:\n %s \nEquals coding:\n", ready_fano);
    char ready_equals[768] = "";
    get_equals(char_array, ready_equals);
    printf("%s", ready_equals);

    char ready_haffman[768] = "";
    get_fano(char_array, ready_haffman);
    printf("\nHaffman coding:\n %s", ready_haffman);
}