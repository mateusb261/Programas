package negocios;

import dados.Editora;

public abstract class ServicoEditora {
    public abstract void cadastrarEditora(String nome, String localizacao);

    public abstract void atualizarEditora(String nomeAntigo, String novoNome, String novaLocalizacao);

    public abstract void removerEditora(String nome);

    public abstract Editora buscarEditoraPorNome(String nome);

    // Outros métodos relacionados a editoras podem ser declarados aqui
}
