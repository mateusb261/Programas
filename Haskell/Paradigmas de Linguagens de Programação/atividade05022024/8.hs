mergeSort :: [Int] -> [Int]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs = merge (mergeSort ys) (mergeSort zs)
  where
    (ys, zs) = splitAt (length xs `div` 2) xs

merge :: [Int] -> [Int] -> [Int]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys) = if x <= y then x : merge xs (y:ys) else y : merge (x:xs) ys

main :: IO ()
main = do
  let l = [5, 3, 7, 1, 9, 4, 2, 6, 8]
  let s = mergeSort l
  print s
