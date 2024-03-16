function gerarFibonachi(quantidade) {
    let array = new Array(quantidade);
    array[0] = 1;
    array[1] = 1;

    for (let i = 2; i < quantidade; i++) {
        array[i] = array[i - 1] + array[i - 2];
    }

  return array;
}

arrayFibonachi = gerarFibonachi(10);
console.log("Os 10 primeiros números da sequência de Fibonacci é: " + arrayFibonachi);
