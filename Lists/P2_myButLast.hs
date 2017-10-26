myButLast :: [a] -> a
myButLast [] = error "error"
myButLast [_] = error "error"
myButLast (x:_:[]) = x
myButLast (x:xs) = myButLast xs