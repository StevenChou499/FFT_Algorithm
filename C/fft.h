#ifndef FFT
#define FFT

#include <math.h>

typedef struct complex {
    double x;
    double y;
} complex;

// conjugate an array of complex number
complex *conjugate(complex *cpx, unsigned Num);

// an array of complex addition 
complex *complex_add(complex *a, complex *b, unsigned Num);

// an array of complex subtraction
complex *complex_sub(complex *a, complex *b, unsigned Num);

// an array of complex multiplication
complex *complex_mul(complex *a, complex *b, unsigned Num);

// weighting function
complex W(unsigned r, unsigned N);

#endif