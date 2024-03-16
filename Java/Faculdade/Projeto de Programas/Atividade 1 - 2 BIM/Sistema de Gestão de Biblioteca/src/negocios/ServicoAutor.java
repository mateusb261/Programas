package negocios;

import dados.Autor;
import dados.Livro;
import java.util.ArrayList;

// Classe abstrata que define os serviços relacionados a autores
public abstract class ServicoAutor {

    /* Método abstrato: */

    // Para cadastrar um novo autor;
    public abstract Autor cadastrarAutor(String nome, String nacionalidade);
    // Atualizar informações de um autor;
    public abstract void atualizarAutor(int Id, String novoNome, String novaNacionalidade);
    // Remover um autor;
    public abstract void removerAutor(String nome);
    // Buscar um autor por ID;
    public abstract Autor buscarAutorPorId(int id);
    // Buscar um autor por nome;
    public abstract Autor buscarAutorPorNome(String nome);
    // Listar todos os autores;
    public abstract ArrayList<Autor> listarAutores();
}

