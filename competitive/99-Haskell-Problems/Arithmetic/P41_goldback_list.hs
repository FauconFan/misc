import Data.List

data Ele = Couple (Int, Int)

instance Show Ele where
    show (Couple (a, b)) = show a ++ " + " ++ show b

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

goldbach :: Int -> Ele
goldbach 0 = Couple (0, 0)
goldbach 2 = Couple (0, 0)
goldbach n = 
    if odd n then Couple (0, 0)
    else head [Couple (x, y) | x <- (listPrimeErathosthemeRecu 2 n []), y <- (listPrimeErathosthemeRecu 2 n []), x + y == n]

goldbach_list :: Int -> Int -> [Ele]
goldbach_list n m = map goldbach [actu | actu <- [n..m], even actu, actu > 2]

goldbach_list' :: Int -> Int -> Int -> [Ele]
goldbach_list' n m max = myDelete max (goldbach_list n m)
    where
        myDelete :: Int -> [Ele] -> [Ele]
        myDelete n [] = []
        myDelete n ((Couple (a, b)):xs) = if a >= n && b >= n then (Couple (a, b)):(myDelete n xs) else myDelete n xs