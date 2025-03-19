//arvore.h
#include <stdlib.h>

//Representa um nó de uma árvore binária de busca
typedef struct NoArvore
{
	int Valor;	//Valor armazenado no nó da árvore
	struct NoArvore *Esquerda;	//Ponteiro para o filho à esquerda do nó
	struct NoArvore *Direita;	//Ponteiro para o filho à direita do nó
}NoArvore;

//Representa uma árvore binária de busca
typedef struct Arvore
{
	NoArvore *Raiz;	//Ponteiro para a raiz da árvore
	int Tamanho;	//Quantidade de nós presentes na árvore
}Arvore;

//Função que cria uma nova árvore binária de busca
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


//Função que insere o valor informado na árvore informada
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
		a->Raiz = novo; //inserção da raiz
	else if(valor < pai->Valor)
		pai->Esquerda = novo; //inserção à esquerda do pai
	else
		pai->Direita = novo; //inserção à direita do pai
		
	a->Tamanho = a->Tamanho + 1;
	return 1;
	
}







