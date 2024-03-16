package negocios;

import dados.Autor;
import dados.Livro;
import java.util.ArrayList;

public class ImpleAutor extends ServicoAutor {
    private ArrayList<Autor> listaDeAutores;

    // Construtor da classe, inicializa a lista de autores
    public ImpleAutor() {
        listaDeAutores = new ArrayList<>();
    }

    /* Método para cadastrar um autor */
    @Override
    public Autor cadastrarAutor(String nome, String nacionalidade){
        // Cria um novo autor além de adicionar o autor à lista e chamando o método
        Autor autor = new Autor(nome, nacionalidade);
        listaDeAutores.add(autor);
        autor.adicionarAutor();
        // Salva o autor em um arquivo (assumindo que esse método está definido em Autor)
        autor.saveAutorToFile();
        // Retorna o autor criado
        return autor;
    }

    /* Método para atualizar informações de um autor */
    @Override
    public void atualizarAutor(int Id, String novoNome, String novaNacionalidade) {
        // Busca o autor pelo ID
        Autor autor = buscarAutorPorId(Id);
        // Atualiza o nome do autor e a nacionalidade do autor caso o autor seja encontrado
        if (autor != null) {
            autor.setNome(novoNome);
            autor.setNacionalidade(novaNacionalidade);
        } else {
            System.out.println("Autor não encontrado. Atualização não realizada.");
        }
    }

    /* Método para remover um autor */
    @Override
    public void removerAutor(String nome) {
        // Busca o autor pelo nome
        Autor autor = buscarAutorPorNome(nome);
        // Remove o autor da lista e chama um método (assumindo que ele realiza ações adicionais)
        // Ou retorna uma saída avisando que o autor não foi encontrado
        if (autor != null) {
            listaDeAutores.remove(autor);
            autor.removerAutor();
        } else {
            System.out.println("Autor não encontrado. Remoção não realizada.");
        }
    }

    // Método para buscar um autor por ID
    @Override
    public Autor buscarAutorPorId(int id) {
        for (Autor autor :  listaDeAutores) {
            if (autor.getId() == id) {
                return autor;
            }
        }
        // Retorna nulo se o autor não for encontrado
        return null;
    }

    // Método para buscar um autor por nome
    @Override
    public Autor buscarAutorPorNome(String nome) {
        for (Autor autor : listaDeAutores) {
            if (autor.getNome().equals(nome)) {
                return autor;
            }
        }
        // Retorna nulo se o autor não for encontrado
        return null;
    }

    // Método para listar todos os autores
    @Override
    public ArrayList<Autor> listarAutores() {
        return listaDeAutores;
    }
}
