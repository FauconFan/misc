-- copied from correction
import Data.List (sortBy, insertBy)
import Data.Ord (comparing)
import Control.Arrow (second)
 
huffman :: [(Char, Int)] -> [(Char, String)]
huffman =
  let shrink [(_, ys)] = sortBy (comparing fst) ys
      shrink (x1:x2:xs) = shrink $ insertBy (comparing fst) (add x1 x2) xs
      add (p1, xs1) (p2, xs2) =
        (p1 + p2, map (second ('0':)) xs1 ++ map (second ('1':)) xs2)
  in  shrink . map (\(c, p) -> (p, [(c ,"")])) . sortBy (comparing snd)