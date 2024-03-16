fatorial :: Int -> Int
fatorial 0 = 1
fatorial n = n * fatorial (n-1)

main :: IO ()
main = do
  let n = 5
  let f = fatorial n
  putStrLn ("O fatorial de " ++ show n ++ " é " ++ show f)