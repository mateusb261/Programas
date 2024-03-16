function mediaNumerosArray(string) {
  let total = 0;
  let contador = 0;
  let num_var;

  for (let c of string) {
    if (!isNaN(c)) {
      num_var = Number(c);
      total += num_var;
      contador++;
    }
  }
  total /= contador;

  return total;
}

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Digite um array de números separados por vírgulas: ', (resposta) => {
    let array = resposta.split(',').map(Number);
    let resultado = mediaNumerosArray(array);
    console.log('A média da soma dos números do array ' + resposta + ' é: ' + resultado + '.');

    rl.close();
});
