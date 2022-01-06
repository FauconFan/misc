compress :: (Eq a) => [a] -> [a]
compress [] = []
compress [x] = [x]
compress (x:y:xs) = if x == y then compress (x:xs) else [x] ++ compress (y:xs)