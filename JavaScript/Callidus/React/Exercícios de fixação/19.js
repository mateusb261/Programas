function maiorString(array) {
  let maior = array[0];

  for (let string of array) {
    if (string.length > maior.length) {
      maior = string;
    }
  }

  return maior;
}

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Digite um array de strings separados por vírgulas: ', (resposta) => {
    let array = resposta.split(',');
    let maior_string = maiorString(array);
    console.log("A maior string do array fornecido é: " + maior_string + ".");

  rl.close();
});