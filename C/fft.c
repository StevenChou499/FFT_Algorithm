#include "fft.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI ((double) 3.1415926)

void complex_add(complex *a, complex *b, complex *sum) {
    sum->real = a->real + b->real;
    sum->imag = a->imag + b->imag;
    return;
}

void complex_sub(complex *a, complex *b, complex *dif) {
    dif->real = a->real - b->real;
    dif->imag = a->imag - b->imag;
    return;
}

void complex_mul(complex *a, complex *b, complex *mul) {
    mul->real = a->real * b->real - a->imag * b->imag;
    mul->imag = a->real * b->imag + a->imag * b->real;
    return;
}

sequence *sequence_init(unsigned length) {
    sequence *sqen = malloc(sizeof(sequence));
    if (sqen) {
        sqen->arr = calloc(sizeof(complex), length);
    }
    sqen->len = length;
    return sqen;
}

void sequence_free(sequence *sqen) {
    free(sqen->arr);
    free(sqen);
    return;
}

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

unsigned *bit_reverse(unsigned len) {
    unsigned needed_bit = (unsigned) log2(len);
    unsigned needed_array = pow(2, needed_bit);
    unsigned *index = calloc(sizeof(unsigned), needed_array);
    // unsigned tmp = 0;
    for (unsigned i = 0; i < needed_array; i++) {
        unsigned tmp = 0;
        for (unsigned j = 0; j < needed_bit; j++) {
            if ((1 << j) & i)
                tmp = tmp | ((1 << (needed_bit - 1)) >> j);
        }
        index[i] = tmp;
    }
    return index;
}

void sequence_add(sequence *a, sequence *b, sequence *sum) {
    if (a->len != b->len) {
        fprintf(stderr, "The length of sequence a : %u and sequence b : %u isn't the same\n", a->len, b->len);
        return;
    }
    if (sum == NULL)
        sum = malloc(sizeof(sequence) * a->len);
    for (unsigned index = 0; index < a->len; index++) {
        (sum->arr + index)->real = (a->arr + index)->real + (b->arr + index)->real;
        (sum->arr + index)->imag = (a->arr + index)->imag + (b->arr + index)->imag;
    }
    sum->len = a->len;
    return;
}

void sequence_sub(sequence *a, sequence *b, sequence *dif) {
    if (a->len != b->len) {
        fprintf(stderr, "The length of sequence a : %u and sequence b : %u isn't the same\n", a->len, b->len);
        return;
    }
    if (dif == NULL)
        dif = malloc(sizeof(sequence) * a->len);
    for (unsigned index = 0; index < a->len; index++) {
        (dif->arr + index)->real = (a->arr + index)->real - (b->arr + index)->real;
        (dif->arr + index)->imag = (a->arr + index)->imag - (b->arr + index)->imag;        
    }
    dif->len = a->len;
    return;
}

void sequence_mul(sequence *a, sequence *b, sequence *prod) {
    if (a->len != b->len) {
        fprintf(stderr, "The length of sequence a : %u and sequence b : %u isn't the same\n", a->len, b->len);
        return;
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
    return;
}

complex W(unsigned r, unsigned N) {
    complex cpx;
    cpx.real = cos((-2 * PI * r) / N);
    cpx.imag = sin((-2 * PI * r) / N);
    return cpx;
}

sequence *FFT2(sequence *x) {
    sequence *X = sequence_init(2);
    sequence *tmp = sequence_init((2 / 2));
    complex tmp_c[(2 / 2)];
    for (unsigned index = 0; index < (2 / 2); index++) {
        tmp_c[index] = W(index, 2);
        complex_mul((x->arr + index), (tmp_c + index), (tmp->arr + index));
    }
    for (unsigned index = 0; index < (2 / 2); index++) {
        complex_add(x->arr + index, tmp->arr + index, X->arr + index);
        complex_sub(x->arr + index, tmp->arr + index, X->arr + (index + (2 /2)));
    }
    sequence_free(tmp);
    return X;
}

sequence *FFT4(sequence *x) {
    sequence *X = sequence_init(4);
    sequence *tmp = sequence_init((4 / 2));
    unsigned *list = bit_reverse(4);
    complex tmp_c[(4 / 2)];
    for (unsigned index = 0; index < (4 / 2); index++) {
        tmp_c[index] = W(index, 4);
        complex_mul((x->arr + index), (tmp_c + index), (tmp->arr + index));
    }
    for (unsigned index = 0; index < (4 / 2); index++) {
        complex_add(x->arr + index, tmp->arr + index, X->arr + index);
        complex_sub(x->arr + index, tmp->arr + index, X->arr + (index + (4 / 2)));
    }
    sequence_free(tmp);
    return X;
}

void Butterfly(complex *X, complex *x, unsigned len) {
    complex tmp_mul[len / 2];
    complex tmp_W[len / 2];
    if (len == 2) {
        for (unsigned index = 0; index < (len / 2); index++) {
            tmp_W[index] = W(index, len);
            complex_mul((x + index), (tmp_W + index), (tmp_mul + index));
        }
        for (unsigned index = 0; index < (len / 2); index++) {
            complex_add((x + index), (tmp_mul + index), (X + index));
            complex_sub((x + index), (tmp_mul + index), (X + index + (len / 2)));
        }
        return;
    }
    Butterfly((X), (x), (len / 2));
    Butterfly((X + (len / 2)), (x + (len / 2)), (len / 2));
    for (unsigned index = 0; index < (len / 2); index++) {
        tmp_W[index] = W(index, len);
        complex_mul((X + index), (tmp_W + index), (tmp_mul + index));
    }
    for (unsigned index = 0; index < (len / 2); index++) {
        complex t = *(X + index);
        complex_add((X + index), (tmp_mul + index), (X + index));
        complex_sub(&t, (tmp_mul + index), (X + index + (len / 2)));
    }
    return;
}

sequence *General_FFT(sequence *x) {
    if (x->len == 0) {
        fprintf(stderr, "The lenght of input sequence is zero, returning NULL\n");
        return NULL;
    }
    unsigned len = x->len;
    complex tmp_mul[len / 2];
    complex tmp_W[len / 2];
    complex tmp[len];
    sequence *X = sequence_init(len);
    X->len = len;
    X->arr = calloc(sizeof(complex), len);
    unsigned *bit_rev = bit_reverse(len);
    for (unsigned index = 0; index < len; index++) {
        tmp[index] = x->arr[bit_rev[index]];
    }
    for (unsigned index = 0; index < len; index++) {
        x->arr[index] = tmp[index];
    }
    Butterfly((X->arr), (x->arr), (len / 2));
    Butterfly((X->arr + (len / 2)), (x->arr + (len / 2)), (len / 2));
    for (unsigned index = 0; index < (len / 2); index++) {
        tmp_W[index] = W(index, len);
        complex_mul((X->arr + index), (tmp_W + index), (tmp_mul + index));
    }
    for (unsigned index = 0; index < (len / 2); index++) {
        complex t = *(X->arr + index);
        complex_add((X->arr + index), (tmp_mul + index), (X->arr + index));
        complex_sub(&t, (tmp_mul + index), (X->arr + index + (len / 2)));
    }
    return X;
}