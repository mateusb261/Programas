/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
	Curso: Sistemas de Informação
*/

public class Main {
    public static void main(String[] args) {

        /* Criando leitores */

        Leitor Marcos = new Leitor("Marcos Silva");
        Leitor Jose = new Leitor("José Silva");

        /* Criando autores */

        Autor Tulio = new Autor("Túlio Santos", "Brasileiro");
        Autor Paulo = new Autor("Paulo Santos", "Brasileiro");

        /* Criando livros utilizando o método "criarLivro" pertencente à classe "Autor",
        ilustrando a relação de Composição entre as classes "Livro" e "Autor" */

        Tulio.criarLivro("O patinho feio", Tulio);
        Paulo.criarLivro("Cinderela", Paulo);

        /* Criando livros pelo método construtor e adicionando cada livro à lista de
        cada autor */

        Livro chapeuzinhoVermelho = new Livro("Chapeuzinho vermelho", Tulio);
        Tulio.addLivro(chapeuzinhoVermelho);

        Livro aBelaEAFera = new Livro("A Bela e a Fera", Tulio);
        Tulio.addLivro(aBelaEAFera);

        Livro osTrêsPorquinhos = new Livro("Os três porquinhos", Paulo);
        Paulo.addLivro(osTrêsPorquinhos);

        Livro aBrancaDeNeve = new Livro("A Branca de Neve", Paulo);
        Paulo.addLivro(aBrancaDeNeve);

        /* Adicionando livros à lista de livros emprestados de cada leitor e adicionando
        leitores a cada lista de livros */

        Marcos.addLivro(chapeuzinhoVermelho);
        chapeuzinhoVermelho.addLeitor(Marcos);

        Marcos.addLivro(osTrêsPorquinhos);
        osTrêsPorquinhos.addLeitor(Marcos);

        Jose.addLivro(aBelaEAFera);
        aBelaEAFera.addLeitor(Jose);

        Jose.addLivro(aBrancaDeNeve);
        aBrancaDeNeve.addLeitor(Jose);

        /* Imprimindo os livros escritos por cada autor */

        System.out.println(Tulio.getLivros());
        System.out.println(Paulo.getLivros());

        /* Imprimindo os livros emprestados por cada leitor */

        System.out.println(Marcos.getLivros());
        System.out.println(Jose.getLivros());

        /* Imprimindo os leitores de cada livro */

        System.out.println(chapeuzinhoVermelho.getLeitores());
        System.out.println(aBelaEAFera.getLeitores());
        System.out.println(osTrêsPorquinhos.getLeitores());
        System.out.println(aBrancaDeNeve.getLeitores());
    }
}