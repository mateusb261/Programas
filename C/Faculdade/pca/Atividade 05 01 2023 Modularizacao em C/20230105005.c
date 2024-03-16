#include <stdio.h>

int num_nat(){
    int n;
    do{
        printf("Digite um numero natural relativo a uma posicao da sequencia de Fibonacci: ");
        scanf("%d", & n);
        printf("\n");
        if(n <= 0){
            printf("Entrada invalida. Digite apenas numeros naturais positivos.");
            printf("\n");
        }
    } while(n <= 0);
    return n;
}

int fib(int n){
    if(n <= 2){
        return 1;
    }
    else{
        if(n > 2){
            int fib = 0;
            int ult_fib = 1, pen_fib = 1, contador = 1;
            while(contador <= (n - 2)){
                fib = ult_fib + pen_fib;
                pen_fib = ult_fib;
                ult_fib = fib;
                contador++;
            }
            return fib;
        }
    }
}

int main(){
    int n = num_nat();
    int v_fib = fib(n);
    printf("O valor da posicao %d na sequencia de Fibonacci e: %d", n, v_fib);
    return 0;
}