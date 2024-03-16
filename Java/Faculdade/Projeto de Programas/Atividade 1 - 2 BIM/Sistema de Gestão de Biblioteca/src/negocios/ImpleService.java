package negocios;

import dados.Livro;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ImpleService implements ReservaService, EmprestimoService {
    // Mapas para manter registros de reservas e empréstimos de livros
    private Map<Livro, List<String>> reservas;
    // Mapa de livros e suas listas de nomes de usuários que fizeram reserva
    private Map<Livro, String> emprestimos;
    // Mapa de livros emprestados e o nome do usuário que os emprestou

    // Construtor da classe, inicializa os mapas
    public ImpleService() {
        reservas = new HashMap<>();
        emprestimos = new HashMap<>();
    }

    // Implementação dos métodos da interface ReservaService

    /* Método para fazer uma reserva de livro */
    @Override
    public boolean fazerReserva(Livro livro, String nomeUsuario) {
        if (verificarDisponibilidade(livro)) {
            List<String> listaReservas = reservas.getOrDefault(livro, new ArrayList<>());
            listaReservas.add(nomeUsuario);
            reservas.put(livro, listaReservas);
            System.out.println("Reserva efetuada com sucesso!");

            return true;
        } else {
            System.out.println("Não foi possível efetuar a reserva. Livro indisponível.");

            return false;
        }
    }

    /* Método para verificar a disponibilidade de um livro para reserva */
    @Override
    public boolean verificarDisponibilidade(Livro livro) {
        return !emprestimos.containsKey(livro);
    }

    /* Método para consultar as reservas solicitadas */
    @Override
    public void consultarReservasSolicitadas() {
        for (Map.Entry<Livro, List<String>> entry : reservas.entrySet()) {
            Livro livro = entry.getKey();
            List<String> listaReservas = entry.getValue();
            System.out.println("Livro: " + livro.getTitulo());
            System.out.println("Reservas solicitadas por:");
            for (String nomeUsuario : listaReservas) {
                System.out.println("- " + nomeUsuario);
            }
            System.out.println("----------");
        }
    }

    /* Método para cancelar uma reserva de livro */
    @Override
    public boolean cancelarReserva(Livro livro, String nomeUsuario) {
        List<String> listaReservas = reservas.getOrDefault(livro, new ArrayList<>());
        if (listaReservas.remove(nomeUsuario)) {
            reservas.put(livro, listaReservas);
            System.out.println("Reserva cancelada com sucesso!");

            return true;
        } else {
            System.out.println("Você não tem uma reserva para este livro.");

            return false;
        }
    }

    // Implementação dos métodos da interface EmprestimoService

    /* Método para emprestar um livro */
    @Override
    public boolean emprestarLivro(Livro livro, String nomeUsuario) {
        if (verificarDisponibilidade(livro)) {
            emprestimos.put(livro, nomeUsuario);
            System.out.println("Empréstimo realizado com sucesso!");

            return true;
        } else {
            System.out.println("Não foi possível efetuar o empréstimo. Livro indisponível.");

            return false;
        }
    }

    /* Método para devolver um livro emprestado */
    @Override
    public boolean devolverLivro(Livro livro, String nomeUsuario) {
        String usuarioEmprestimo = emprestimos.get(livro);
        if (usuarioEmprestimo != null && usuarioEmprestimo.equals(nomeUsuario)) {
            emprestimos.remove(livro);
            System.out.println("Livro devolvido com sucesso!");

            return true;
        } else {
            System.out.println("Você não tem este livro emprestado.");

            return false;
        }
    }
}
