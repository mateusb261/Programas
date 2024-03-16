
public class AumentaFrase {

	public static void main(String[] args) {
		
		String frase = null;
		String novaFrase = null;
		try 
		{ 
			novaFrase = frase.toUpperCase(); 
		} 
		
			
		catch(NullPointerException e) //CAPTURA DA exceção. 
		{ 
			//TRATAMENTO DA exceção
			System.out.println("Foi atribuido um valor default.");
			frase = "a turma de poo eh a melhor turma da computacao";
			novaFrase = frase.toUpperCase();
		} 
		
		System.out.println("Frase antiga: "+frase);
		System.out.println("Frase nova: "+novaFrase);
	}	
}
		
		

