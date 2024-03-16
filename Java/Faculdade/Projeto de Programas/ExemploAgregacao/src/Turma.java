import java.util.ArrayList;


public class Turma {
	
	private String codigo;
	private ArrayList<Aluno> alunos = new ArrayList<>();
	

	public String getCodigo() {
		return codigo;
	}

	public void setCodigo(String codigo) {
		this.codigo = codigo;
	}
	
	public void addAluno(Aluno aluno){
		alunos.add(aluno);
	}
	
	public String obterAlunos(){
		String retorno = "Lista de Alunos\n";
		for(int i=0;i<this.alunos.size();i++){
			retorno+= "Nome: "+this.alunos.get(i).getNome()+"\n"+"Matricula: "+
			this.alunos.get(i).getMatricula()+"\n";
			
		}
		return retorno;
	}

}
