public class Invoice {
    private int num;
    private String descr;
    private int quant;
    private double preço_item;

    public Invoice(int num, String descr, int quant, double preço_item) {
        if (num < 0)
            this.num = 0;
        if (num > 0)
            this.num = num;

        this.descr = descr;

        if (quant < 0)
            this.quant = 0;
        if (quant > 0)
            this.quant = quant;

        if (preço_item < 0)
            this.preço_item = 0.0;
        if (preço_item > 0)
            this.preço_item = preço_item;
    }

    public void setNum (int num) {
        if (num > 0)
            this.num = num;
    }

    public void setDescr(String descr) {
        this.descr = descr;
    }

    public void setQuant(int quant) {
        if (quant > 0)
            this.quant = quant;
    }

    public void setPreço_item(double preço_item) {
        if (preço_item > 0)
            this.preço_item = preço_item;
    }

    public int getNum() {
        return this.num;
    }

    public String getDescr() {
        return this.descr;
    }

    public int getQuant() {
        return this.quant;
    }

    public double getPreço_item() {
        return this.preço_item;
    }

    public void getInvoice() {
        int quant = this.quant;;
        double v_total = this.preço_item * this.quant;

        System.out.println("A fatura do produto fornecido é: \n");
        System.out.println("Cod Descrição Qtd Vl Unit. Vl total\n");
        System.out.printf("%d  ", this.num);
        System.out.printf("%s  ", this.descr);
        System.out.printf("%d  ", this.quant);
        System.out.printf("R$ %.2f  ", this.preço_item);
        System.out.printf("R$ %.2f", v_total);
    }
}
