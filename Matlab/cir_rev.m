function X_rev = cir_rev(X)
    len = length(X);
    X_rev = [X(1), fliplr(X(2 : len))];
end