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
    char dado;
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
No* excluir_fim(No *lista)
{
    if (lista == NULL)
        return lista;

    else if (lista != NULL)
    {
        No *temp = lista;
        No *ant = lista;

        while (1)
        {
            if (temp -> prox == NULL)
            {
                ant -> prox = temp -> prox;

                temp = NULL;
                free(temp);
                ant = NULL;
                free(ant);

                return lista;
            }

            else if (temp -> prox != NULL)
            {
                ant = temp;
                temp = temp -> prox;
            }
        }
    }
}

/*--------------------------------------------------------------------------*/
No* excluir_inicio(No *lista)
{
    if (lista == NULL)
        return lista;

    No *temp = lista;
    lista = lista -> prox;
    lista -> ant = NULL;


    temp -> prox = NULL;
    temp -> ant = NULL;
    temp = NULL;
    free(temp);

    return lista;
}

/*--------------------------------------------------------------------------*/
No* adicionar_fim(No *lista, char dado)
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

    else if (lista != NULL)
    {
        No *temp = lista;

        while (1) {
            if (temp -> prox == NULL)
            {
                temp -> prox = novo;
                novo -> ant = temp;

                novo = NULL;
                free(novo);
                temp = NULL;
                free(temp);

                return lista;
            }

            else if (temp -> prox != NULL)
                temp = temp -> prox;
        }
    }
}

/*--------------------------------------------------------------------------*/
No* adicionar_inicio(No* lista, int dado)
{
    No *novo = (No *)malloc( sizeof( No ) );

    novo -> dado = dado;
    novo -> prox = lista;
    novo -> ant = NULL;

    lista -> ant = novo;
    lista = novo;

    novo = NULL;
    free(novo);

    return lista;
}

