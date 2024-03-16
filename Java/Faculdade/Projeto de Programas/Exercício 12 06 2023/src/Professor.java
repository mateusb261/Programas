import java.util.ArrayList;

public class Professor {
    private String nome;
    private int matricula;
    private ArrayList <Aluno> alunos;
    public Professor(String nome, int matricula) {
        this.nome = nome;
        this.matricula = matricula;
        this.alunos = new ArrayList<>();
    }

    public String getNome() { return this.nome;};

    public void adicionarAluno(Aluno a) { alunos.add(a);};

    public void removerAluno(Aluno a) { alunos.remove(a);};

    public ArrayList<Aluno> getAlunos() { return this.alunos;};

}