/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
	Curso: Sistemas de Informação
*/

#include "lista_encadeada_2.h"

int main(int argc, char** argv)
{

    /* para fins de esclarecimento, o início da lista
    corresponde ao último valor adicionado em uma lista,
    ou seja, na lista [3 2 1], o início corresponde ao
    nó que contém o valor "3". Logo, seu fim corresponde
    ao nó que contém o valor "1" */

    Descritor *lista;

    lista = criar();

    for (int i = 0; i < 3; i++)
    {
        int elemento;
        scanf("%d", &elemento);
        lista = adicionar_fim(lista, elemento);
    }

    imprimir(lista);

    lista = excluir_inicio(lista);

    imprimir(lista);

    lista = excluir_fim(lista);

    imprimir(lista);

    lista = adicionar_inicio(lista, 1);

    imprimir(lista);

    return 0;
}