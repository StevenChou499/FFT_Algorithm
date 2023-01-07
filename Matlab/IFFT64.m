function x_Inv_64 = IFFT64(X)
    x_64 = FFT64(X);
    x_64 = x_64 / 64;
    x_Inv_64 = cir_rev(x_64);
end