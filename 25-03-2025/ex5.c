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

//Busca por profundidade
void NivelNo(NoArvore *no, int nivel, int atual){
    if(no != NULL){
        if(nivel == atual){
            printf("%d ", no->Valor);
        }
        else{
            NivelNo(no->FilhoEsquerda, nivel, atual + 1);
            NivelNo(no->FilhoDireita, nivel, atual + 1);
        }
    }
}

void Nivel(Arvore *a, int nivel){
    if(a != NULL && nivel >= 0){
        NivelNo(a->Raiz, nivel, 0);
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
        Nivel(a, 2);

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
