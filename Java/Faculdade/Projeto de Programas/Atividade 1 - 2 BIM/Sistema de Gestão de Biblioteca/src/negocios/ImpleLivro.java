package negocios;

import dados.Autor;
import dados.Editora;
import dados.Livro;
import java.util.ArrayList;

public class ImpleLivro extends ServicoLivro {
    private ArrayList<Livro> listaDeLivros;

    // Construtor da classe, inicializa a lista de livros
    public ImpleLivro() {
        listaDeLivros = new ArrayList<>();
    }

    /* Método para cadastrar um novo livro */
    @Override
    public void cadastrarLivro(String titulo, Autor autor, Editora editora) {
        // Cria um novo livro e adiciona-o à lista de livros
        Livro livro = new Livro(titulo, autor, editora);
        listaDeLivros.add(livro);
        // Adiciona o livro às listas de livros do autor e da editora
        autor.adicionarLivro(livro);
        editora.adicionarLivro(livro);
        // Salva o livro em um arquivo (assumindo que esse método está definido em Livro)
        livro.saveLivroToFile();
    }

    /* Método para atualizar informações de um livro */
    @Override
    public void atualizarLivro(String tituloAntigo, String novoTitulo, Autor novoAutor, Editora novaEditora) {
        // Busca o livro pelo título antigo
        Livro livro = buscarLivroPorTitulo(tituloAntigo);
        // Atualiza o título, autor e editora do livro caso ele seja encontrado
        if (livro != null) {
            livro.setTitulo(novoTitulo);
            livro.setAutor(novoAutor);
            livro.setEditora(novaEditora);
        } else {
            System.out.println("Livro não encontrado. Atualização não realizada.");
        }
    }

    /* Método para remover um livro */
    @Override
    public void removerLivro(String titulo){
        // Busca o livro pelo título
        Livro livro = buscarLivroPorTitulo(titulo);
        if (livro != null) {
            // Remove o livro da lista de livros, do autor e da editora
            listaDeLivros.remove(livro);
            livro.getAutor().getLivrosAutor().remove(livro);
            livro.getEditora().getLivrosEditora().remove(livro);
        } else {
            System.out.println("Livro não encontrado. Remoção não realizada.");
        }
    }

    /* Método para buscar um livro pelo título */
    @Override
    public Livro buscarLivroPorTitulo(String titulo) {
        for (Livro livro : listaDeLivros) {
            if (livro.getTitulo().equals(titulo)) {
                return livro;
            }
        }
        // Retorna nulo se o livro não for encontrado
        return null;
    }

    /* Método para listar todos os livros */
    @Override
    public ArrayList<Livro> listarLivros() {
        return listaDeLivros;
    }
}
