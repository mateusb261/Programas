somaProd :: (Int, Int) -> (Int, Int) -> (Int, Int)
somaProd (a, b) (c, d) = (a + c, b * d)

main :: IO ()
main = do
  let x = (2, 3)
  let y = (4, 5)
  let z = somaProd x y
  print z
