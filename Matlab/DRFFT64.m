function [X_64, Y_64] = DRFFT64(x, y)
    c_64 = x + 1j * y;
    C_64 = FFT64(c_64);
    X_64 = (C_64 + conjugate(cir_rev(C_64))) / 2;
    Y_64 = (C_64 - conjugate(cir_rev(C_64))) / (2 * 1j);
end