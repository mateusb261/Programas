#include <stdio.h>

int i, indice, copia;

int vet[5] = {45,5,72,19,28};

main()
{
	//imprimir
    for(i = 0; i < 5; i++)
	{
		printf("%4d", vet[i]);
	}
	
	printf("\n");
	
	//preencher vetor
	for(i = 1; i < 5; i++){
      copia = vet[i];
      indice = i;

      while(indice > 0 && vet[indice - 1] > copia){
        vet[indice] = vet[indice - 1];
        indice--;
      }
      vet[indice] = copia;
    }
    
    printf("\n");
    //imprimir
    for(i = 0; i < 5; i++)
	{
		printf("%4d", vet[i]);
	}
	
}
