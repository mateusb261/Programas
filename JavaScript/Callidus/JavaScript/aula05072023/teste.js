var objeto = new Object();

var nave = {
    nome:"Enterprise";
    propulsao: "Gerador de sobra";
    proprietário: "Kirk";
}


funcion calc_consumo(distancia){
    return distancia/(15/this.motor);
}

//classe que representa um carro

funcion Carro(modelo, marca, ano, motor){
	this.modelo = modelo;
	this.marca = marca;
	this.ano = ano;
	this.motor = motor;
}

Carro.prototype.rodas = 4;
Carro.prototype.consumo = calc_consumo;

var car1 = new Carro("G800", "Gurgel", 1976, 1.0);
var car2 = new Carro("147", "Fiat", 1984, 2.0);

if(car1.rodas == 4) window.alert("ainda BEM!");
var fas = car2.consumo(100);


//valueOf - retorna o valor primitivo do objeto string. É útil quando desejamos atribuir o valor de um objeto string para uma variável que seja de tipo primitivo String.

exemplo:
var stob = new String("gerador de campos PQP");
var str = stob.valueOf();

//stob será um objeto de tipo Object e str será uma variável primitiva do tipo string

//charAt(pos) - retorna uma string contendo o caracter de posição pos da string. se nao existir nenhum caractere nessa posição, o resultado é uma string vazia.

//exemplo:
var str = "Millways";
car carac = str.charAt(5); //retornará w

//concat(string1, string2, ..., stringn) - este método retorna uma string
//contendo a própria string de qual o método foi chamado e todos os caracteres
//das strings que lhe foram passadas como argumentos, na ordem em que foram fornecidas.

//exemplo:

var str 1 = "Praticamente ", str2 = "Inofensiva";
var result = str1.concat(str2);

//indexOf(padrao, pos) - procura a ocorrência da string contida em padrao
//a partir da posição pos dentro da string sobre a qual se invocou este método e
//retorna o índice da primeira ocorrência.

exemplo:
var cachalote = "Vou chamar isso de cauda, cauda é um bom nome!";
var ind1 = cachalote.lastIndexOf("cauda");
var ind2 = cachalote.lastIndexOf("cauda", 25);
var ind3 = cachalote.lastIndexOf("mustafa");

replace(velho, novo)

//exemplo:

var a = "Não se esqueça da sua toalha!";
var res1 = a.replace("toalha", "mochila");
var res2 = a.replace("bicicleta", "mochila");

funcion up(sub, pos, str){
    return sub.toUpperCase();
}

var a = "Não se esqueça da sua toalha!";
var res = a.replace("toalha", up);

//search(padrao)

var str = "A vida é louca, meus amigos";
var res1 = str.search("amigos");
var res1 = str.search("narigao");

//slice(inicio, fim)

//exemplo:
var str = "Ate mais e obrigado pelos peixes";
var res1 = str.slice(11);
var res2 = str.slice(11, 20);
var res3 = str.slice(-7, -1);

//split(separador, limite)

//exemplo:
var dados = "Terra, Marte, Jupiter";
var arr1 = dados.split(", ");
var arr2 = dados.split(", ", 2);



SMA 262-3