#include <stdio.h>

const int Tamanho = 10;
int Vetor[Tamanho] = {6, 7, 5, 4, 9, 8, 3, 8, 2, 1};

void *ImprimeVetor(){
    for(int i = 0; i <= Tamanho -1; i++) {
        printf("\nVetor %d: %d ", i, Vetor[i]);
    }
}

void Quick_Sort(int Left, int Right) {  
    int Aux, Pivor, L, R;
   
    L = Left;
    R = Right;
    Pivor = Vetor[(Left + Right) / 2];
   
    while(L <= R) {
        while(Vetor[L] < Pivor && L < Right) {
            L++;
        }
        while(Vetor[R] > Pivor && R > Left) {
            R--;
        }
        if(L <= R) {
            Aux = Vetor[L];
            Vetor[L] = Vetor[R];
            Vetor[R] = Aux;
            L++;
            R--;
        }
    }
    
    if(R > Left) {
        Quick_Sort(Left, R);
    }
    
    if(L < Right) {
        Quick_Sort(L, Right);
    }
}

main(){
    printf("Vetor antes da ordenação:");
    ImprimeVetor();

    Quick_Sort(0, Tamanho-1);

    printf("\n\nVetor depois da ordenação:");
    ImprimeVetor();
}
