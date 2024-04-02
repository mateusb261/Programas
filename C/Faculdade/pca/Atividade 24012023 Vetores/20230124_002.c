#include <stdio.h>

int n;
int i = 0;

void impr_ord_inv(int lista[]) {
    for (; n >= 0; n--) {
        printf("%d", lista[n]);
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
    impr_ord_inv(lista);
    return 0;
}
