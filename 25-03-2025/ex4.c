#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

//Função recursiva que exibe a sub-árvore iniciada em no em PRÉ-ORDEM
void EhDeBuscaNo(NoArvore *no) {
    if(no != NULL){
        if(NoArvore->FilhoEsquerda->Valor < NoArvore->Valor)
            EhDeBuscaNo(NoArvore->FilhoEsquerda);
        else
            return;
    }
}

//Exibe os elementos da árvore informada utilizando o percurso pré-ordem
void EhDeBusca(Arvore *a){
    if(a != NULL)
        printf("Pre Ordem: ");
        EhDeBuscaNo(a->Raiz);
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

