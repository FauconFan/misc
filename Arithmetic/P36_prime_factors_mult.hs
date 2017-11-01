listPrimeErathosthemeRecu :: Int -> Int -> [Int] -> [Int]
listPrimeErathosthemeRecu 2 2 [] = []
listPrimeErathosthemeRecu 2 max [] = (listPrimeErathosthemeRecu 3 max [2])
listPrimeErathosthemeRecu actu max tab = 
    if actu > max 
        then tab 
        else if any (isDivisible actu) tab 
            then listPrimeErathosthemeRecu (actu + 1) max tab 
            else listPrimeErathosthemeRecu (actu + 1) max (tab ++ [actu])
    where
        isDivisible :: Int -> Int -> Bool
        isDivisible n m = mod n m == 0

listPrimeErathostheme :: Int -> [Int]
listPrimeErathostheme 0 = []
listPrimeErathostheme 1 = []
listPrimeErathostheme n = listPrimeErathosthemeRecu 2 n []

nbDivisible :: Int -> Int -> Int
nbDivisible n m = if mod n m /= 0 then 0 else 1 + nbDivisible (div n m) m

prime_factors_mult :: Int -> [(Int, Int)]
prime_factors_mult 0 = []
prime_factors_mult 1 = []
prime_factors_mult x = [(n, m) | n <- listPrimeErathostheme x, let m = nbDivisible x n, m /= 0]