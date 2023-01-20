#include "fft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned length = 64U;
    sequence *what = sequence_init(length);
    for (int i = 0; i < length; i++) {
        what->arr[i].real = i + 1;
        what->arr[i].imag = i + 1;
    }
    for (int i = 0; i < length; i++) {
        printf("input %d : %f %f\n", i, what->arr[i].real, what->arr[i].imag);
    }
    sequence *What = General_FFT(what);
    for (int i = 0; i < length; i++) {
        printf("output %d : %f %f\n", i, What->arr[i].real, What->arr[i].imag);
    }
    sequence *whhh = Inverse_FFT(What);
    for (int i = 0; i < length; i++) {
        printf("output %d : %f %f\n", i, whhh->arr[i].real, whhh->arr[i].imag);
    }
    sequence_free(what);
    sequence_free(What);
    sequence_free(whhh);
    return 0;
}