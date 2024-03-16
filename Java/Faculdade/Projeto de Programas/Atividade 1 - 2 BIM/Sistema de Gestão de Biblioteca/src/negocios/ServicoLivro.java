package negocios;

import dados.Autor;
import dados.Editora;
import dados.Livro;

import java.util.ArrayList;

// Classe abstrata que define os serviços relacionados a livros
public abstract class ServicoLivro {
    /* Método abstrato */

    // Para cadastrar um novo livro
    public abstract void cadastrarLivro(String titulo, Autor autor, Editora editora);
    // Atualizar informações de um livro
    public abstract void atualizarLivro(String tituloAntigo, String novoTitulo, Autor novoAutor, Editora novaEditora);
    // Remover um livro
    public abstract void removerLivro(String titulo);
    // Buscar um livro por título
    public abstract Livro buscarLivroPorTitulo(String titulo);
    // Listar todos os livros
    public abstract ArrayList<Livro> listarLivros();
}
