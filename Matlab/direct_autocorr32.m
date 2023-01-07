function X_ac = direct_autocorr32(xn_32)
    X_ac = zeros(1, 63);
    for k = -31 : 31
        for i = 1 : 32
            if (i + k) > 0 && (i + k) < 33
                X_ac(k + 32) = X_ac(k + 32) + xn_32(i) * xn_32(i + k);
            end
        end
    end
end