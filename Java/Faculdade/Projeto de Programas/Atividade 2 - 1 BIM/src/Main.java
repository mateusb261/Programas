/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
	Curso: Sistemas de Informação
*/

import javax.swing.*;

public class Main {

    // criar um objeto global "garagem", para ser possível realizar operações relacionadas à classe "Garagem" na main

    public static Garagem garagem = new Garagem();

    // função que pode ser utilizada na main para adicionar um veículo à garagem
    public static void adicionar() {

        String marca = JOptionPane.showInputDialog("Digite a marca do veículo:");
        String modelo = JOptionPane.showInputDialog("Digite o modelo do veículo:");
        String anoString = JOptionPane.showInputDialog("Digite o ano do veículo:");

        int anoInt = Integer.parseInt(anoString);

        String tipoVeiculo;


        do {
            tipoVeiculo = JOptionPane.showInputDialog(null, "Informe o tipo de veículo: \n " +
                    "[1] Carrro \n " +
                    "[2] Moto\n " +
                    "[3] Caminhão \n ");

            if (tipoVeiculo.charAt(0) == '1') {
                Carro carro = new Carro(marca, modelo, anoInt);
                garagem.adicionarVeiculo(carro);
            }

            if (tipoVeiculo.charAt(0) == '2') {
                Moto moto = new Moto(marca, modelo, anoInt);
                garagem.adicionarVeiculo(moto);
            }

            if (tipoVeiculo.charAt(0) == '3') {
                Caminhão caminhão = new Caminhão(marca, modelo, anoInt);
                garagem.adicionarVeiculo(caminhão);
            }

        } while (tipoVeiculo.charAt(0) != '1' && tipoVeiculo.charAt(0) != '2' && tipoVeiculo.charAt(0) != '3');


    }

    // função que pode ser utilizada na main para remover um veículo da garagem

    public static void remover() {
        String marca = JOptionPane.showInputDialog(null, "\nDigite a marca correspondente ao " +
                "veículo que deseja remover da garagem:");
        String modelo = JOptionPane.showInputDialog(null, "\nDigite o modelo correspondente ao " +
                "veículo que deseja remover da garagem:");

        /* O comando instanceof está presente no método "removerVeiculo(marca, modelo)" da classe "Garagem" para
        identificar o tipo de veículo que será removido da garagem */

        String mensagem = garagem.removerVeiculo(marca, modelo);

        JOptionPane.showMessageDialog(null, mensagem);
    }

    // função que pode ser utilizada na main para listar os veículos presentes na garagem

    public static void listar() {
        String lista = garagem.listarVeiculos();
        JOptionPane.showMessageDialog(null, lista);

    }

    public static void main(String[] args) {

        String operacao;

        do{
			 operacao = JOptionPane.showInputDialog(null, "Programa Garagem Veículos \n" +
                     "Informe a operação: \n " +
                     "[1] Adicionar um veículo à garagem \n " +
                     "[2] Remover um veículo da garagem\n " +
                     "[3] Listar os veículos presentes na garagem \n " +
                     "[4] Encerrar o programa \n");

            if (operacao.charAt(0) == '1'){
				adicionar();

			}else if (operacao.charAt(0) == '2'){
				remover();

			}else if (operacao.charAt(0) == '3'){
				listar();

			}
		} while(operacao.charAt(0)!= '4');

        System.exit(0);
    }
}