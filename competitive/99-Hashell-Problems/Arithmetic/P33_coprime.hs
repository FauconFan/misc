coprime :: Int -> Int -> Bool
coprime a b
    | b == 0 = (abs a) == 1
    | otherwise = coprime b (mod a b)