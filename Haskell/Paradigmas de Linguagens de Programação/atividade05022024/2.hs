maxSegundo :: Int -> Int -> Int -> (Int, Int)
maxSegundo x y z = (m, s)
  where
    m = maximum [x, y, z]
    s = if x == m then max y z else if y == m then max x z else max x y

main :: IO ()
main = do
  let a = 10
  let b = 7
  let c = 9
  let d = maxSegundo a b c
  print d
