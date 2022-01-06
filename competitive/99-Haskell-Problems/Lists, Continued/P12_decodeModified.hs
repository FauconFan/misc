data Ele a = Single a | Multiple Int a deriving (Show)

decodeModified :: [Ele a] -> [a]
decodeModified [] = []
decodeModified (x:xs) = (decode' x) ++ (decodeModified xs)
    where
        decode' (Single x) = [x]
        decode' (Multiple n x) = [x | y <- [1..n]]