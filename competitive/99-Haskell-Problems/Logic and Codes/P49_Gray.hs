gray :: Int -> [String]
gray 0 = [""]
gray n = (++) <$> ["0", "1"] <*> gray (n - 1)