#include "fft.h"
#include <stdio.h>
#include <stdlib.h>

// int main(void)
// {
//     sequence *what = sequence_init(2U);
//     what->arr[0].real = 1;
//     what->arr[1].real = 1;
//     sequence *What = FFT2(what);
//     printf("%f %f %f %f\n", what->arr[0].real, what->arr[0].imag, what->arr[1].real, what->arr[1].imag);
//     printf("%f %f %f %f\n", What->arr[0].real, What->arr[0].imag, What->arr[1].real, What->arr[1].imag);
//     sequence_free(what);
//     sequence_free(What);

//     int len = 8;
//     unsigned *list = bit_reverse(len);
//     for (int i = 0; i < len; i++)
//         printf("%u\n", list[i]);
//     free(list);
//     return 0;
// }

int main(void)
{
    unsigned length = 8U;
    sequence *what = sequence_init(length);
    for (int i = 0; i < length; i++) {
        what->arr[i].real = i;
        what->arr[i].imag = i;
    }
    for (int i = 0; i < length; i++) {
        printf("input %d : %f %f\n", i, what->arr[i].real, what->arr[i].imag);
    }
    sequence *What = General_FFT(what);
    for (int i = 0; i < length; i++) {
        printf("output %d : %f %f\n", i, What->arr[i].real, What->arr[i].imag);
    }
    sequence_free(what);
    sequence_free(What);
    return 0;
}