
public class Engenheiro extends Funcionario {

	private String crea;

	public Engenheiro(String nome, double salario, String crea) {
		super(nome, salario);
		this.crea = crea;
	}
	public String getCrea() {
		return crea;
	}
	public void setCrea(String crea) {
		this.crea = crea;
	}
	public double obterBonicacao(){
		return getSalario()*0.15;
	}
}
