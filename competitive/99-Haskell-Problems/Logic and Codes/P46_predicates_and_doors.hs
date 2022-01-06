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

equ' :: Bool -> Bool -> Bool
equ' True True = True
equ' False False = True
equ' _ _ = False

nor' :: Bool -> Bool -> Bool
nor' b c = not' $ or' b c

nand' :: Bool -> Bool -> Bool
nand' b c = not' $ and' b c

xor' :: Bool -> Bool -> Bool
xor' b c = not' $ equ' b c

impl' :: Bool -> Bool -> Bool
impl' b c = let d = not' b in or' d c

table :: (Bool -> Bool -> Bool) -> IO ()
table f = putStrLn $ intercalate ("\n") [show a ++ " " ++ show b ++ " " ++ show (f a b) | a <- [True, False], b <- [True, False] ]