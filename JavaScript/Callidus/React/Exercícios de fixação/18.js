function primo(numero) {
  if (numero < 2 || !Number.isInteger(numero)) {
    return false;
  }

  let raiz = Math.sqrt(numero);
  for (let divisor = 2; divisor <= raiz; divisor++) {
    if (numero % divisor === 0) {
      return false;
    }
  }

  return true;
}

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Digite um número: ', (resposta) => {
  let numero = Number(resposta);

  if (isNaN(numero)) {
    console.log('Isso não é um número válido.');
  } else {
    let resultado = primo(numero);
    if (resultado) {
      console.log('O número ' + numero + ' é primo.');
    } else {
      console.log('O número ' + numero + ' não é primo.');
    }
  }

  rl.close();
});
