#include "fft.h"
#include <stdio.h>

int main(void)
{
    // int r = 1, N = 8;
    for (int r = 0, N = 8; r < N; r++) {
        printf("The value of W(%u, %u) is %lf\n", r, N, W(r, N).real);
        printf("The value of W(%u, %u) is %lf\n", r, N, W(r, N).imag);
    }
    return 0;
}