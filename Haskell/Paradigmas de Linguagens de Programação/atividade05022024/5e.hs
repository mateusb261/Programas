data Termo = Termo { coef :: Int, grau :: Int } deriving (Eq, Show)

grauTermo :: Termo -> Int
grauTermo t = grau t

grauTermos :: [Termo] -> Int
grauTermos [] = error "Polinômio vazio não tem grau"
grauTermos [t] = grauTermo t
grauTermos (t:ts) = max (grauTermo t) (grauTermos ts)

mostraPolinomio :: [Termo] -> String
mostraPolinomio [] = ""
mostraPolinomio [t] = mostraTermo t
mostraPolinomio (t:ts) = mostraTermo t ++ " + " ++ mostraPolinomio ts

mostraTermo :: Termo -> String
mostraTermo t = show (coef t) ++ "x^" ++ show (grau t)

main :: IO ()
main = do
  let termos = [Termo 5 1, Termo 3 2, Termo (-2) 0, Termo 4 3]
  let grau = grauTermos termos
  putStrLn ("O grau do polinômio " ++ mostraPolinomio termos ++ " é " ++ show grau)
