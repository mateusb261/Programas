import  javax.swing.*;

public class Ex_try_catch_finally{
    public static void main(String args[]){
       int n1, n2;    
   	String aux=JOptionPane.showInputDialog(null, "Informe um valor inteiro");
       try{
           n1=Integer.parseInt(aux); //transforma em inteiro o valor digitado em aux
           aux=JOptionPane.showInputDialog(null, "Informe outro valor inteiro");
           n2=Integer.parseInt(aux); //idem
           JOptionPane.showMessageDialog(null, "Produto = "  + (n1*n2));
	    JOptionPane.showMessageDialog(null, "Divisão = "  + (n1/n2));
       }
       catch (NumberFormatException e) { //trata erros de formato de numeros
 		JOptionPane.showMessageDialog(null, "Erro na entrada de dados");             }
       catch (ArithmeticException e) { //Divisão por zero
		JOptionPane.showMessageDialog(null, "Divisão por zero");             }
       finally {
 		JOptionPane.showMessageDialog(null, "****Final de execução****");
       }
  }
}

