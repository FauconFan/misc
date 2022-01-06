encode :: (Eq a) => [a] -> [(Int, a)]
encode [] = []
encode (x:xs) = encode' 1 x xs where
    encode' n x [] = [(n, x)]
    encode' n x (y:ys)
        | x == y = encode' (n + 1) x ys
        | otherwise = (n, x) : encode' 1 y ys