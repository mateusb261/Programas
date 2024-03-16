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

/*--------------------------------------------------------------------------*/
No* criar()
{
    return NULL;
}


/*--------------------------------------------------------------------------*/
void imprimir( No *lista )
{
    No *temp;

    temp = lista;

    while( temp != NULL )
    {
        printf( "%d ", temp -> dado );
        temp = temp -> prox;
    }

    printf("\n");
}

/*--------------------------------------------------------------------------*/
int buscar( No *lista, int dado )
{
    No *temp;

    temp = lista;

    while( temp != NULL )
    {
        if (temp -> dado == dado)
            return 1;

        temp = temp -> prox;
    }

    return 0;
}

/*--------------------------------------------------------------------------*/
No* excluir_início(No *lista)
{
    if (lista == NULL)
        return lista;

    else if (lista != NULL) {

        No *temp = lista;
        No *ant = lista;

        int var_controle = 0;

        while (var_controle == 0) {
            if (temp -> prox == NULL) {
                var_controle = 1;

                ant -> prox = temp -> prox;

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
No* excluir_fim(No *lista)
{
    No *temp = lista;
    No *var = lista -> prox;
    lista = lista -> prox;

    temp -> prox = NULL;
    temp -> ant = NULL;
    temp = NULL;
    free(temp);

    while (1 == 1)
    {
        if (var -> prox == lista)
        {
            lista -> ant = var;

            return lista;
        }

        else if (var -> prox != lista)
        {
            var = var -> prox;
        }
    }
}

/*--------------------------------------------------------------------------*/
No* adicionar_início(No *lista, int dado)
{
    No *novo = (No *)malloc( sizeof( No ) );

    novo -> dado = dado;
    novo -> prox = NULL;

    if (lista == NULL)
    {
        lista = novo;
        lista -> ant = NULL;
        novo = NULL;
        free(novo);

        return lista;
    }

    else if (lista != NULL) {

        int var_controle = 0;
        No *temp = lista;

        while (var_controle == 0) {
            if (temp -> prox == NULL) {
                var_controle = 1;

                temp -> prox = novo;
                novo -> ant = temp;

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
No* adicionar_fim(No* lista, int dado)
{
    No *novo = (No *)malloc( sizeof( No ) );

    novo -> dado = dado;
    novo -> prox = lista;

    if (lista == NULL) {
        novo -> ant = novo;
        novo -> prox = novo;
        lista = novo;
        novo = NULL;
        free(novo);

        return lista;
    }

    else if (lista != NULL)
    {
        No *temp = lista;
        while (1 == 1)
        {
            if (temp -> prox == lista)
            {
                lista -> ant = novo;
                novo -> ant = temp;
                lista = novo;
                temp -> prox = lista;

                novo = NULL;
                free(novo);

                return lista;
            }

            else if (temp -> prox != lista)
            {
                temp = temp -> prox;
            }
        }
    }
}