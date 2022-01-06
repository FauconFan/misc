data Ele a = Single a | Multiple Int a deriving (Show)

encodeModified :: (Eq a) => [a] -> [Ele a]
encodeModified [] = []
encodeModified (x:xs) = encode' 1 x xs
    where 
        encode' 1 x [] = [Single x]
        encode' n x [] = [Multiple n x]
        encode' n x (y:ys)
            | x == y = encode' (n + 1) x ys
            | otherwise = (encode'' n x) : encode' 1 y ys 
        encode'' 1 x = Single x
        encode'' n x = Multiple n x