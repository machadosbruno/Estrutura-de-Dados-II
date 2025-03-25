#include <stdlib.h>

//Representa um nó de uma árvore binária de busca
typedef struct NoArvore
{
    int Valor; //Valor armazenado no nó da árvore
    struct NoArvore *FilhoDireita; //Ponteiro para o filho a direita do Nó
    struct NoArvore *FilhoEsquerda; //Ponteiro para o filho a esquerda do Nó
} NoArvore;

//Representa a árvore binária de busca
typedef struct Arvore
{
    NoArvore *Raiz;  //Ponteiro para a Raiz da Arvore
    int Tamanho;  //Quantidade de nós presentes na árvore
}Arvore;

//Criar uma nova árvore
Arvore* ArvoreNovo() {
    Arvore *a = malloc(sizeof(Arvore));
    if(a != NULL){
        a->Raiz = NULL;
        a->Tamanho = 0;
    }
    return a;
}

//Inserir elemento informado na árvore informada
//Retorna 1 se sucesso, 0 se erro
int ArvoreInserir(Arvore *a, int valor){
    if(a == NULL)
        return 0;

    NoArvore *novo = malloc(sizeof(NoArvore));

    if(novo == NULL)
        return 0;

    novo->Valor = valor;
    novo->FilhoEsquerda = NULL;
    novo->FilhoDireita = NULL;

    NoArvore *atual = a->Raiz;
    NoArvore *pai = NULL;

    while(atual != NULL){
        pai = atual;
        if(valor < atual->Valor)
            atual = atual->FilhoEsquerda;
        else
            atual = atual->FilhoDireita;
    }
    if(pai == NULL)
       a->Raiz = novo; //inserção da Raiz
    else if(valor < pai->Valor)
        pai->FilhoEsquerda = novo; //inserção à esquerda do pai
    else
        pai->FilhoDireita = novo; //inserção à direita do pai

    a->Tamanho = a->Tamanho + 1;
    return 1;
}

//Remover elemento informado na árvore informada
//Retorna 1 se sucesso, 0 se erro
int ArvoreRemover(Arvore *a, int valor){
    if(a == NULL || a->Tamanho == 0)
        return 0;

    //Procurar o elemento a ser removido
    NoArvore *atual = a->Raiz;
    NoArvore *pai = NULL;
    while(atual != NULL && atual->Valor != valor){
        pai = atual;
        if(valor < atual->Valor){
            atual = atual->FilhoEsquerda;
        }
        else{
            atual = atual->FilhoDireita;
        }
    }

    //Não encontrei o elemento que eu quero remover
    if(atual == NULL)
        return 0;

    //Encontrei o Nó

    if(atual->FilhoEsquerda == NULL && atual->FilhoDireita == NULL){
        //remoção de nó folha

        //1 - Raiz
        if(pai == NULL)
            a->Raiz = NULL;

        //2 - Filho a esquerda
        else if(valor < pai->Valor)
            pai->FilhoEsquerda = NULL;

        //3 - Filho a direita
        else
            pai->FilhoDireita = NULL;


    }
    else if(atual->FilhoEsquerda != NULL && atual->FilhoDireita == NULL){
        //Remoção de nó com filho apenas à esquerda
        if(pai == NULL)
            a->Raiz = atual->FilhoEsquerda;
        else if(valor < pai->Valor)
            pai->FilhoEsquerda = atual->FilhoEsquerda;
        else
            pai->FilhoDireita = atual->FilhoEsquerda;
    }
    else if(atual->FilhoEsquerda == NULL && atual->FilhoDireita != NULL){
        //Remoção de nó com filho apenas à direita
        if(pai == NULL)
            a->Raiz = atual->FilhoDireita;
        else if(valor < pai->Valor)
            pai->FilhoEsquerda = atual->FilhoDireita;
        else
            pai->FilhoDireita = atual->FilhoDireita;
    }
    else{
        //Remover arvore com dois filhos
        NoArvore *substituto = atual->FilhoEsquerda;
        NoArvore *paiSubstituto = atual;

        while(substituto->FilhoDireita !=  NULL){
            paiSubstituto = substituto;
            substituto = substituto->FilhoDireita;
        }

        if(paiSubstituto != atual){
            paiSubstituto->FilhoDireita = substituto->FilhoEsquerda;
            substituto->FilhoEsquerda = atual->FilhoEsquerda;
        }

        substituto->FilhoDireita = atual->FilhoDireita;

        if(pai == NULL){
            a->Raiz = substituto;
        }
        else if(valor < pai-> Valor){
            pai->FilhoEsquerda = substituto;
        }
        else{
            pai->FilhoDireita = substituto;
        }
    }
    //Limpeza do nó na Heap
    free(atual);
    //diminuir um no tamanho da Raiz
    a->Tamanho = a->Tamanho - 1;
    return 1;
}
