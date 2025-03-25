#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

//Função recursiva que percorre a sub-árvore iniciada em no o perucurso EM-ORDEM
//calculando as alturas dos nós folhas.
int AlturaNo(NoArvore *no) {
    if(no != NULL){
        int AlturaEsquerda = AlturaNo(no->FilhoEsquerda);
        int AlturaDireita = AlturaNo(no->FilhoDireita);
        if(AlturaEsquerda > AlturaDireita)
            return 1 + AlturaEsquerda;
        else
            return 1 + AlturaDireita;
    }
    else{
        return 0;
    }
}

//Exibe a altura
void Altura(Arvore *a){
    if(a != NULL && a->Raiz != NULL)
        printf("Altura: %d", AlturaNo(a->Raiz));
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
        printf(" EM: ");
        EmOrdemNo(a->Raiz);
}

int main (void){
    int n;
    Arvore *a = ArvoreNovo();
    while(1){
        system("cls");

        EmOrdem(a);
        Altura(a);

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

