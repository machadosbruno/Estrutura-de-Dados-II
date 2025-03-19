//main.c
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

//Fun��o recursiva que exibe a sub-�rvore iniciada em no em PR�-ORDEM
void PreOrdemNo(NoArvore *no)
{
	if(no != NULL)
	{
		printf("%d ", no->Valor);
		PreOrdemNo(no->Esquerda);
		PreOrdemNo(no->Direita);
	}
}

//Exibe os n�s da �rvore informada utilizando o percurso PR�-ORDEM
void PreOrdem(Arvore *a)
{
	if(a != NULL) {
		printf("PRE: ");
		PreOrdemNo(a->Raiz);
		printf("\n");
	}
}

//Fun��o recursiva que exibe a sub-�rvore iniciada em no em EM-ORDEM
void EmOrdemNo(NoArvore *no)
{
	if(no != NULL)
	{		
		EmOrdemNo(no->Esquerda);
		printf("%d ", no->Valor);
		EmOrdemNo(no->Direita);
	}
}

//Exibe os n�s da �rvore informada utilizando o percurso EM-ORDEM
void EmOrdem(Arvore *a)
{
	if(a != NULL) {
		printf(" EM: ");
		EmOrdemNo(a->Raiz);
		printf("\n");
	}
}

//Fun��o recursiva que exibe a sub-�rvore iniciada em no em P�S-ORDEM
void PosOrdemNo(NoArvore *no)
{
	if(no != NULL)
	{
		PosOrdemNo(no->Esquerda);
		PosOrdemNo(no->Direita);
		printf("%d ", no->Valor);
	}
}

//Exibe os n�s da �rvore informada utilizando o percurso P�S-ORDEM
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
			;//remover da �rvore
		else
			break;
	}
	
	return 0;
}
