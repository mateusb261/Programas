/*
	Nome: Mateus Bastos Magalhães Mar
	Matrícula: 2215310063
	Curso: Sistemas de Informação
*/

#include "lista_encadeada2.h"

int main(int argc, char** argv)
{
    No *lista;

    lista = criar(); //lista = NULL;

    for (int i = 0; i < 1000; i++)
    {
        int elemento;
        scanf("%d", &elemento);
        lista = adicionar(lista, elemento);
    }

    imprimir(lista);

    return 0;
}