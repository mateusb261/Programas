package dados;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Editora {

  /* Atributos */

  private String nome;
  private String localizacao;
  private ArrayList<Livro> livrosEditora;
  private ArrayList<Autor> autoresEditora;
  private static final String LISTA_EDITORAS = "Lista de Editoras.txt";
  private static int editorasArquivo = 0;
  private int editoraSalvaNoArquivo = 0;


  /* Construtor */

  public Editora(String nome, String localizacao) {
    this.nome = nome;
    this.localizacao = localizacao;
    this.livrosEditora = new ArrayList<>();
    this.autoresEditora = new ArrayList<>();
  }


  /* Getters e setters */

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getLocalizacao() {
    return localizacao;
  }

  public void setLocalizacao(String localizacao) {
    this.localizacao = localizacao;
  }

  public ArrayList<Livro> getLivrosEditora() {
    return livrosEditora;
  }

  public ArrayList<Autor> getAutoresEditora() {
    return autoresEditora;
  }


  /* Outras funções */

  public void adicionarLivro(Livro livro) {
    livrosEditora.add(livro);
  }

  public Autor encontrarAutor(String tituloLivro) {
    for (Livro livro : livrosEditora) {
      if (livro.getTitulo().equals(tituloLivro)) {
        return livro.getAutor();
      }
    }
    // Exceçao
    return null;
  }

  public void saveEditoraToFile() {
    if (editoraSalvaNoArquivo == 0) {
      try (PrintWriter writer = new PrintWriter(new FileWriter(LISTA_EDITORAS, true))) {

        if (editorasArquivo == 0) {
          writer.println("Lista de editoras");
          writer.println("");
        }

        writer.println(nome);

        editoraSalvaNoArquivo = 1;
        editorasArquivo++;

      } catch (IOException e) {
        System.err.println("Erro ao escrever no arquivo: " + e.getMessage());
      }
    }
  }
}