//arvore.h
#include <stdlib.h>

//Representa um n� de uma �rvore bin�ria de busca
typedef struct NoArvore
{
	int Valor;	//Valor armazenado no n� da �rvore
	struct NoArvore *Esquerda;	//Ponteiro para o filho � esquerda do n�
	struct NoArvore *Direita;	//Ponteiro para o filho � direita do n�
}NoArvore;

//Representa uma �rvore bin�ria de busca
typedef struct Arvore
{
	NoArvore *Raiz;	//Ponteiro para a raiz da �rvore
	int Tamanho;	//Quantidade de n�s presentes na �rvore
}Arvore;

//Fun��o que cria uma nova �rvore bin�ria de busca
Arvore* ArvoreNovo()
{
	Arvore *a = malloc(sizeof(Arvore));
	
	if(a != NULL)
	{
		a->Raiz = NULL;
		a->Tamanho = 0;
	}
	
	return a;
}


//Fun��o que insere o valor informado na �rvore informada
//Retorna 1 se sucesso, 0 se erro
int ArvoreInserir(Arvore *a, int valor)
{
	if(a == NULL)
		return 0;
	
	NoArvore *novo = malloc(sizeof(NoArvore));
	
	if(novo == NULL)
		return 0;
		
	novo->Valor = valor;
	novo->Esquerda = NULL;
	novo->Direita = NULL;
	
	NoArvore *atual = a->Raiz;
	NoArvore *pai = NULL;
	
	while(atual != NULL)
	{
		pai = atual;
		
		if(valor < atual->Valor)
			atual = atual->Esquerda;
		else
			atual = atual->Direita;
	}
	
	if(pai == NULL)
		a->Raiz = novo; //inser��o da raiz
	else if(valor < pai->Valor)
		pai->Esquerda = novo; //inser��o � esquerda do pai
	else
		pai->Direita = novo; //inser��o � direita do pai
		
	a->Tamanho = a->Tamanho + 1;
	return 1;
	
}







