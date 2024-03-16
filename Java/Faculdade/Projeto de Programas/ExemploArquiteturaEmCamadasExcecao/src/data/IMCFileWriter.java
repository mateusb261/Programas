package data;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class IMCFileWriter {
    private static final String FILE_NAME = "imc_results.txt";

    public static void saveResultToFile(double imc) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(FILE_NAME, true))) {
            writer.println(imc);
        } catch (IOException e) {
            System.err.println("Erro ao escrever no arquivo: " + e.getMessage());
        }
    }
}
