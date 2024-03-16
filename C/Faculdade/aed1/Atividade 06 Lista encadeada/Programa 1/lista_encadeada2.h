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
    No* prox;
};

/*--------------------------------------------------------------------------*/
No* criar()
{
    return NULL;
}

/*--------------------------------------------------------------------------*/
No* inserir( No *lista, int dado )
{
    No *novo;

    novo = (No *)malloc( sizeof( No ) );
    novo->dado = dado;
    novo->prox = lista;

    return novo;
}

/*--------------------------------------------------------------------------*/
No* excluir( No *lista )
{
    No *temp;

    temp = lista;
    lista = lista->prox;

    temp->prox = NULL;
    free(temp);

    return lista;

}

/*--------------------------------------------------------------------------*/
void imprimir( No *lista )
{
    No *temp;

    temp = lista;

    while( temp != NULL )
    {
        printf( "%d ", temp->dado );
        temp = temp->prox;
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
        if (temp->dado == dado)
            return 1;

        temp = temp->prox;
    }

    return 0;
}

No* adicionar( No *lista, int dado )
{
    No *novo;
    novo = (No *)malloc( sizeof( No ) );

    novo->dado = dado;
    novo->prox = lista;

    lista = novo;
    novo = NULL;
    free(novo);

    return lista;
}

No* excluir_elemento(No *lista, int dado)
{
    No *temp;
    No *ant;
    ant = lista;
    temp = lista;
    int var_controle = 0, cont_controle = 0;

    while (var_controle == 0 && temp != NULL)
    {
        if (temp -> dado == dado)
        {
            var_controle = 1;

            if (cont_controle > 0)
            {
                ant -> prox = temp -> prox;

                temp = NULL;
                free(temp);
                ant = NULL;
                free(ant);
            }

            if (cont_controle == 0)
            {
                lista = lista -> prox;
                temp = NULL;
                free(temp);
                ant = NULL;
                free(ant);
            }
        } else {
            ant = temp;
            temp = temp -> prox;
            cont_controle++;
        }
    }
    return lista;
}