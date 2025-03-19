//main.c
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

//Função recursiva que exibe a sub-árvore iniciada em no em PRÉ-ORDEM
void PreOrdemNo(NoArvore *no)
{
	if(no != NULL)
	{
		printf("%d ", no->Valor);
		PreOrdemNo(no->Esquerda);
		PreOrdemNo(no->Direita);
	}
}

//Exibe os nós da árvore informada utilizando o percurso PRÉ-ORDEM
void PreOrdem(Arvore *a)
{
	if(a != NULL) {
		printf("PRE: ");
		PreOrdemNo(a->Raiz);
		printf("\n");
	}
}

//Função recursiva que exibe a sub-árvore iniciada em no em EM-ORDEM
void EmOrdemNo(NoArvore *no)
{
	if(no != NULL)
	{		
		EmOrdemNo(no->Esquerda);
		printf("%d ", no->Valor);
		EmOrdemNo(no->Direita);
	}
}

//Exibe os nós da árvore informada utilizando o percurso EM-ORDEM
void EmOrdem(Arvore *a)
{
	if(a != NULL) {
		printf(" EM: ");
		EmOrdemNo(a->Raiz);
		printf("\n");
	}
}

//Função recursiva que exibe a sub-árvore iniciada em no em PÓS-ORDEM
void PosOrdemNo(NoArvore *no)
{
	if(no != NULL)
	{
		PosOrdemNo(no->Esquerda);
		PosOrdemNo(no->Direita);
		printf("%d ", no->Valor);
	}
}

//Exibe os nós da árvore informada utilizando o percurso PÓS-ORDEM
void PosOrdem(Arvore *a)
{
	if(a != NULL) {
		printf("POS: ");
		PosOrdemNo(a->Raiz);
		printf("\n");
	}
}

int main(void)
{
	int n;
	
	Arvore *a = ArvoreNovo();
		
	while(1)
	{
		system("cls");
		printf("Tamanho: %d\n\n", a->Tamanho);
		
		PreOrdem(a);
		EmOrdem(a);
		PosOrdem(a);
				
		printf("\n>> ");
		scanf("%d", &n);
	
		if(n > 0)
			ArvoreInserir(a, n);
		else if(n < 0)
			;//remover da árvore
		else
			break;
	}
	
	return 0;
}
