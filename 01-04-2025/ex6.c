#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

//Função recursiva que exibe a sub-árvore iniciada em no em PRÉ-ORDEM
void PreOrdemNo(NoArvore *no) {
    if(no != NULL){
        printf("%d ", no->Valor);
        PreOrdemNo(no->FilhoEsquerda);
        PreOrdemNo(no->FilhoDireita);
    }
}

//Exibe os elementos da árvore informada utilizando o percurso pré-ordem
void PreOrdem(Arvore *a){
    if(a != NULL)
        printf("Pre Ordem: ");
        PreOrdemNo(a->Raiz);
}


//Função recursiva que exibe a sub-árvore iniciada em no o perucurso EM-ORDEM
void EmOrdemNo(NoArvore *no) {
    if(no != NULL){
        EmOrdemNo(no->FilhoEsquerda);
        printf("%d ", no->Valor);
        EmOrdemNo(no->FilhoDireita);
    }
}

//Exibe os elementos da árvore informada utilizando o percurso EM-ordem
void EmOrdem(Arvore *a){
    if(a != NULL)
        printf("EM: ");
        EmOrdemNo(a->Raiz);
}


//Função recursiva que exibe a sub-árvore iniciada em no o perucurso PÓS-ORDEM
void PosOrdemNo(NoArvore *no) {
    if(no != NULL){
        PosOrdemNo(no->FilhoEsquerda);
        PosOrdemNo(no->FilhoDireita);
        printf("%d ", no->Valor);
    }
}

//Exibe os elementos da árvore informada utilizando o percurso PÓS-ORDEM
void PosOrdem(Arvore *a){
    if(a != NULL)
        printf("POS: ");
        PosOrdemNo(a->Raiz);
}

void MedianaNo(NoArvore *no, int meio, int *indice){
    if(no != NULL){
        MedianaNo(no->FilhoEsquerda, meio, indice);
        *indice = *indice + 1;
        if(*indice == meio)
            printf("%d", no->Valor);
        else{
            if(*indice < meio)
                MedianaNo(no->FilhoDireita, meio, indice);
        }
    }
}

void Mediana(Arvore *a){
    if(a != NULL && a->Tamanho % 2 == 1){
        int indice = -1;
        printf("Mediana: ");
        MedianaNo(a->Raiz, (int) a->Tamanho/2, indice);
        printf("\n");
    }
}

int main (void){
    int n;
    Arvore *a = ArvoreNovo();

    while(1){
        system("cls");
        printf("Tamanho: %d\n\n", a->Tamanho);

        PreOrdem(a);
        printf("\n\n");
        EmOrdem(a);
        printf("\n\n");
        PosOrdem(a);
        printf("\n\n");
        Mediana(a);
        printf("\n\n>> ");
        scanf("%d", &n);
        if(n > 0){
            ArvoreInserir(a, n);
        }
        else if(n < 0){
            ArvoreRemover(a, -n);
        }
        else{
            break;
        }
    }
    return 0;
}
