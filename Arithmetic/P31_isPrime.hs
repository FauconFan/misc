listPrimeErathosthemeRecu :: Int -> Int -> [Int] -> [Int]
listPrimeErathosthemeRecu 2 2 [] = []
listPrimeErathosthemeRecu 2 max [] = (listPrimeErathosthemeRecu 3 max [2])
listPrimeErathosthemeRecu actu max tab = 
    if actu > max 
        then tab 
        else if any (isDivisible actu) tab 
            then listPrimeErathosthemeRecu (actu + 1) max tab 
            else listPrimeErathosthemeRecu (actu + 1) max (tab ++ [actu])

isDivisible :: Int -> Int -> Bool
isDivisible n 0 = False
isDivisible n 1 = True
isDivisible n m = mod n m == 0

isPrime :: Int -> Bool
isPrime 0 = False
isPrime 1 = False
isPrime n = elem n (listPrimeErathosthemeRecu 2 n [])