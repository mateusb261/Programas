#include <stdio.h>

int main(){
    const int tam = 100;
    int lista[tam];
    int n;
    printf("Digite a quantidade de numeros: ");
    scanf("%d", & n);
    printf("\n");
    int i = 0;
    for(i; i < n; i++){
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", & lista[i]);
    }
    n--;
    for(n; n >= 0; n--){
        printf("%d", lista[n]);
    }
    return 0;
}
