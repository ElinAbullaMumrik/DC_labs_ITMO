//
// Created by Людмила on 11.10.2019.
//
#include <string.h>
#include "fun_coding.h"
char* make_a_code (int length, int* array_in, char* array_out){
    array_out= "";
    for (int i = 0; i<length; i++){
        switch (array_in[i]){
            case 0: strcat(array_out, "11011");
            case 20: strcat(array_out, "11011");
            case 40: strcat(array_out, "11100");
            case 60: strcat(array_out, "1100");
            case 80: strcat(array_out, "111101");
            case 100: strcat(array_out, "111110");
            case 120: strcat(array_out, "101");
            case 140: strcat(array_out, "01");
            case 160: strcat(array_out, "00");
            case 180: strcat(array_out, "100");
            case 200: strcat(array_out, "11010");
            case 220: strcat(array_out, "111010");
            case 240: strcat(array_out, "111111");
            case 260: strcat(array_out, "111011");
        }
    }
    return array_out;
}