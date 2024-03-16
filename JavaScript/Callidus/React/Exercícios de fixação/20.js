function unirArrays(array1, array2) {
    let array_final = array1.concat(array2);

    return array_final;
}

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Digite o primeiro array: ', (resposta1) => {
  rl.question('Digite o segundo array: ', (resposta2) => {
      let array_final = unirArrays(resposta1, resposta2);
      console.log("O array resultante da união é: " + array_final + ".");
      rl.close();
  });
});
