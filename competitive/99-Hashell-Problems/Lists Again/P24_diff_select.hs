import System.Random
import Data.List

diffSelect :: Int -> Int -> IO [Int]
diffSelect n m = do
    gen <- getStdGen
    return . take n $ nub $ randomRs (1, m) gen