#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

//Função recursiva que exibe a sub-árvore iniciada em no o perucurso EM-ORDEM
void EmOrdemNo(NoArvore *no) {
    if(no != NULL){
        EmOrdemNo(no->FilhoEsquerda);
        if(no->FilhoDireita == NULL && no->FilhoEsquerda ==  NULL)
            printf("%d ", no->Valor);
        EmOrdemNo(no->FilhoDireita);
    }
}

//Exibe os elementos da árvore informada utilizando o percurso EM-ordem
void EmOrdem(Arvore *a){
    if(a != NULL)
        printf("Nos folhas em ordem crescente: ");
        EmOrdemNo(a->Raiz);
}

int main (void){
    int n;
    Arvore *a = ArvoreNovo();

    while(1){
        system("cls");

        EmOrdem(a);

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
