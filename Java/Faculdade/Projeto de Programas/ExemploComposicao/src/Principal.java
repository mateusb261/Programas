
public class Principal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Funcionario funcionario = new Funcionario("Jose","PI00AM");
		funcionario.addDependente("Fabio", "filho");
		funcionario.addDependente("Fernanda", "esposa");
		
		System.out.println("Funcionario: "+funcionario.getNome());
		System.out.println("Matricula: "+funcionario.getMatricula());
		
		System.out.println(funcionario.obterDependentes());
		funcionario = null;
		
		

	}

}
