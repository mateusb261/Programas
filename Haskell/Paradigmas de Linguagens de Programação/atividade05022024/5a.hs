-- Define um tipo para representar um termo de um polinômio
data Termo = Termo { coef :: Int, grau :: Int } deriving (Eq, Show)

-- Define uma função para comparar dois termos pelo grau
comparaTermo :: Termo -> Termo -> Ordering
comparaTermo t1 t2 = compare (grau t1) (grau t2)

-- Define uma função para ordenar uma lista de termos pelo grau
ordenaTermos :: [Termo] -> [Termo]
ordenaTermos = sortBy comparaTermo

-- Define uma função para converter uma lista de termos em uma string
mostraPolinomio :: [Termo] -> String
mostraPolinomio [] = ""
mostraPolinomio [t] = mostraTermo t
mostraPolinomio (t:ts) = mostraTermo t ++ " + " ++ mostraPolinomio ts

-- Define uma função auxiliar para converter um termo em uma string
mostraTermo :: Termo -> String
mostraTermo t = show (coef t) ++ "x^" ++ show (grau t)

-- Define uma função principal que recebe uma lista de termos e ordena e mostra o polinômio correspondente
main :: IO ()
main = do
  let termos = [Termo 5 1, Termo 3 2, Termo (-2) 0, Termo 4 3] -- Exemplo de entrada
  let polinomio = ordenaTermos termos -- Ordena os termos pelo grau
  putStrLn (mostraPolinomio polinomio) -- Mostra o polinômio ordenado
