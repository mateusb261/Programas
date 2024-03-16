/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
	Curso: Sistemas de Informação
*/

public class Carro extends Veiculo{
    private int numPortas;
    private float litrosPortaMalas;

    public Carro(String marca, String modelo, int ano) {
        super(marca, modelo, ano);
    }

    public int getNumPortas() {
        return numPortas;
    }

    public void setNumPortas(int numPortas) {
        this.numPortas = numPortas;
    }

    public float getLitrosPortaMalas() {
        return litrosPortaMalas;
    }

    public void setLitrosPortaMalas(float litrosPortaMalas) {
        this.litrosPortaMalas = litrosPortaMalas;
    }
}
