
public class ExemploPolimorfismo {
	
	
	public static void mostrarBonificacao(Funcionario funcionario){
		System.out.println("Nome: "+funcionario.getNome());
		System.out.println(String.format("Bonificacao: R$ %,.2f ",funcionario.obterBonicacao()));
		System.out.println("============================================");
		
	}
	
	
	public static void main(String[] args) {
		
		Funcionario funcionario = new Funcionario("Jose", 1000);
		mostrarBonificacao(funcionario);
		
		Engenheiro engenheiro = new Engenheiro("Ronaldo", 3000, "AM1001");
		mostrarBonificacao(engenheiro);
		
		Funcionario motorista = new Motorista("Adriano",2012, "011929AM");
		mostrarBonificacao(motorista);
		
		//Motorista mot = motorista;
	}
	  
			
	    
	
	/*
	public static void main(String[] arg){  
	       
			Funcionario[] funcionarios = new Funcionario[2];
	  		 //array para dois funcionarios
	        funcionarios[0] = new Engenheiro("Ronaldo", 3000, "AM1001");  
	        //Isso é correto, já que Engenheiro é-um Funcionario  
	        funcionarios[1] = new Motorista("Adriano",2012, "011929AM");  
	 		//Isso é correto, já que Motorista é-um Funcionario          
	        
	        for(int i = 0;i<2;i++){ 
	        	  
	            if(funcionarios[i] instanceof Engenheiro){  
	                Engenheiro eng = (Engenheiro) funcionarios[i];  //cast
	                System.out.println("Engenheiro: "+funcionarios[i].getNome()); 
	                System.out.println("CREA:"+eng.getCrea());  
	            }else{ 
	            	Motorista mot = (Motorista) funcionarios[i];  //cast
	                System.out.println("Motorista: "+funcionarios[i].getNome());
	                System.out.println("CNH:"+mot.getCnh());
	               
	            }  
	              
	            System.out.println();  
	        }  
	    } */  
	
}
