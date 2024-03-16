import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Professor Fabio = new Professor("Fábio", 100);
        Aluno Mateus = new Aluno("Mateus", 101);
        Aluno Jose = new Aluno("José", 102);
        Aluno Maria = new Aluno("Maria", 103);

        Fabio.adicionarAluno(Mateus);
        Fabio.adicionarAluno(Jose);
        Fabio.adicionarAluno(Maria);
    }
}