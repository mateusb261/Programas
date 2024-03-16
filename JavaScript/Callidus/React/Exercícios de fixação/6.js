function inverter(numero) {
  let string = numero.toString();
  let invertida = string.split('').reverse().join('');
  let resultado = Number(invertida);

  return resultado;
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
    let resultado = inverter(numero);
    console.log('O número invertido de ' + numero + ' é ' + resultado + '.');
  }

  rl.close();
});
