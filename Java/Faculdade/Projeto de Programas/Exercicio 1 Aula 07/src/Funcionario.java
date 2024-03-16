import java.util.ArrayList;

public class Funcionario {
    private String nome;
    private String identificao;

    public Funcionario(String nome, String identificao, ArrayList<Funcionario>funcionarios) {
        this.nome = nome;
        this.identificao = identificao;
        funcionarios.add(this);
    }

    public String getNome() {
        return this.nome;
    }
}
