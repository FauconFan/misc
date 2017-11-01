isPrime :: Int -> Bool
isPrime 0 = False
isPrime 1 = False
isPrime 2 = True
isPrime n = elem n (listPrimeErathosthemeRecu 2 n [])
    where
        listPrimeErathosthemeRecu :: Int -> Int -> [Int] -> [Int]
        listPrimeErathosthemeRecu actu max tab = 
            if actu > max 
                then tab 
                else if any (isDivisible actu) tab 
                    then listPrimeErathosthemeRecu (actu + 1) max tab 
                    else listPrimeErathosthemeRecu (actu + 1) max (tab ++ [actu])
        isDivisible :: Int -> Int -> Bool
        isDivisible n m = mod n m == 0