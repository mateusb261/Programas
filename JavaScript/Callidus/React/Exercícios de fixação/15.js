function maiorNumero(array) {
  let maior = array[0];

  for (let numero of array) {
    if (numero > maior) {
      maior = numero;
    }
  }

  return maior;
}

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Digite um array de números separados por vírgulas: ', (resposta) => {
  let array = resposta.split(',').map(Number);

  if (array.some(isNaN)) {
    console.log('Isso não é um array válido.');
  } else {
    let resultado = maiorNumero(array);
    console.log('O maior elemento do array fornecido é: ' + resultado + '.');
  }

  rl.close();
});