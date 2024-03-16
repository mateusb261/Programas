package apresentacao;

import javax.swing.*;
import dados.Autor;
import dados.Editora;
import dados.Livro;
import negocios.ImpleAutor;
import negocios.ImpleEditora;
import negocios.ImpleLivro;
import negocios.ImpleService;

import java.util.ArrayList;

public class Menu {
    /* Instânciação das classes da camada de negócios para utilizar seus métodos: */
    // Para Autores;
    private ImpleAutor impleAutor = new ImpleAutor();
    // Para Editoras;
    private ImpleEditora impleEditora = new ImpleEditora();
    // Para Livros;
    private ImpleLivro impleLivro = new ImpleLivro();
    // Para os Serviços secundários;
    private ImpleService impleService = new ImpleService();

    // Método para cadastrar autores, editoras ou livros
    public void cadastrar() {
        String tipoCadastrar;

        do {
            tipoCadastrar = JOptionPane.showInputDialog(null, "Informe o que deseja cadastrar: \n " +
                    "[1] Autor \n " +
                    "[2] Editora\n " +
                    "[3] Livro \n ");

            if (tipoCadastrar == null) {
                JOptionPane.showMessageDialog(null, "Operação de cadastro cancelada");
                return;
            }
            /* Cadastro de: */
            // Um autor;
            if (tipoCadastrar.charAt(0) == '1') {
                String nome = JOptionPane.showInputDialog("Digite o Nome do autor:");
                String nacionalidade = JOptionPane.showInputDialog("Digite a Nacionalidade do autor:");

                Autor autor = impleAutor.cadastrarAutor(nome, nacionalidade);

                JOptionPane.showMessageDialog(null, "O Id do autor cadastrado é: " + autor.getId());
            }

            // Uma editora;
            if (tipoCadastrar.charAt(0) == '2') {
                String nome = JOptionPane.showInputDialog("Digite o Nome da editora:");
                String localizacao = JOptionPane.showInputDialog("Digite a Localização da editora:");

                impleEditora.cadastrarEditora(nome, localizacao);
            }

            // Um livro;
            if (tipoCadastrar.charAt(0) == '3') {
                String titulo = JOptionPane.showInputDialog("Digite o Título do livro:");
                String nomeAutor = JOptionPane.showInputDialog("Digite o Nome do autor:");
                String nomeEditora = JOptionPane.showInputDialog("Digite o Nome da editora:");

                // Tratamento de excessão
                try {
                    Autor autor = impleAutor.buscarAutorPorNome(nomeAutor);
                    Editora editora = impleEditora.buscarEditoraPorNome(nomeEditora);

                    impleLivro.cadastrarLivro(titulo, autor, editora);
                } catch (NullPointerException e) {
                    JOptionPane.showMessageDialog(null, "Editora ou Autor não encontrado(s). Cadastro não realizado.");
                }
            }

        } while (tipoCadastrar.charAt(0) != '1' && tipoCadastrar.charAt(0) != '2' && tipoCadastrar.charAt(0) != '3');
    }

    // Método para atualizar informações de autores, editoras ou livros
    public void atualizar() {
        String tipoAtualizar;

        do {
            tipoAtualizar = JOptionPane.showInputDialog(null, "Informe o que deseja atualizar: \n " +
                    "[1] Autor \n " +
                    "[2] Editora\n " +
                    "[3] Livro \n ");

            if (tipoAtualizar == null) {
                JOptionPane.showMessageDialog(null, "Operação de atualizar cancelada");
                return;
            }

            // Atualizando informações de um autor
            if (tipoAtualizar.charAt(0) == '1') {
                String IdString = JOptionPane.showInputDialog("Digite o Id do autor:");
                String nacionalidadeAutor = JOptionPane.showInputDialog("Digite a Nova Nacionalidade do autor:");
                String novoNome = JOptionPane.showInputDialog("Digite o Nome Novo do autor:");

                // Tratamento de excessão
                try {
                    int IdInt = Integer.parseInt(IdString);
                    impleAutor.atualizarAutor(IdInt, novoNome, nacionalidadeAutor);
                } catch (NumberFormatException e) {
                    JOptionPane.showMessageDialog(null, "Entrada de Id incorreta. Atualização não realizada.");
                } catch (NullPointerException e) {
                    JOptionPane.showMessageDialog(null, "Autor não encontrado. Atualização não realizada.");
                }
            }

            // Atualizando as informações de uma editora
            if (tipoAtualizar.charAt(0) == '2') {
                String nomeAntigo = JOptionPane.showInputDialog("Digite o Nome Antigo da editora:");
                String novoNome = JOptionPane.showInputDialog("Digite o Nome Novo da editora:");
                String novaLocalizacao = JOptionPane.showInputDialog("Digite a Nova Localização da editora:");

                // Tratamento de excessão
                try {
                    impleEditora.atualizarEditora(nomeAntigo, novoNome, novaLocalizacao);
                } catch (NullPointerException e) {
                    JOptionPane.showMessageDialog(null, "Editora não encontrada. Atualização não realizada.");
                }
            }

            // Atualizando as informações de um livro
            if (tipoAtualizar.charAt(0) == '3') {
                String tituloAntigo = JOptionPane.showInputDialog("Digite o Título Antigo do livro:");
                String novoTitulo = JOptionPane.showInputDialog("Digite o Título Novo do livro:");
                String novoAutor = JOptionPane.showInputDialog("Digite o Nome do Novo autor:");
                String novaEditora = JOptionPane.showInputDialog("Digite o Nome da Nova editora:");

                Autor autor = impleAutor.buscarAutorPorNome(novoAutor);
                Editora editora = impleEditora.buscarEditoraPorNome(novaEditora);

                // Tratamento de excessão
                try {
                    impleLivro.atualizarLivro(tituloAntigo, novoTitulo, autor, editora);
                } catch (NullPointerException e) {
                    JOptionPane.showMessageDialog(null, "Livro não encontrado. Atualização não realizada.");
                }
            }

        } while (tipoAtualizar.charAt(0) != '1' && tipoAtualizar.charAt(0) != '2' && tipoAtualizar.charAt(0) != '3');
    }

