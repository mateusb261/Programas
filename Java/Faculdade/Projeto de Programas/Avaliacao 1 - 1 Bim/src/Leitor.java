/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
	Curso: Sistemas de Informação
*/

import java.util.ArrayList;

public class Leitor {
    private String nome;
    private ArrayList<Livro>livros = new ArrayList<>();

    public Leitor(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return this.nome;
    }

    public void addLivro(Livro livro) {
        this.livros.add(livro);
    }

    public String getLivros() {
        String lista = "Lista de livros emprestados pelo leitor " + this.nome + ":\n";
        for (int i = 0; i < this.livros.size(); i++) {
            lista += this.livros.get(i).getTitulo() + "\n";
        }
        return lista;
    }
}