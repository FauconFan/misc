import System.Random

rnd_permu :: [a] -> IO [a]
rnd_permu [] = return []
rnd_permu xs = do
    rand <- randomRIO (0, (length xs)-1)
    rest <- let (ys,(_:zs)) = splitAt rand xs
            in rnd_permu $ ys ++ zs
    return $ (xs !! rand):rest