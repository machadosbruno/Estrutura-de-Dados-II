#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"

//Função recursiva que exibe a sub-árvore iniciada em no o perucurso EM-ORDEM
void EmOrdemNo(NoArvore *no) {
    if(no != NULL){
        EmOrdemNo(no->FilhoDireita);
        printf("%d ", no->Valor);
        EmOrdemNo(no->FilhoEsquerda);
    }
}

//Exibe os elementos da árvore informada utilizando o percurso EM-ordem
void EmOrdem(Arvore *a){
    if(a != NULL)
        printf("Ordem decrescente: ");
        EmOrdemNo(a->Raiz);
}


int main (void){
    int n;
    Arvore *a = ArvoreNovo();

    for(int i = 0; i <= 20; i++){
        system("cls");
        printf("Tamanho: %d\n\n", a->Tamanho);

        EmOrdem(a);
        printf("\n\n");

        n = rand() * 10;

        if(n > 0){
            ArvoreInserir(a, n);
        }
        else{
            break;
        }
    }
    return 0;
}

