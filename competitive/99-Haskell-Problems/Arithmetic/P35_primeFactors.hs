primeFactors :: Int -> [Int]
primeFactors 0 = []
primeFactors 1 = []
primeFactors n = primeFactors' n 2
    where
        primeFactors' :: Int -> Int -> [Int]
        primeFactors' 1 _ = []
        primeFactors' n f
            | mod n f == 0 = f : primeFactors' (div n f) f
            | otherwise = primeFactors' n (f + 1)