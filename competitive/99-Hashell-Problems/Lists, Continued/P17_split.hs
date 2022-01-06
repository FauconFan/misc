split :: [a] -> Int -> [[a]]
split [] n = []
split x 0 = [x]
split (x:xs) n = [(x:x1), x2] 
    where 
        xss = split xs (n - 1)
        x1 = if (length xss == 2) then xss !! 0 else []
        x2 = if (length xss == 2) then xss !! 1 else 
            if (length xss == 1) then xss !! 0 else []