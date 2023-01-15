#ifndef FFT
#define FFT

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI ((double) 3.1415926)

typedef struct complex {
    double real;
    double imag;
} complex;

typedef struct sequence {
    complex *arr;
    unsigned len;
} sequence;

// complex addition
void inline complex_add(complex *a, complex *b, complex *sum) {
    sum->real = a->real + b->real;
    sum->imag = a->imag + b->imag;
    return;
}

// complex subtraction
void inline complex_sub(complex *a, complex *b, complex *dif) {
    dif->real = a->real - b->real;
    dif->imag = a->imag - b->imag;
    return;
}

// complex multiplication
void inline complex_mul(complex *a, complex *b, complex *mul) {
    mul->real = a->real * b->real - a->imag * b->imag;
    mul->imag = a->real * b->imag + a->imag * b->real;
    return;
}

// Initialize a sequence of complex numbers with all zeros
sequence *sequence_init(unsigned length) {
    sequence *sqen = malloc(sizeof(sequence));
    if (sqen) {
        sqen->arr = calloc(sizeof(complex), len);
    }
    sqen->len = length;
    return sqen;
}

// Free the memory space of a sequence
void sequnce_free(sequence *sqen) {
    free(sqen->arr);
    free(sqen);
    return;
}

// conjugate a sequence
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

// bit reverse an sequence of index
unsigned *bit_reverse(unsigned *index, unsigned len);

// an sequence of complex addition 
void sequence_add(sequence *a, sequence *b, sequence *sum) {
    if (a->len != b->len) {
        fprintf(stderr, "The length of sequence a : %u and sequence b : %u isn't the same\n", a->len, b->len);
        return NULL;
    }
    if (sum == NULL)
        sum = malloc(sizeof(sequence) * a->len);
    for (unsigned index = 0; index < a->len; index++) {
        (sum->arr + index)->real = (a->arr + index)->real + (b->arr + index)->real;
        (sum->arr + index)->imag = (a->arr + index)->imag + (b->arr + index)->imag;        
    }
    sum->len = a->len;
    return sum;
}

// an sequence of complex subtraction
void sequence_sub(sequence *a, sequence *b, sequence *dif) {
    if (a->len != b->len) {
        fprintf(stderr, "The length of sequence a : %u and sequence b : %u isn't the same\n", a->len, b->len);
        return NULL;
    }
    if (dif == NULL)
        dif = malloc(sizeof(sequence) * a->len);
    for (unsigned index = 0; index < a->len; index++) {
        (dif->arr + index)->real = (a->arr + index)->real - (b->arr + index)->real;
        (dif->arr + index)->imag = (a->arr + index)->imag - (b->arr + index)->imag;        
    }
    dif->len = a->len;
    return dif;
}

// an sequence of complex multiplication
void sequence_mul(sequence *a, sequence *b, sequence *prod) {
    if (a->len != b->len) {
        fprintf(stderr, "The length of sequence a : %u and sequence b : %u isn't the same\n", a->len, b->len);
        return NULL;
    }
    if (prod == NULL)
        prod = malloc(sizeof(sequence) * a->len);
    for (unsigned index = 0; index < a->len; index++) {
        (prod->arr + index)->real = (a->arr + index)->real * (b->arr + index)->real \
        - (a->arr + index)->imag * (b->arr + index)->imag;
        (prod->arr + index)->imag = (a->arr + index)->real * (b->arr + index)->imag \
        + (a->arr + index)->imag * (b->arr + index)->real;
    }
    prod->len = a->len;
    return sum;
}

// weighting function
complex W(unsigned r, unsigned N) {
    complex cpx;
    cpx.real = cos((-2 * PI * r) / N);
    cpx.imag = sin((-2 * PI * r) / N);
    return cpx;
}

#endif