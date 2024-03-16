/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
	Curso: Sistemas de Informação
*/

import java.util.ArrayList;

public class Autor {
    private String nome;
    private String nacionalidade;
    private ArrayList<Livro>livros = new ArrayList<>();

    public Autor(String nome, String nacionalidade) {
        this.nome = nome;
        this.nacionalidade = nacionalidade;
    }

    public String getNome() {
        return this.nome;
    }

    public void criarLivro(String titulo, Autor autor) {
        livros.add(new Livro(titulo, autor));
    }

    public void addLivro(Livro livro) {
        this.livros.add(livro);
    }

    public String getLivros() {
        String lista = "Lista de livros escritos pelo autor " + this.nome + " (Nacionalidade: " + this.nacionalidade + "):\n";
        for (int i = 0; i < this.livros.size(); i++) {
            lista += this.livros.get(i).getTitulo() + "\n";
        }
        return lista;
    }
}