    // Método para remover autores, editoras ou livros
    public void remover() {
        String tipoRemover;

        do {
            tipoRemover = JOptionPane.showInputDialog(null, "Informe o que deseja remover: \n " +
                    "[1] Autor \n " +
                    "[2] Editora\n " +
                    "[3] Livro \n ");

            if (tipoRemover == null) {
                JOptionPane.showMessageDialog(null, "Operação de remoção cancelada.");
                return;
            }

            // Removendo um autor
            if (tipoRemover.charAt(0) == '1') {
                String nomeAutor = JOptionPane.showInputDialog("Digite o Nome do autor:");

                try {
                    impleAutor.removerAutor(nomeAutor);
                } catch (NullPointerException e) {
                    JOptionPane.showMessageDialog(null, "Autor não encontrado. Remoção não realizada.");
                }
            }

            // Removendo uma editora
            if (tipoRemover.charAt(0) == '2') {
                String nomeEditora = JOptionPane.showInputDialog("Digite o Nome da editora:");

                try {
                    impleEditora.removerEditora(nomeEditora);
                } catch (NullPointerException e) {
                    JOptionPane.showMessageDialog(null, "Editora não encontrada. Remoção não realizada.");
                }
            }

            // Removendo um livro
            if (tipoRemover.charAt(0) == '3') {
                String tituloLivro = JOptionPane.showInputDialog("Digite o Título do livro:");

                try {
                    impleLivro.removerLivro(tituloLivro);
                } catch (NullPointerException e) {
                    JOptionPane.showMessageDialog(null, "Livro não encontrado. Remoção não realizada.");
                }
            }

        } while (tipoRemover.charAt(0) != '1' && tipoRemover.charAt(0) != '2' && tipoRemover.charAt(0) != '3');
    }

    // Método para visualizar informações de autores, editoras ou livros
    public void visualizar() {
        String tipoVisualizar;

        do {
            tipoVisualizar = JOptionPane.showInputDialog(null, "Informe o que deseja visualizar: \n " +
                    "[1] Lista de Autores \n " +
                    "[2] Lista de Editoras\n " +
                    "[3] Lista de Livros \n ");

            if (tipoVisualizar == null) {
                JOptionPane.showMessageDialog(null, "Operação de visualizar cancelada");
                return;
            }
            /* Visualizando */
            // A lista de autores;
            if (tipoVisualizar.charAt(0) == '1') {
                ArrayList<Autor> listaDeAutores = impleAutor.listarAutores();
                String mensagem = "Lista de autores cadastrados:\n\n";

                for (Autor autor : listaDeAutores) {
                    mensagem += "Nome: " + autor.getNome() + "; Nacionalidade: " + autor.getNacionalidade() + "\n";
                }

                JOptionPane.showMessageDialog(null, mensagem);
            }

            // A lista de editoras;
            if (tipoVisualizar.charAt(0) == '2') {
                ArrayList<Editora> listaDeEditoras = impleEditora.listarEditoras();
                String mensagem = "Lista de editoras cadastradas:\n\n";

                for (Editora editora : listaDeEditoras) {
                    mensagem += "Nome: " + editora.getNome() + "; Localização: " + editora.getLocalizacao() + "\n";
                }

                JOptionPane.showMessageDialog(null, mensagem);
            }

            // A lista de livros;
            if (tipoVisualizar.charAt(0) == '3') {
                ArrayList<Livro> listaDeLivros = impleLivro.listarLivros();
                String mensagem = "Lista de livros cadastrados:\n\n";

                for (Livro livro : listaDeLivros) {
                    mensagem += "Título: " + livro.getTitulo() + "; Autor: " + livro.getAutor().getNome() + "; Editora: " + livro.getEditora().getNome() + "\n";
                }

                JOptionPane.showMessageDialog(null, mensagem);
            }

        } while (tipoVisualizar.charAt(0) != '1' && tipoVisualizar.charAt(0) != '2' && tipoVisualizar.charAt(0) != '3');
    }

