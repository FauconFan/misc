import Data.List

and' :: Bool -> Bool -> Bool
and' True True = True
and' _ _ = False

or' :: Bool -> Bool -> Bool
or' False False = False
or' _ _ = True

not' :: Bool -> Bool
not' True = False
not' False = True

table2 :: (Bool -> Bool -> Bool) -> IO ()
table2 f = putStrLn $ intercalate ("\n") [show a ++ " " ++ show b ++ " " ++ show (f a b) | a <- [True, False], b <- [True, False] ]