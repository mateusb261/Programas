public class Main {
    public static void main(String[] args) {
        Est a = new Est(), b = new Est(), c = new Est();
        a.var = 1;
        b.var++;

        Est.var++;

        System.out.println(a.var);
        System.out.println(b.var);
        System.out.println(Est.var);
    }
}