#include "fft.h"
#include <stdio.h>

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

sequence *complex_add(sequence *a, sequence *b) {
    if (a->len != b->len) {
        fprintf(stderr, "The length of sequence a and sequence b isn't the same\n");
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
        fprintf(stderr, "The length of sequence a and sequence b isn't the same\n");
        return NULL;
    }
    sequence *dif = malloc(sizeof(sequence) * a->len);
    for (unsigned index = 0; index < a->len; index++) {
        (dif->arr + index)->real = (a->arr + index)->real - (b->arr + index)->real;
        (dif->arr + index)->imag = (a->arr + index)->imag - (b->arr + index)->imag;        
    }
    return dif;
}

