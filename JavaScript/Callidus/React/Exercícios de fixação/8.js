function montante(capital, tempo, taxa) {
  taxa = taxa / 100;
  let resultado = capital * Math.pow(1 + taxa, tempo);

  return resultado.toFixed(2);
}

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Digite o capital inicial: ', (resposta1) => {
  rl.question('Digite o tempo em meses: ', (resposta2) => {
    rl.question('Digite a taxa de juros mensal em percentual: ', (resposta3) => {
      let capital = Number(resposta1);
      let tempo = Number(resposta2);
      let taxa = Number(resposta3);

      if (isNaN(capital) || isNaN(tempo) || isNaN(taxa)) {
        console.log('Algum dos valores digitados não é um número válido.');
      } else {
        let resultado = montante(capital, tempo, taxa);
        console.log('O montante do investimento é ' + resultado + '.');
      }

      rl.close();
    });
  });
});
