function contarCaractere(caractere, string) {
  let contador = 0;

  for (let c of string) {
    if (c === caractere) {
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

rl.question('Digite um caractere: ', (resposta1) => {
  rl.question('Digite uma string: ', (resposta2) => {
    let resultado = contarCaractere(resposta1, resposta2);
    console.log('O caractere "' + resposta1 + '" aparece ' + resultado + ' vezes na string "' + resposta2 + '".');

    rl.close();
  });
});
