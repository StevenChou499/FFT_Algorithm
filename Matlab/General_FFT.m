function X = General_FFT(xn)
    len = length(xn);
    i = (0 : (len - 1));
    i = bitrevorder(i);
    X = zeros([1 len]);
    xn_top = Butterfly(xn(i(1 : len / 2) + ones(1, len / 2)), len / 2);
    xn_bottom = Butterfly(xn(i(len / 2 + 1 : len) + ones(1, len / 2)), len / 2);
    for i = 1 : (len / 2)
        X(i) = xn_top(i) + xn_bottom(i) * W(i - 1, len);
        X(i + (len / 2)) = xn_top(i) - xn_bottom(i) * W(i - 1, len);
    end
end