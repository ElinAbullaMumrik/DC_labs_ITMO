//
// Created by Людмила on 13.10.2019.
//

#include "fano_func.h"
#include <string.h>

char *get_fano(int *char_array, char *ready_fano) {
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
    return (ready_fano);
};

char *get_haffman(int *char_array, char *ready_haffman) {
    for (int i = 0; i < 128; i++) { //получается 398 символов
        switch (char_array[i]) {
            case 0:
                strcat(ready_haffman, "010001");
                break;
            case 20:
                strcat(ready_haffman, "01001");
                break;
            case 40:
                strcat(ready_haffman, "11110");
                break;
            case 60:
                strcat(ready_haffman, "1110");
                break;
            case 80:
                strcat(ready_haffman, "010000");
                break;
            case 100:
                strcat(ready_haffman, "111111");
                break;
            case 120:
                strcat(ready_haffman, "110");
                break;
            case 140:
                strcat(ready_haffman, "10");
                break;
            case 160:
                strcat(ready_haffman, "00");
                break;
            case 180:
                strcat(ready_haffman, "011");
                break;
            case 200:
                strcat(ready_haffman, "01011");
                break;
            case 220:
                strcat(ready_haffman, "010101");
                break;
            case 240:
                strcat(ready_haffman, "111110");
                break;
            case 260:
                strcat(ready_haffman, "010100");
                break;
        }
    }
    return (ready_haffman);
};

char *get_equals(int *char_array, char *ready_equals) {
    for (int i = 0; i < 128; i++) { //получается 398 символов
        switch (char_array[i]) {
            case 0:
                strcat(ready_equals, "0000");
                break;
            case 20:
                strcat(ready_equals, "0001");
                break;
            case 40:
                strcat(ready_equals, "0010");
                break;
            case 60:
                strcat(ready_equals, "0011");
                break;
            case 80:
                strcat(ready_equals, "0100");
                break;
            case 100:
                strcat(ready_equals, "0101");
                break;
            case 120:
                strcat(ready_equals, "0110");
                break;
            case 140:
                strcat(ready_equals, "0111");
                break;
            case 160:
                strcat(ready_equals, "1000");
                break;
            case 180:
                strcat(ready_equals, "1001");
                break;
            case 200:
                strcat(ready_equals, "1010");
                break;
            case 220:
                strcat(ready_equals, "1011");
                break;
            case 240:
                strcat(ready_equals, "1100");
                break;
            case 260:
                strcat(ready_equals, "1101");
                break;
        }
    }
    return (ready_equals);
};