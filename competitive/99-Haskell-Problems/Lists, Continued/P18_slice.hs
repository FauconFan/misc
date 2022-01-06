slice :: [a] -> Int -> Int -> [a]
slice [] n m = []
slice xs 0 0 = []
slice xs n m = if n >= m || n >= length xs || m < 0 then [] else
    if n < 0 then slice xs 0 m else
    if m >= length xs then slice xs n ((length xs) - 1) else 
    slice' xs n m
    where
        slice' (x:xs) 0 m = x:(slice xs 0 (m - 1))
        slice' (x:xs) n m = slice xs (n - 1) (m - 1)