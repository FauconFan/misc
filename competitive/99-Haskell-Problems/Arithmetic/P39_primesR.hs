listPrimeErathosthemeRecu :: Int -> Int -> [Int] -> [Int]
listPrimeErathosthemeRecu 2 2 [] = []
listPrimeErathosthemeRecu 2 max [] = (listPrimeErathosthemeRecu 3 max [2])
listPrimeErathosthemeRecu actu max tab = 
    if actu > max 
        then tab 
        else if any (isDivisible actu) tab 
            then listPrimeErathosthemeRecu (actu + 1) max tab 
            else listPrimeErathosthemeRecu (actu + 1) max (tab ++ [actu])

listPrimeErathostheme :: Int -> [Int]
listPrimeErathostheme 0 = []
listPrimeErathostheme 1 = []
listPrimeErathostheme n = listPrimeErathosthemeRecu 2 n []

isDivisible :: Int -> Int -> Bool
isDivisible n 0 = False
isDivisible n 1 = True
isDivisible n m = mod n m == 0

primesR :: Int -> Int -> [Int]
primesR n m = dropWhile (< n) (listPrimeErathostheme m)