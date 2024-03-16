/*
   Atividade 1 - 2ºBIM
   Projeto de Programa de Alto Nível - Sistema de Gestão de Biblioteca com Persistência em Arquivos TXT

   -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
                 Sistema de Gestão de Biblioteca
   -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
   Alunos:
   Mateus Bastos Magalhães Mar;                 Mat:  2215310063
   Victor Albarado Braga;                       Mat:  2115310065
   Handryo Laudinei Barbosa Costa;              Mat:  2115310070

   Professor:
   Fábio Santos
   -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
*/

package apresentacao;

import javax.swing.*;

public class Main {
    // Instanciação da classe "Menu" da camada de apresentação para utilizar os métodos de interação com o usuário
    private static Menu menu = new Menu();

    public static void main(String[] args) {
        String operacao;

        do {
            operacao = JOptionPane.showInputDialog(null, "Sistema de Gestão de Biblioteca \n\n" +
                    "Informe a operação: \n " +
                    "[1] Cadastrar \n " +
                    "[2] Atualizar \n " +
                    "[3] Remover \n " +
                    "[4] Visualizar \n " +
                    "[5] Emprestar livro \n" +
                    "[6] Reservar livro \n" +
                    "[7] Devolver livro \n" +
                    "[8] Cancelar reserva \n" +
                    "[9] Encerrar o programa \n");

            if (operacao.charAt(0) == '1') {
                menu.cadastrar();
            }

            else if (operacao.charAt(0) == '2') {
                menu.atualizar();
            }

            else if (operacao.charAt(0) == '3') {
                menu.remover();
            }

            else if (operacao.charAt(0) == '4') {
                menu.visualizar();
            }

            else if (operacao.charAt(0) == '5') {
                menu.emprestarLivro();
            }

            else if (operacao.charAt(0) == '6') {
                menu.reservarLivro();
            }

            else if (operacao.charAt(0) == '7') {
                menu.devolverLivro();
            }

            else if (operacao.charAt(0) == '8') {
                menu.cancelarReserva();
            }
        } while (operacao.charAt(0) != '9');

        System.exit(0);
    }
}
