coprime :: Int -> Int -> Bool
coprime a b
    | b == 0 = (abs a) == 1
    | otherwise = coprime b (mod a b)

totient :: Int -> Int
totient 1 = 1
totient n = length (totient' 1 n)
    where
        totient' n m = 
            if (n == m) then [] else
            if (coprime n m)
            then n:(totient' (n + 1) m)
            else totient' (n + 1) m