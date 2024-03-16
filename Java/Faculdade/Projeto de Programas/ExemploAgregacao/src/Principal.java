
public class Principal {

	public static void main(String[] args) {
		
		
		Turma turma = new Turma();
		turma.setCodigo("ESTTPD01");
		
		Aluno aluno1 = new Aluno();
		aluno1.setMatricula("1022020A");
		aluno1.setNome("Fabio Santos");
		
		Aluno aluno2 = new Aluno();
		aluno2.setMatricula("11111111A");
		aluno2.setNome("Maria da Silva");
		
		turma.addAluno(aluno1);
		turma.addAluno(aluno2);
		
		System.out.println(turma.obterAlunos());
		
		

	}

}
