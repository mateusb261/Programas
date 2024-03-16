package negocios;

import dados.Livro;

// Interface que define os serviços relacionados a reservas de livros

public interface ReservaService {
    /* Métodos */

    // Para fazer uma reserva de livro;
    public boolean fazerReserva(Livro livro, String nomeUsuario);
    // Verificar a disponibilidade de um livro para reserva;
    public boolean verificarDisponibilidade(Livro livro);
    // Consultar as reservas solicitadas;
    public void consultarReservasSolicitadas();
    // Cancelar uma reserva de livro;
    public boolean cancelarReserva(Livro livro, String nomeUsuario);
}
