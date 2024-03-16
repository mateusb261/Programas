data Termo = Termo { coef :: Int, grau :: Int } deriving (Eq, Show)

avalTermo :: Termo -> Int -> Int
avalTermo t x = coef t * x ^ grau t

avalTermos :: [Termo] -> Int -> Int
avalTermos [] x = 0
avalTermos (t:ts) x = avalTermo t x + avalTermos ts x

mostraPolinomio :: [Termo] -> String
mostraPolinomio [] = ""
mostraPolinomio [t] = mostraTermo t
mostraPolinomio (t:ts) = mostraTermo t ++ " + " ++ mostraPolinomio ts

mostraTermo :: Termo -> String
mostraTermo t = show (coef t) ++ "x^" ++ show (grau t)

main :: IO ()
main = do
  let termos = [Termo 5 1, Termo 3 2, Termo (-2) 0, Termo 4 3]
  let ponto = 2
  let valor = avalTermos termos ponto
  putStrLn ("O valor do polinômio " ++ mostraPolinomio termos ++ " no ponto " ++ show ponto ++ " é " ++ show valor)
