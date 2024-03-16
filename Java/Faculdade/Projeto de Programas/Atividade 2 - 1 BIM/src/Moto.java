/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
	Curso: Sistemas de Informação
*/

public class Moto extends Veiculo{
    private String chassi;

    public Moto(String marca, String modelo, int ano) {
        super(marca, modelo, ano);
    }

    public String getChassi() {
        return chassi;
    }

    public void setChassi(String chassi) {
        this.chassi = chassi;
    }
}
