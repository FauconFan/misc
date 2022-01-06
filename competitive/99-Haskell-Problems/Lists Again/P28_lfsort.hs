 -- Copied from the solution
import List
 
lsort :: [[a]] -> [[a]]
lsort = sortBy (\xs ys -> compare (length xs) (length ys))

lfsort :: [[a]] -> [[a]]
lfsort l = sortBy (\xs ys -> compare (frequency (length xs) l) (frequency (length ys) l)) l