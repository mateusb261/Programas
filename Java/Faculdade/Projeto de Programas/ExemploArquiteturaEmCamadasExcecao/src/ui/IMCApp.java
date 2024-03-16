package ui;

import javax.swing.JOptionPane;
import business.IMCCalculator;
import data.IMCFileWriter;

public class IMCApp {
    public static void main(String[] args) {
        String weightInput = JOptionPane.showInputDialog("Digite o seu peso em kg:");
        double weight = Double.parseDouble(weightInput);

        String heightInput = JOptionPane.showInputDialog("Digite a sua altura em metros:");
        double height = Double.parseDouble(heightInput);

        IMCCalculator calculator = new IMCCalculator();
        double imc = calculator.calculateIMC(weight, height);

        String resultMessage = String.format("Seu IMC é: %.2f", imc);
        JOptionPane.showMessageDialog(null, resultMessage);

        IMCFileWriter.saveResultToFile(imc); // Salva o resultado em um arquivo de texto
    }
}
