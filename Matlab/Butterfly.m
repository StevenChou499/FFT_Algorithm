function B = Butterfly(bn, len)
    if (len == 2)
        B(1) = bn(1) + bn(2) * W(0, 2);
        B(2) = bn(1) - bn(2) * W(0, 2);
        return;
    end
    B = zeros([1 len]);
    bn_top_half = Butterfly(bn(1 : ((len / 2))), len / 2);
    bn_bottom_half = Butterfly(bn(((len / 2) + 1) : len), len / 2);
    for i = 1 : (len / 2)
        B(i) = bn_top_half(i) + bn_bottom_half(i) * W(i - 1, len);
        B(i + (len / 2)) = bn_top_half(i) - bn_bottom_half(i) * W(i - 1, len);
    end
end