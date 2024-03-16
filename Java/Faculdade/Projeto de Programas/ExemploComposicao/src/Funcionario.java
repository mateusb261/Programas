import java.util.ArrayList;


public class Funcionario {

	private String nome, matricula;
	private ArrayList<Dependente> dependentes = new ArrayList<>();

	public Funcionario(String nome, String matricula) {
		this.nome = nome;
		this.matricula = matricula;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getMatricula() {
		return matricula;
	}
	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}
	
	public void addDependente(String nome, String parentesco){
		dependentes.add(new Dependente(nome,parentesco));
	}
	
	public String obterDependentes(){
		String retorno = "Lista de Dependentes\n";
		for(int i=0;i<this.dependentes.size();i++){
			retorno+= "Nome: "+this.dependentes.get(i).getNome()+"\n"+"Parentesco: "+
			this.dependentes.get(i).getParentesco()+"\n";
			
		}
		return retorno;
	}

}
