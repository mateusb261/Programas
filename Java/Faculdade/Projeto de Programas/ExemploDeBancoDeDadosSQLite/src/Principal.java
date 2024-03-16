import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class Principal {
    public static void main(String[] args) {
        // Dados do aluno
        Aluno aluno = new Aluno();
        aluno.setId(4);
        aluno.setNome("Fabio");
        aluno.setIdade(30);

        // Conexão com o banco de dados
        try {
            Connection connection = DriverManager.getConnection("jdbc:sqlite:alunos.db");

            // Verifica e cria a tabela alunos, caso não exista
            String createTableQuery = "CREATE TABLE IF NOT EXISTS alunos (id INT PRIMARY KEY, nome TEXT, idade INT)";
            Statement createTableStatement = connection.createStatement();
            createTableStatement.execute(createTableQuery);

            // SQL para inserção do aluno na tabela
            String insertQuery = "INSERT INTO alunos (id, nome, idade) VALUES (?, ?, ?)";
            PreparedStatement preparedStatement = connection.prepareStatement(insertQuery);

            // Configuração dos parâmetros
            preparedStatement.setInt(1, aluno.getId());
            preparedStatement.setString(2, aluno.getNome());
            preparedStatement.setInt(3, aluno.getIdade());

            // Execução da inserção
            preparedStatement.executeUpdate();
            
            System.out.println("Aluno inserido com sucesso!");

            // Consulta para recuperar a lista de alunos
            String selectQuery = "SELECT id, nome, idade FROM alunos";
            Statement selectStatement = connection.createStatement();
            ResultSet resultSet = selectStatement.executeQuery(selectQuery);

            // Mostrar a lista de alunos
            System.out.println("Lista de Alunos:");
            while (resultSet.next()) {
                int id = resultSet.getInt("id");
                String nome = resultSet.getString("nome");
                int idade = resultSet.getInt("idade");
                System.out.println("ID: " + id + ", Nome: " + nome + ", Idade: " + idade);
            }

            // Fechamento da conexão e recursos
            resultSet.close();
            selectStatement.close();
            preparedStatement.close();
            createTableStatement.close();
            connection.close();

           
        } catch (SQLException e) {
            System.err.println("Erro ao inserir aluno: " + e.getMessage());
        }
    }
}