    // método para emprestar um livro
    public void emprestarLivro() {
        String tituloLivro = JOptionPane.showInputDialog("Digite o título do livro:");

        // verifica se o título fornecido é válido
        if (tituloLivro != null) {
            Livro livro = impleLivro.buscarLivroPorTitulo(tituloLivro);

            // verifica se o objeto "livro" é nulo
            if (livro != null) {
                String nomeUsuario = JOptionPane.showInputDialog("Digite o nome do usuário:");

                boolean emprestimo = impleService.emprestarLivro(livro, nomeUsuario);

                if (emprestimo) {
                    JOptionPane.showMessageDialog(null, "Empréstimo realizado com sucesso!");
                } else {
                    JOptionPane.showMessageDialog(null, "Não foi possível efetuar o empréstimo. Livro indisponível.");
                }
            } else {
                JOptionPane.showMessageDialog(null, "O livro fornecido não existe. Empréstimo não realizado.");
            }
        } else {
            JOptionPane.showMessageDialog(null, "Nenhum livro foi fornecido. Empréstimo não realizado.");
        }
    }

    // método para reservar um livro
    public void reservarLivro() {
        String tituloLivro = JOptionPane.showInputDialog("Digite o título do livro:");

        // verifica se o título fornecido é válido
        if (tituloLivro != null) {
            Livro livro = impleLivro.buscarLivroPorTitulo(tituloLivro);

            // verifica se o objeto "livro" é nulo
            if (livro != null) {
                String nomeUsuario = JOptionPane.showInputDialog("Digite o nome do usuário:");

                boolean reserva = impleService.fazerReserva(livro, nomeUsuario);

                if (reserva) {
                    JOptionPane.showMessageDialog(null, "Reserva efetuada com sucesso!");
                } else {
                    JOptionPane.showMessageDialog(null, "Não foi possível efetuar a reserva. Livro indisponível.");
                }
            } else {
                JOptionPane.showMessageDialog(null, "O livro fornecido não existe. Reserva não realizada.");
            }
        } else {
            JOptionPane.showMessageDialog(null, "Nenhum livro foi fornecido. Reserva não realizada.");
        }
    }

    // método para devolver um livro
    public void devolverLivro() {
        String tituloLivro = JOptionPane.showInputDialog("Digite o título do livro:");

        // verifica se o título fornecido é válido
        if (tituloLivro != null) {
            Livro livro = impleLivro.buscarLivroPorTitulo(tituloLivro);

            // verifica se o objeto "livro" é nulo
            if (livro != null) {
                String nomeUsuario = JOptionPane.showInputDialog("Digite o nome do usuário:");

                boolean reserva = impleService.devolverLivro(livro, nomeUsuario);

                if (reserva) {
                    JOptionPane.showMessageDialog(null, "Livro devolvido com sucesso!");
                } else {
                    JOptionPane.showMessageDialog(null, "Você não tem este livro emprestado.");
                }
            } else {
                JOptionPane.showMessageDialog(null, "O livro fornecido não existe. Devolução não realizada.");
            }
        } else {
            JOptionPane.showMessageDialog(null, "Nenhum livro foi fornecido. Devolução não realizada.");
        }
    }

    // método para cancelar reserva
    public void cancelarReserva() {
        String tituloLivro = JOptionPane.showInputDialog("Digite o título do livro:");

        // verifica se o título fornecido é válido
        if (tituloLivro != null) {
            Livro livro = impleLivro.buscarLivroPorTitulo(tituloLivro);

            // verifica se o objeto "livro" é nulo
            if (livro != null) {
                String nomeUsuario = JOptionPane.showInputDialog("Digite o nome do usuário:");

                boolean reserva = impleService.cancelarReserva(livro, nomeUsuario);

                if (reserva) {
                    JOptionPane.showMessageDialog(null, "Reserva cancelada com sucesso!");
                } else {
                    JOptionPane.showMessageDialog(null, "Você não tem uma reserva para este livro.");
                }
            } else {
                JOptionPane.showMessageDialog(null, "O livro fornecido não existe. Cancelamento não realizado.");
            }
        } else {
            JOptionPane.showMessageDialog(null, "Nenhum livro foi fornecido. Cancelamento não realizado.");
        }
    }
}
