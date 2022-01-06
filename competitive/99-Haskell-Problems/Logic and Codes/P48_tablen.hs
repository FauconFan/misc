-- copied from correction
import Control.Monad (replicateM)
 
-- functions as in solution 46
infixl 4 `or'`
infixl 4 `nor'`
infixl 5 `xor'`
infixl 6 `and'`
infixl 6 `nand'`
infixl 7 `equ'`

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
 
tablen :: Int -> ([Bool] -> Bool) -> IO ()
tablen n f = mapM_ putStrLn [toStr a ++ " => " ++ show (f a) | a <- args n]
    where args n = replicateM n [True, False]
          toStr = unwords . map (\x -> show x ++ space x)
          space True = "  "
          space False = " "