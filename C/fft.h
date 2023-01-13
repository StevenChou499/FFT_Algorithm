#ifndef FFT
#define FFT

#include <math.h>

typedef struct complex {
    double x;
    double y;
} compelx;

// conjugate of a complex number
void conjugate(complex *cpx);

// complex addition
void complex_add(complex *a, complex *b);

// weighting function
double W(unsigned r, unsigned N);

#endif