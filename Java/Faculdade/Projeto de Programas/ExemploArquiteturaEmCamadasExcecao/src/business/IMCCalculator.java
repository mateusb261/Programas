package business;

public class IMCCalculator {
    public double calculateIMC(double weight, double height) {
        if (height <= 0) {
            throw new IllegalArgumentException("A altura deve ser maior que zero.");
        }

        return weight / (height * height);
    }
}
