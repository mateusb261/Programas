/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
	Curso: Sistemas de Informação
*/

public class Caminhão extends Veiculo{
    private String tipo;

    public Caminhão(String marca, String modelo, int ano) {
        super(marca, modelo, ano);
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }
}
