selectionSort :: [Int] -> [Int]
selectionSort [] = []
selectionSort xs = x : selectionSort ys
  where
    x = minimum xs
    ys = delete x xs

delete :: Int -> [Int] -> [Int]
delete _ [] = []
delete x (y:ys) = if x == y then ys else y : delete x ys

main :: IO ()
main = do
  let l = [5, 3, 7, 1, 9, 4, 2, 6, 8]
  let s = selectionSort l
  print s
