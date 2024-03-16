// Essa interface descreve os métodos relacionados a operações de empréstimo e devolução de livros.
package negocios;
// Importa a classe Livro para ser usada nos métodos.
import dados.Livro;

public interface EmprestimoService {
  /* Método */

  // Para emprestar um livro a um usuário;
  public boolean emprestarLivro(Livro livro, String nomeUsuario);
  // Devolver um livro que foi emprestado;
  public boolean devolverLivro(Livro livro, String nomeUsuario);
}

