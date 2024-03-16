package negocios;

import dados.Editora;
import java.util.ArrayList;

public class ImpleEditora {
    // Lista de editoras mantida pela classe
    private ArrayList<dados.Editora> listaDeEditoras;

    // Construtor da classe, inicializa a lista de editoras
    public ImpleEditora() {
        listaDeEditoras = new ArrayList<>();
    }

    /* Método para cadastrar uma nova editora */
    public void cadastrarEditora(String nome, String localizacao) {
        // Cria um objeto Editora com o nome e a localização fornecidos
        dados.Editora editora = new dados.Editora(nome, localizacao);
        // Adiciona a editora à lista
        listaDeEditoras.add(editora);
        // Salva a editora em um arquivo (assumindo que esse método está definido em Editora)
        editora.saveEditoraToFile();
    }

    /* Método para atualizar informações de uma editora */
    public void atualizarEditora(String nomeAntigo, String novoNome, String novaLocalizacao) {
        // Busca a editora pelo nome antigo
        dados.Editora editora = buscarEditoraPorNome(nomeAntigo);
        // Atualiza o nome da editora
        editora.setNome(novoNome);
        // Atualiza a localização da editora
        editora.setLocalizacao(novaLocalizacao);
    }

    /* Método para remover uma editora */
    public void removerEditora(String nome) {
        Editora editora = buscarEditoraPorNome(nome);
        // Remove a editora da lista ou lança uma excessão caso a editora não seja encontrada
        if (editora != null) {
            listaDeEditoras.remove(editora);
        } else {
            throw new NullPointerException();
        }
    }

    /* Método para buscar uma editora pelo nome */
    public Editora buscarEditoraPorNome(String nome) {
        for (Editora editora : listaDeEditoras) {
            // Retorna a editora encontrada
            if (editora.getNome().equals(nome)) {
                return editora;
            }
        }
        // Retorna nulo se a editora não for encontrada
        return null;
    }

    /* Método para listar todas as editoras */
    public ArrayList<Editora> listarEditoras() {
        // Retorna a lista de editoras
        return listaDeEditoras;
    }
}
