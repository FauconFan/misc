elementAt :: [a] -> Int -> a
elementAt [] n = error "error"
elementAt x 0 = error "error"
elementAt x 1 = head x
elementAt [x] n = x
elementAt (x:xs) n = elementAt xs (n - 1)