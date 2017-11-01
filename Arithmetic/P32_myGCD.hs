pgcd :: Int -> Int -> Int
pgcd a b
    | b == 0 = abs a
    | otherwise = gcd b (mod a b)