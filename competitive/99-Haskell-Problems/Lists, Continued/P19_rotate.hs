rotate :: [a] -> Int -> [a]
rotate x n
    | n >= 0 = drop' n x ++ take' n x
    | otherwise = drop' m x ++ take' m x
    where
        m = n + length x
        drop' 0 x = x
        drop' n [] = []
        drop' n (x:xs) = drop' (n - 1) xs
        take' 0 x = []
        take' n [] = []
        take' n (x:xs) = x:(take' (n - 1) xs)