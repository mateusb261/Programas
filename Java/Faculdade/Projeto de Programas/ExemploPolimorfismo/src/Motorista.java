
public class Motorista extends Funcionario {

	private String cnh;
	
	public Motorista(String nome, double salario, String cnh) {
		super(nome, salario);
		this.cnh = cnh;
	}
	public String getCnh() {
		return cnh;
	}
	public void setCnr(String cnh) {
		this.cnh = cnh;
	}
	public double obterBonicacao(){
		return getSalario()*0.12;
	}
}
