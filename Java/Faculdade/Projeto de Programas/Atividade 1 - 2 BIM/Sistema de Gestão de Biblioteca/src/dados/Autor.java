package dados;

import java.util.ArrayList;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Autor {

    /* Atributos */

    private static int contadorId = 0;
    private int id;
    private String nome;
    private String nacionalidade;
    private ArrayList<Livro> livrosAutor;
    private static ArrayList<Autor> listaDeAutores = new ArrayList<>();
    private static final String LISTA_AUTORES = "Lista de autores.txt";
    private static int autoresArquivo = 0;
    private int autorSalvoNoArquivo = 0;

    /* Construtor */

    public Autor(String nome, String nacionalidade) {
        this.id = ++contadorId;
        this.nome = nome;
        this.nacionalidade = nacionalidade;
        this.livrosAutor = new ArrayList<>();
    }


    /* Getters e setters */

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;

    }

    public String getNacionalidade() {
        return nacionalidade;
    }

    public void setNacionalidade(String nacionalidade) {
        this.nacionalidade = nacionalidade;
    }

    public int getId() {
        return id;
    }

    public void setId(int novoId) {

        // Verifica se o novoId já está em uso por outro autor
        for (Autor autor : listaDeAutores) {
            if (autor.getId() == novoId) {
                System.out.println("ID já está em uso por outro autor. Não foi possível alterar o ID.");
                return;
            }
        }
        // Se não está em uso, pode-se alterar o ID
        id = novoId;
    }

    public ArrayList<Livro> getLivrosAutor() {
        return livrosAutor;
    }


    /* Outras funções */

    public void adicionarLivro(Livro livro) {
        livrosAutor.add(livro);
    }

    public void adicionarAutor() {
        listaDeAutores.add(this);
    }

    public void removerAutor() {
        listaDeAutores.remove(this);
    }

    public void saveAutorToFile() {
    if (autorSalvoNoArquivo == 0) {
      try (PrintWriter writer = new PrintWriter(new FileWriter(LISTA_AUTORES, true))) {

        if (autoresArquivo == 0) {
          writer.println("Lista de autores");
          writer.println("");
        }

        writer.println(nome);

        autorSalvoNoArquivo = 1;
        autoresArquivo++;

      } catch (IOException e) {
        System.err.println("Erro ao escrever no arquivo: " + e.getMessage());
      }
    }
  }
}