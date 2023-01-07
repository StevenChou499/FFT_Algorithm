function Conv_result = direct_conv_32(input1, input2)
    Conv_result = zeros(1, 63);
    for i = 1 : 63
        for a = 1 : 32
            for b = 1 : 32
                if (a + b) == (i + 1)
                    Conv_result(i) = Conv_result(i) + input1(a) * input2(b);
                end
            end
        end
    end
end