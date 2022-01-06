repli :: [a] -> Int -> [a]
repli [] n = []
repli (x:xs) n = (repli' x n) ++ (repli xs n)
    where
        repli' x 0 = []
        repli' x n = x:(repli' x (n - 1))