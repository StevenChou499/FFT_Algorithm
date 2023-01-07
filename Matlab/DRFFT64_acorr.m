function X_acorr = DRFFT64_acorr(x)
    x_rev = fliplr(x);
    x_padded = [x, zeros(1, 32)];
    x_rev_padded = [x_rev, zeros(1, 32)];

    [X, X_REV] = DRFFT64(x_padded, x_rev_padded);

    Result = X .* X_REV;
    Result_Inv = IFFT64(Result);
    
    X_acorr = real(Result_Inv(1 : 63));
end