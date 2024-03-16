#include <stdio.h>

int n;
int i;

void impr_pares(int lista[]){
    int resto;
    for (i = 0; i <= n; i++) {
        resto = lista[i] % 2;
        if(resto == 0) {
            printf("%d ", lista[i]);
        }
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
    impr_pares(lista);
    return 0;
}
