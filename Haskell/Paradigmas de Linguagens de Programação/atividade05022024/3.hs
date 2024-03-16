triangulo :: Double -> Double -> Double -> Bool
triangulo a b c = a + b > c && a + c > b && b + c > a

main :: IO ()
main = do
  let x = 3.0
  let y = 4.0
  let z = 5.0
  let t = triangulo x y z
  print t
