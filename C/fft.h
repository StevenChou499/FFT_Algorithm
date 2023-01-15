#ifndef FFT
#define FFT

typedef struct complex {
    double real;
    double imag;
} complex;

typedef struct sequence {
    complex *arr;
    unsigned len;
} sequence;

// conjugate a sequence
sequence *conjugate(sequence *sqen);

// bit reverse an sequence of index
unsigned *bit_reverse(unsigned *index, unsigned len);

// an array of complex addition 
sequence *complex_add(sequence *a, sequence *b);

// an array of complex subtraction
sequence *complex_sub(sequence *a, sequence *b);

// an array of complex multiplication
sequence *complex_mul(sequence *a, sequence *b);

// weighting function
complex W(unsigned r, unsigned N);

#endif