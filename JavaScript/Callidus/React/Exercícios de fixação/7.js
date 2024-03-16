function contarVogais(string) {
  let vogais = new Set(['a', 'e', 'i', 'o', 'u']);
  let contador = 0;

  for (let caractere of string) {
    caractere = caractere.toLowerCase();

    if (vogais.has(caractere)) {
      contador++;
    }
  }

  return contador;
}

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Digite uma string: ', (resposta) => {
  let resultado = contarVogais(resposta);
  console.log('A string "' + resposta + '" tem ' + resultado + ' vogais.');

  rl.close();
});
