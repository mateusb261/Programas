
public class Carro extends Brinquedo implements Mobilidade  {

	public Carro() {
		// TODO Auto-generated constructor stub
	}

	@Override
	public void frente() {
		// TODO Auto-generated method stub
		System.out.println("Ir para frente");
	}

	@Override
	public void recuar() {
		// TODO Auto-generated method stub
		System.out.println("Recuar");

	}

	@Override
	public void esquerda() {
		// TODO Auto-generated method stub
		System.out.println("Ir para esquerda");

	}

	@Override
	public void direita() {
		// TODO Auto-generated method stub
		System.out.println("Ir para direita");
	}

	@Override
	public void parar() {
		// TODO Auto-generated method stub
		System.out.println("Parar");
	}

	@Override
	public void emitirSinalDeLocalizacao() {
		// TODO Auto-generated method stub
		System.out.println("Emitir sinal de localização");
	}

}
