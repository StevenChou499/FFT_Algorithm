function X_32 = FFT32(x)
    i = (0 : 31);
    i = bitrevorder(i);
    X_32 = zeros([1 32]);
    xn_16_1 = Butterfly(x(i(1:16) + ones(1, 16)), 16);
    xn_16_2 = Butterfly(x(i(17:32) + ones(1, 16)), 16);
    for i = 1 : 16
        X_32(i) = xn_16_1(i) + xn_16_2(i) * W(i - 1, 32);
        X_32(i + 16) = xn_16_1(i) - xn_16_2(i) * W(i - 1, 32);
    end
end