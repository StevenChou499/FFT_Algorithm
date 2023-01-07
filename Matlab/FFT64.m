function X_64 = FFT64(x)
    i = (0 : 63);
    i = bitrevorder(i);
    X_64 = zeros([1 64]);
    xn_32_1 = FFT32(x(bitrevorder(i(1:32)) + ones(1, 32)));
    xn_32_2 = FFT32(x(bitrevorder(i(33:64)) + ones(1, 32)));
    for i = 1 : 32
        X_64(i) = xn_32_1(i) + xn_32_2(i) * W(i - 1, 64);
        X_64(i + 32) = xn_32_1(i) - xn_32_2(i) * W(i - 1, 64);
    end
end