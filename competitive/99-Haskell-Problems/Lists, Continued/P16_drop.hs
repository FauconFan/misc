dropN :: [a] -> Int -> [a]
dropN [] n = []
dropN x n = drop' x 1 n
    where
        drop' [] actu n = []
        drop' (x:xs) actu n = if mod actu n == 0 then drop' xs (actu + 1) n else x:(drop' xs (actu + 1) n)