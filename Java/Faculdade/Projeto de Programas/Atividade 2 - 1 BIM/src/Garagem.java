/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
	Curso: Sistemas de Informação
*/

import java.util.ArrayList;

public class Garagem {
    private ArrayList<Veiculo> veiculos = new ArrayList<>(100);

    public Garagem() {

    }

    public void adicionarVeiculo(Veiculo veiculo) {
        if (veiculos.size() < 100) {
            this.veiculos.add(veiculo);
        }
        else {
            System.out.println("Não foi possível adicionar o veículo pois não há vaga disponível");
        }
    }

    public String removerVeiculo(String marca, String modelo) {

        String retorno = "";
        int sucesso = 0;

        for (int i = 0; i < veiculos.size(); i++) {
            if (veiculos.get(i).getMarca().equals(marca) && veiculos.get(i).getModelo().equals(modelo)) {

                sucesso = 1;

                if (veiculos.get(i) instanceof Carro) {
                    retorno += "Um veículo do tipo Carro será removido da garagem";
                }

                if (veiculos.get(i) instanceof Moto) {
                    retorno += "Um veículo do tipo Moto será removido da garagem";
                }

                if (veiculos.get(i) instanceof Caminhão) {
                    retorno += "Um veículo do tipo Caminhão será removido da garagem";
                }

                veiculos.remove(i);
            }
        }

        if (sucesso == 0) {
                retorno += "O veículo informado não está na garagem, logo, não foi retirado";
            }

        return retorno;
    }

    public String listarVeiculos() {
        String retorno = "Os seguintes veículos encontram-se na garagem:\n";
        Veiculo veiculo;

        for (int i = 0; i < veiculos.size(); i++) {
            veiculo = veiculos.get(i);

            if (veiculo instanceof Carro)
                retorno += "[" + i + "]" + "Carro:  ";


            if (veiculo instanceof Moto)
                retorno += "[" + i + "]" + "Moto:  ";


            if (veiculo instanceof Caminhão)
                retorno += "[" + i + "]" + "Caminhão:  ";


            retorno += "Marca: " + veiculo.getMarca() + "; Modelo: " + veiculo.getModelo() + "; Ano: " + veiculo.getAno() + "\n";
        }

        return retorno;
    }

    public int quantidadeVeiculos() {
        return veiculos.size();
    }
}
