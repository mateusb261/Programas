import java.util.ArrayList;

public class Departamento {
    private String nome;
    private ArrayList<Funcionario>funcionarios = new ArrayList<>();

    public Departamento(String nome) {
        this.nome = nome;
    }

    public void addFuncionario(Funcionario funcionario) {
        this.funcionarios.add(funcionario);
    }

    public ArrayList<Funcionario> getArrayList() {
        return this.funcionarios;
    }

    public void obterFuncionarios() {
        System.out.println("Os funcionário desse departamento são:\n");
        for (int i = 0; i < this.funcionarios.size(); i++) {
            System.out.println(funcionarios.get(i).getNome());
        }
        System.out.println();
    }
}
