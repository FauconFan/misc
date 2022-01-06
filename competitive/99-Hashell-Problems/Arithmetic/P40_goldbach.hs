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

goldbach :: Int -> (Int, Int)
goldbach 0 = (0, 0)
goldbach 2 = (0, 0)
goldbach n = 
    if odd n then (0, 0)
    else head [(x, y) | x <- (listPrimeErathosthemeRecu 2 n []), y <- (listPrimeErathosthemeRecu 2 n []), x + y == n]