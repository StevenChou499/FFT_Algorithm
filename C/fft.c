#include "fft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI ((double) 3.1415926)

sequence *conjugate(sequence *sqen) {
    if (sqen->len == 0) {
        fprintf(stderr, "The length of the seqence is zero\n");
        return sqen;
    }
    for (unsigned index = 0; index < sqen->len; index++) {
        (sqen->arr + index)->imag = -(sqen->arr + index)->imag;
    }
    return sqen;
}

unsigned *bit_reverse(unsigned *index, unsigned len) {
    
}

sequence *complex_add(sequence *a, sequence *b) {
    if (a->len != b->len) {
        fprintf(stderr, "The length of sequence a : %u and sequence b : %u isn't the same\n", a->len, b->len);
        return NULL;
    }
    sequence *sum = malloc(sizeof(sequence) * a->len);
    for (unsigned index = 0; index < a->len; index++) {
        (sum->arr + index)->real = (a->arr + index)->real + (b->arr + index)->real;
        (sum->arr + index)->imag = (a->arr + index)->imag + (b->arr + index)->imag;        
    }
    return sum;
}

sequence *complex_sub(sequence *a, sequence *b) {
    if (a->len != b->len) {
        fprintf(stderr, "The length of sequence a : %u and sequence b : %u isn't the same\n", a->len, b->len);
        return NULL;
    }
    sequence *dif = malloc(sizeof(sequence) * a->len);
    for (unsigned index = 0; index < a->len; index++) {
        (dif->arr + index)->real = (a->arr + index)->real - (b->arr + index)->real;
        (dif->arr + index)->imag = (a->arr + index)->imag - (b->arr + index)->imag;        
    }
    return dif;
}

complex W(unsigned r, unsigned N) {
    complex cpx;
    cpx.real = cos((-2 * PI * r) / N);
    cpx.imag = sin((-2 * PI * r) / N);
    return cpx;
}