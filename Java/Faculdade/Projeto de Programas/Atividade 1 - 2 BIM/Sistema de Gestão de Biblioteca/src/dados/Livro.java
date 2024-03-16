package dados;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Livro {

    /* Atributos */

    private String titulo;
    private Autor autor;
    private Editora editora;
    private static final String FILE_NAME = "Lista de livros.txt";
    private static int livrosArquivo = 0;
    private int livroSalvoNoArquivo = 0;

    /* Construtor */

    public Livro(String titulo, Autor autor, Editora editora) {
        this.titulo = titulo;
        this.autor = autor;
        this.editora = editora;
    }


  /* Getters e setters */
    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public Autor getAutor() {
        return autor;
    }

    public void setAutor(Autor autor) {
        this.autor = autor;
    }

    public Editora getEditora() {
        return this.editora;
    }

    public void setEditora(Editora editora) {
        this.editora = editora;
    }


    /* Salvar livro para o arquivo da lista de livros criados */

    public void saveLivroToFile() {
        if (livroSalvoNoArquivo == 0) {
            try (PrintWriter writer = new PrintWriter(new FileWriter(FILE_NAME, true))) {

                if (livrosArquivo == 0) {
                  writer.println("Lista de livros");
                  writer.println("");
                  writer.println("");
                }

                writer.println("Título: " + titulo);
                writer.println("Autor: " + autor.getNome());
                writer.println("Editora: " + editora.getNome());
                writer.println();

                livroSalvoNoArquivo = 1;
                livrosArquivo++;

            } catch (IOException e) {
                System.err.println("Erro ao escrever no arquivo: " + e.getMessage());
            }
        }
    }
}
