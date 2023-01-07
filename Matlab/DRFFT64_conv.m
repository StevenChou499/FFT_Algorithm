function X_conv = DRFFT64_conv(x, y)
    x_padded = [x, zeros(1, 32)];
    y_padded = [y, zeros(1, 32)];

    [DRFF_X, DRFF_Y] = DRFFT64(x_padded, y_padded);

    Freq_Result = DRFF_X .* DRFF_Y;

    Result = IFFT64(Freq_Result);

    X_conv = real(Result(1 : 63));
end