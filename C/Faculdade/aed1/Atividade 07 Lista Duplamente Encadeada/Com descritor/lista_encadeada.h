/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
	Curso: Sistemas de Informação
*/

#include <stdio.h>
#include <stdlib.h>

/* definição da estrutura de dados */
typedef struct no No;

struct no
{
    int dado;
    No* ant;
    No* prox;
};

/* definição do descritor */
typedef struct descritor
{
    int qtde;
    No* lista;
} Descritor;

/*--------------------------------------------------------------------------*/
Descritor* criar()
{
    Descritor *d;

    d = (Descritor *)malloc( sizeof( Descritor ) );
    d->qtde = 0;
    d->lista = NULL;

    return d;
}

/*--------------------------------------------------------------------------*/
void imprimir( Descritor *lista )
{
    No *temp;

    temp = lista -> lista;

    while( temp != NULL )
    {
        printf( "%d ", temp -> dado );
        temp = temp -> prox;
    }

    printf("\n");
}

/*--------------------------------------------------------------------------*/
int buscar( Descritor *lista, int dado )
{
    No *temp;

    temp = lista -> lista;

    while( temp != NULL )
    {
        if (temp -> dado == dado)
            return 1;

        temp = temp -> prox;
    }

    return 0;
}

/*--------------------------------------------------------------------------*/
No* excluir_início(Descritor *lista)
{
    if (lista -> lista == NULL) {
        lista -> qtde --;
        return lista;
    }

    else if (lista -> lista != NULL) {

        No *temp = lista -> lista;
        No *ant = lista -> lista;

        int var_controle = 0;

        while (var_controle == 0) {
            if (temp -> prox == NULL) {
                var_controle = 1;

                ant -> prox = temp -> prox;

                lista -> qtde --;

                temp = NULL;
                free(temp);
                ant = NULL;
                free(ant);

                return lista;
            }

            else if (temp -> prox != NULL) {
                ant = temp;
                temp = temp -> prox;
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
No* excluir_fim(Descritor *lista)
{
    No *temp = lista -> lista;
    lista -> lista = temp -> prox;

    lista -> qtde --;

    temp -> prox = NULL;
    temp -> ant = NULL;
    temp = NULL;
    free(temp);

    return lista;
}

/*--------------------------------------------------------------------------*/
No* adicionar_início(Descritor *lista, int dado)
{
    No *novo = (No *)malloc( sizeof( No ) );

    novo -> dado = dado;
    novo -> prox = NULL;

    if (lista -> lista == NULL)
    {
        lista -> lista = novo;
        lista -> lista -> prox = NULL;

        lista -> qtde ++;

        novo = NULL;
        free(novo);

        return lista;
    }

    else if (lista -> lista != NULL) {

        int var_controle = 0;
        No *temp = lista -> lista;

        while (var_controle == 0) {
            if (temp -> prox == NULL) {
                var_controle = 1;

                temp -> prox = novo;
                novo -> ant = temp;

                lista -> qtde ++;

                novo = NULL;
                free(novo);
                temp = NULL;
                free(temp);

                return lista;
            }

            else if (temp -> prox != NULL) {
                temp = temp -> prox;
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
No* adicionar_fim(Descritor * lista, int dado)
{
    No *novo = (No *)malloc( sizeof( No ) );

    novo -> dado = dado;
    novo -> prox = lista -> lista;
    novo -> ant = NULL;

    lista -> lista = novo;

    lista -> qtde ++;

    novo = NULL;
    free(novo);

    return lista;
}