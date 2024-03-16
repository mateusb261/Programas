insertionSort :: [Int] -> [Int]
insertionSort [] = []
insertionSort (x:xs) = insert x (insertionSort xs)

insert :: Int -> [Int] -> [Int]
insert x [] = [x]
insert x (y:ys) = if x <= y then x : y : ys else y : insert x ys

main :: IO ()
main = do
  let l = [5, 3, 7, 1, 9, 4, 2, 6, 8]
  let s = insertionSort l
  print s
