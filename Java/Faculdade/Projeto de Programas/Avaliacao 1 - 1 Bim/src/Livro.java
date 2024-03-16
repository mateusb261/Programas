/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
	Curso: Sistemas de Informação
*/

import java.util.ArrayList;

public class Livro {
    private String titulo;
    private Autor autor;
    private ArrayList<Leitor>leitores = new ArrayList<>();
    public Livro(String titulo, Autor autor) {
        this.titulo = titulo;
        this.autor = autor;
    }

    public String getAutor() {
        return this.autor.getNome();
    }

    public String getTitulo() {
        return this.titulo;
    }

    public void addLeitor(Leitor leitor) {
        this.leitores.add(leitor);
    }

    public String getLeitores() {
        String lista = "Lista de leitores que emprestaram o livro " + this.titulo + ":\n";
        for (int i = 0; i < this.leitores.size(); i++) {
            lista += this.leitores.get(i).getNome() + "\n";
        }
        return lista;
    }
}