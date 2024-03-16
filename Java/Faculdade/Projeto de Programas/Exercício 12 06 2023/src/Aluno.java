import java.util.ArrayList;

public class Aluno {
    private String nome;
    private int matricula;
    private ArrayList<Professor> professores;

    public Aluno(String nome, int matricula) {
        this.nome = nome;
        this.matricula = matricula;
        this.professores = new ArrayList<>();
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void adicionarProfessor(Professor p) { professores.add(p);}

    public void removerProfessor(Professor p) { professores.remove(p);}

    public ArrayList<Professor> getProfessores() { return professores;};
}
