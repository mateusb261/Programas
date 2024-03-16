#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preencher(int num[3][3]);
void questao1();
void questao2();
int matriz[][3];

int main()
{

    questao1(matriz);
    return 0;
}


void questao2(){
    char nomes[5][120]={"Joao","Sara","Adria","Mauro","Sandra"};
    char prioridade [5]={'N','N','S','N','S'};
    char nome[120];
    char nomeprioridade[5][120];
    int i,c=0;

    printf ("Digite um nome: ");
    scanf("%s", nome);

    for (i=0;i<5; i++){
        if (strcmp(nome,nomes[i])==0)
            printf ("Achaou na possicao %d ", i+1);
    }

    for (i=0;i<5; i++){
        if (prioridade[i]=='S'){
            strcpy(nomeprioridade[c],nomes[i]);
            c++;
        }
    }
    printf("\nCom prioridade..........");
    for (i=0;i<c; i++){
        printf("\n%s",nomeprioridade[i]);
    }
}

void questao1(){
    int matriz[3][3];
    int soma=0,i,j;
    preencher(matriz);
    for(i=0;i<3;i++){
        for (j=0;j<3;j++){
            if (i==j) {
                soma=soma+matriz[i][j];
            }
        }
    }
    printf("soma diagonal principal %d",soma);
}

void preencher(int num[][3]){
    int i,j;
    for(i=0;i<3;i++){
        for (j=0;j<3;j++){
            printf("Valor para %d,%d ",(i + 1), (j + 1));
            scanf("%d",&num[i][j]);
        }
    }
}

