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

// complex addition
void complex_add(complex *a, complex *b, complex *sum);

// complex subtraction
void complex_sub(complex *a, complex *b, complex *dif);

// complex multiplication
void complex_mul(complex *a, complex *b, complex *mul);

// complex divided by number
void complex_div_num(complex *a, unsigned num);

// Initialize a sequence of complex numbers with all zeros
sequence *sequence_init(unsigned length);

// Free the memory space of a sequence
void sequence_free(sequence *sqen);

// conjugate a sequence
sequence *conjugate(sequence *sqen);

// circular reverse a sequence
void seq_cir_rev(sequence *sqen);

// bit reverse an sequence of index
unsigned *bit_reverse(unsigned len);

// an sequence of complex addition 
void sequence_add(sequence *a, sequence *b, sequence *sum);

// an sequence of complex subtraction
void sequence_sub(sequence *a, sequence *b, sequence *dif);

// an sequence of complex multiplication
void sequence_mul(sequence *a, sequence *b, sequence *prod);

// divide a sequence by a number
void seq_div_num(sequence *x, unsigned num);

// weighting function
complex W(unsigned r, unsigned N);

// implement 2 complex FFT
sequence *FFT2(sequence *x);

// implement 4 complex FFT
sequence *FFT4(sequence *x);

// implement Butterfly calculation for FFT
void Butterfly(complex *X, complex *x, unsigned len);

// implement general FFT
sequence *General_FFT(sequence *x);

// implement inverse FFT
sequence *Inverse_FFT(sequence *X);

#endif