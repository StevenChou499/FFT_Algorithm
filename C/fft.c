#include "fft.h"

complex *conjugate(complex *cpx, unsigned Num) {
    for (unsigned index = 0; index < Num; index++) {
        (cpx + index)->y = -(cpx + index)->y;
    }
    return cpx;
}

complex *complex_add(complex *a, complex *b, unsigned Num) {
    complex *sum = malloc(sizeof(complex) * Num);
    for (unsigned index = 0; index < Num; index++) {
        (sum + index)->x = (a + index)->x + (b + index)->x;
        (sum + index)->y = (a + index)->y + (b + index)->y;        
    }
    return sum;
}

complex *complex_sub(complex *a, complex *b, unsigned Num) {
    complex *dif = malloc(sizeof(complex) * Num);
    for (unsigned index = 0; index < Num; index++) {
        (dif + index)->x = (a + index)->x - (b + index)->x;
        (dif + index)->y = (a + index)->y - (b + index)->y;        
    }
    return dif;
}