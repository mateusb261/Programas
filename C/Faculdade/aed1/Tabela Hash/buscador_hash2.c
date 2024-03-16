/*------------------------------------------------------------------
-------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO 10  // Tamanho da tabela hash
#define BUSCA 3     // Nº de termos de busca


/* definição da estrutura de dados */
typedef struct no No;
struct no {
	char info[15];
	No *prox;
};

No *tabela[TAMANHO];


// Insere um novo nó no início de uma lista
No *inserir_adjacente( No *lista, char info[] )
{
	No *novo;
	novo = (No *)malloc( sizeof( No ) );

	strcpy( novo->info, info );

	novo->prox = lista;
	
	return novo;
}


// Calcula o índice da tabela hash com base na string info
int faz_hash( char info[] )
{
	int indice = 0;
	int i;

	for (i = 0; i < 11; i++)
		indice += info[i] * i * i;
	
	indice %= TAMANHO; // % como os limites da tabela

	return indice;
}

// Insere um novo valor na tabela hash
void inserir( char info[] )
{
	int funcao_hash;
	
	funcao_hash = faz_hash( info );

	printf("hash = %d info= %s \n", funcao_hash, info );

	tabela[funcao_hash] = inserir_adjacente( tabela[funcao_hash], info);
}


// Exibe o conteúdo da tabela hash
void imprimir( No *g[] )
{
	int i;
	No *atual;

	for ( i = 0; i < TAMANHO; i++ )
	{	
		// Se a lista estiver vazia
		if ( g[i] == NULL )
			printf( "%d -> .\n", i );

		// Se a lista estiver com valores
		else
		{
			atual = g[i];
			
			printf( "%d ->", i );
	
			while( atual != NULL )
			{
				printf( " %s ", atual->info );
				atual = atual->prox;
			}
			printf("\n");
		}
	}
}

/*--------------------------------------------------------------------------*/
int busca_lista( No *lista, char chave[] )
{
	No *c;
	int achou = -1;
	int i = 0;

	c = lista;

	while( c != NULL && achou == -1 )
	{
		if ( !strcmp(c->info,chave ) )
		{
			achou = i;
		}
		else
		{
			i++;
			c = c->prox;
		}
	}

	return achou;
}

/*--------------------------------------------------------------------------*/
int busca_hash( char chave[] )
{
	int achou;
	int indice;

	indice = faz_hash( chave );

	achou = busca_lista( tabela[indice],chave );

	return achou;
}

/*--------------------------------------------------------------------------*/
int main(int argc, char* argv[])
{
	char busca[BUSCA][15];
	int i;
	int achou;
	double start,stop,elapsed;
	char chave[15];
	int min,seg,visualizacao,qualidade;
	float opiniao;

	// inicializa a tabela hash
	for ( i = 0; i < TAMANHO; i++ )
		tabela[i] = NULL;

	// abre o arquivo texto dos videos linhas
 	for (i = 0; i < TAMANHO; i++)
	{
		scanf("%s %d %d %d %d %f",
			chave,
			&min,
			&seg,
			&visualizacao,
			&qualidade,
			&opiniao
		);
		inserir(chave);
	}
	
	// abre o arquivo texto dos videos para procurar
 	for (i = 0; i < BUSCA; i++)
	{
		scanf("%s", chave);
		strcpy( busca[i], chave );
	}	

	// imprime a tabela hash
	printf("\nTabela Hash\n");
	imprimir( tabela );
	printf("\n");
	
	//-----------------------------------------------------------------------------
	printf( "busca hash:\n" );

	start = (double) clock() / CLOCKS_PER_SEC;
	
	achou = -1;
	
	for ( i = 0; i<BUSCA; i++)
	{
		achou = busca_hash(busca[i]);

		if ( achou >= 0 )
			printf("[%d] %s encontrado ^_^\n",i, busca[i] );
		else
			printf("%s nao encontrado =(\n",busca[i]);
	}
	
	stop = (double) clock() / CLOCKS_PER_SEC;
	
	elapsed = (double) stop - start;

	printf("em %f segundos\n", elapsed );
	
	return 0;
}
