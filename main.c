#include <stdio.h>
#include <stdlib.h>
#include "bmp_functions.h"
#include <math.h>
#include <string.h>

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
    printf("%lf ", entropy);
    printf("%lf ", entropy * 128);
    printf("%d ", sum);//sum -- переменная, которая считает длину считанной последовательности. была нужна для дебага
    int array1[128];
    get_arr(*image, array1);
    char ready_fano[768] = "";
    for (int i = 0; i < 128; i++) { //получается 398 символов
        switch (char_array[i]) {
            case 0:
                strcat(ready_fano, "11011");
                break;
            case 20:
                strcat(ready_fano, "11011");
                break;
            case 40:
                strcat(ready_fano, "11100");
                break;
            case 60:
                strcat(ready_fano, "1100");
                break;
            case 80:
                strcat(ready_fano, "111101");
                break;
            case 100:
                strcat(ready_fano, "111110");
                break;
            case 120:
                strcat(ready_fano, "101");
                break;
            case 140:
                strcat(ready_fano, "01");
                break;
            case 160:
                strcat(ready_fano, "00");
                break;
            case 180:
                strcat(ready_fano, "100");
                break;
            case 200:
                strcat(ready_fano, "11010");
                break;
            case 220:
                strcat(ready_fano, "111010");
                break;
            case 240:
                strcat(ready_fano, "111111");
                break;
            case 260:
                strcat(ready_fano, "111011");
                break;
        }
    }
//    for (int i = 0; i < 768; i++) {
//        printf("%c", ready_fano[i]);
//    }
printf("%s", ready_fano);
}