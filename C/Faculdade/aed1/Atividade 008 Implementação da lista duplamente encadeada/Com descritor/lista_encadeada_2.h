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
typedef struct descritor Descritor;

struct descritor
{
    int qtde;
    No* primeiro;
    No* ultimo;
};

/*--------------------------------------------------------------------------*/
Descritor* criar()
{
    Descritor *d;

    d = (Descritor *)malloc( sizeof( Descritor ) );
    d->qtde = 0;
    d->primeiro = NULL;

    return d;
}

/*--------------------------------------------------------------------------*/
void imprimir( Descritor *lista )
{
    No *temp;

    temp = lista -> primeiro;

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

    temp = lista -> primeiro;

    while( temp != NULL )
    {
        if (temp -> dado == dado)
            return 1;

        temp = temp -> prox;
    }

    return 0;
}

/*--------------------------------------------------------------------------*/
No* excluir_fim(Descritor *lista)
{
    if (lista -> primeiro == NULL)
        return lista;

    else if (lista -> primeiro != NULL)
    {
        No *temp = lista -> primeiro;
        No *ant = lista -> primeiro;

        while (1)
        {
            if (temp -> prox == NULL)
            {
                ant -> prox = NULL;
                lista -> ultimo = ant;

                lista -> qtde --;

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
No* excluir_inicio(Descritor *lista)
{
    if (lista -> primeiro == NULL)
        return lista;

    else if (lista -> primeiro != NULL)
    {
        No *temp = lista -> primeiro;
        lista -> primeiro = temp -> prox;
        lista -> primeiro -> ant = NULL;

        lista -> qtde--;

        temp -> prox = NULL;
        temp -> ant = NULL;
        temp = NULL;
        free(temp);

        return lista;
    }
}

/*--------------------------------------------------------------------------*/
No* adicionar_fim(Descritor *lista, int dado)
{
    No *novo = (No *)malloc( sizeof( No ) );

    novo -> dado = dado;
    novo -> prox = NULL;

    if (lista -> primeiro == NULL)
    {
        lista -> ultimo = novo;
        lista -> primeiro = novo;
        lista -> primeiro -> prox = NULL;

        lista -> qtde ++;

        novo = NULL;
        free(novo);

        return lista;
    }

    else if (lista -> primeiro != NULL)
    {
        No *temp = lista -> primeiro;

        while (1)
        {
            if (temp -> prox == NULL)
            {
                lista -> ultimo = novo;
                temp -> prox = novo;
                novo -> ant = temp;

                lista -> qtde ++;

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
No* adicionar_inicio(Descritor * lista, int dado)
{
    No *novo = (No *)malloc( sizeof( No ) );

    novo -> dado = dado;
    novo -> prox = lista -> primeiro;
    novo -> ant = NULL;

    if (lista == NULL)
        lista -> ultimo = novo;

    lista -> primeiro -> ant = novo;
    lista -> primeiro = novo;

    lista -> qtde ++;

    novo = NULL;
    free(novo);

    return lista;
}