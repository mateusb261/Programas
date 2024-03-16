data Termo = Termo { coef :: Int, grau :: Int } deriving (Eq, Show)

derivTermo :: Termo -> Termo
derivTermo t = Termo (coef t * grau t) (grau t - 1)

derivTermos :: [Termo] -> [Termo]
derivTermos [] = []
derivTermos (t:ts) = derivTermo t : derivTermos ts

mostraPolinomio :: [Termo] -> String
mostraPolinomio [] = ""
mostraPolinomio [t] = mostraTermo t
mostraPolinomio (t:ts) = mostraTermo t ++ " + " ++ mostraPolinomio ts

mostraTermo :: Termo -> String
mostraTermo t = show (coef t) ++ "x^" ++ show (grau t)

main :: IO ()
main = do
  let termos = [Termo 5 1, Termo 3 2, Termo (-2) 0, Termo 4 3]
  let derivada = derivTermos termos
  putStrLn ("A derivada do polinômio " ++ mostraPolinomio termos ++ " é " ++ mostraPolinomio derivada)
