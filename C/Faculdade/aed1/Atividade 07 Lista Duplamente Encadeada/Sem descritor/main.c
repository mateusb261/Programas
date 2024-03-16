/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
	Curso: Sistemas de Informação
*/

#include "lista_encadeada.h"

int main(int argc, char** argv)
{

    /* para fins de esclarecimento, o início da lista
    corresponderá ao primeiro valor adicionado em uma lista,
    ou seja, na lista [3 2 1], o início corresponde ao nó que
    contém o valor "1". Logo, seu fim corresponde ao nó que
    contém o valor "3" */


    No *lista;

    lista = criar(); //lista = NULL;

    for (int i = 0; i < 3; i++)
    {
        int elemento;
        scanf("%d", &elemento);
        lista = adicionar_fim(lista, elemento);
    }

    lista = excluir_fim(lista);
    imprimir(lista);

    return 0;
}