data Termo = Termo { coef :: Rational, grau :: Int } deriving (Eq, Show)
coefMax :: [Termo] -> Rational
coefMax [] = error "Polinômio vazio não pode ser normalizado"
coefMax [t] = coef t
coefMax (t:ts) = max (coef t) (coefMax ts)

divTermo :: Termo -> Rational -> Termo
divTermo t x = Termo (coef t / x) (grau t)

normTermos :: [Termo] -> [Termo]
normTermos ts = map (\t -> divTermo t c) ts
  where c = coefMax ts

mostraPolinomio :: [Termo] -> String
mostraPolinomio [] = ""
mostraPolinomio [t] = mostraTermo t
mostraPolinomio (t:ts) = mostraTermo t ++ " + " ++ mostraPolinomio ts

mostraTermo :: Termo -> String
mostraTermo t = show (coef t) ++ "x^" ++ show (grau t)

main :: IO ()
main = do
  let termos = [Termo 2 3, Termo 4 2, Termo (-1) 1, Termo 3 0] -- Exemplo de entrada
  let polinomio = normTermos termos -- Normaliza os termos
  putStrLn (mostraPolinomio polinomio) -- Mostra o polinômio normalizado
