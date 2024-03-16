public class Main {
    public static void main(String[] args) {
        Departamento Software = new Departamento("Desenvolvimento de Software");
        Departamento Admin = new Departamento("Administração");
        Funcionario Mateus = new Funcionario("Mateus Bastos", "001", Software.getArrayList());
        Funcionario Josue = new Funcionario("Josué Azevedo", "002", Software.getArrayList());
        Funcionario Ana = new Funcionario("Ana Lídia", "003", Admin.getArrayList());
        Funcionario Anderson = new Funcionario("Anderson Esteves", "004", Admin.getArrayList());

        Software.obterFuncionarios();
        Admin.obterFuncionarios();
    }
}