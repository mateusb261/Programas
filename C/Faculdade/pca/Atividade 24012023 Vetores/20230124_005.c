#include <stdio.h>

int n;
int i;

void impr_fatorial(int lista[]){
    int resto;
    int fatorial;
    int fator;
    for (i = 0; i <= n; i++) {
        fator = lista[i];
        fatorial = 1;
        while(fator > 1){
            fatorial *= fator;
            fator--;
        }
        printf("%d ", fatorial);
    }
}
int main(){
    const int tam = 100;
    int lista[tam];
    printf("Digite a quantidade de numeros: ");
    scanf("%d", & n);
    printf("\n");
    for(; i < n; i++){
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", & lista[i]);
    }
    n--;
    impr_fatorial(lista);
    return 0;
}
