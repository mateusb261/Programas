function fatorial(num) {
    let fatorial = num;

    for (i = (num - 1); i > 1; i--) {
        fatorial *= i;
    }

    return fatorial;
}

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Digite um número: ', (numero) => {
    let num = Number(numero);

    if (isNaN(num)) {
        console.log('O valor digitado não é um número válido.');
    }
    else {
        let resultado = fatorial(num);
        console.log('O fatorial do numero ' + num + ' é ' + resultado + '.');
    }
    rl.close();
});
