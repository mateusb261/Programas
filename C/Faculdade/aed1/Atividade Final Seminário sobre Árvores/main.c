/*

    Nome:   Carla Lapa Nogueira
    Mat:    2215310004

    Nome:   Danilo Silva de Paula
    Mat:    2215080051

    Nome:   Dário Souza Rocha Filho
    Mat:    2215310006

    Nome:   Gabriel Machado Moreira
    Mat:    2215310008

    Nome:   Mateus Bastos Magalhães Mar
    Mat:    2215310063

    Nome:   Matheus dos anjos Pinheiro
    Mat:    2015280041

    Nome:   Nezi Pimentel Ribeiro Neta
    Mat:    2215310058

    Nome:   Samira Farias Costa de Souza
    Mat:    2215310027

*/

#include <stdio.h>
#include <stdlib.h>
#include "rubro_negra.h"

int main ()
{
    No *raiz = cria_arvore_rb();
    int esc=10, alt=0,num,qnt;


    while(esc!=0)
    {   
        printf("1-inserir\n2-imprimir\n3-remover no\n4-buscar no\n0-sair\n");
        scanf("%d", &esc);

        switch (esc)
        {
        case 1:
            scanf("%d", &num);
            insere_arvore_rb(&raiz, num);
            break;
        case 2:
            imprimir(raiz,0);
            printf("\n");
            break;
        case 3:
            printf("Insira o numero pra ser removido: ");
            scanf("%d", &num);
            remove_no(&raiz, num);
            break;
        case 4:
            printf("Insira o numero pra ser procurado: \n");
            scanf("%d", &num);
            achar_no(&raiz, num);
            break;
        case 0:
            printf("\n\n\n\nsaindo...\n\n\n\n"); 
            break; 
        default:
            printf("Entrada invalida\n");
            break;
        }
    }
}