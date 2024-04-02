#include <stdio.h>

int obter_int(){
    int n;
    printf("Digite um numero inteiro: ");
    scanf("%d", & n);
    printf("\n");
    return n;
}


int num_entre_0_e_9(){
    int n;
    do{
        printf("Digite um numero entre 0 e 9: ");
        scanf("%d", & n);
        printf("\n");
        if(n <= 0 || n >= 9){
            printf("Entrada invalida. Digite apenas um numero entre 0 e 9.");
            printf("\n");
        }
    } while(n <= 0 || n >= 9);
    return n;
}

int contar(int n, int d){
    int cont=0;
    while (n > 0){
        if ((n%10)==d) {
            cont++;
        }
        n=n/10;
    }
    return cont;
}

int main() {
    int n = obter_int();
    int d = num_entre_0_e_9();
    printf("%d", contar(n, d));
    return 0;
}
