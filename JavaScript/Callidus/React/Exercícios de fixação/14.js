function positivos(array) {
  let resultado = [];

  for (let numero of array) {
    if (numero > 0) {
      resultado.push(numero);
    }
  }

  return resultado;
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
    let resultado = positivos(array);
    console.log('O array contendo somente números positivos é ' + resultado + '.');
  }

  rl.close();
});