#include <stdio.h>
#include "trie.h"

int main(){
    char entrada[100];
    printf("Digite '+coisa' para adicionar a palavra 'coisa'\n");
    printf("Ou digite '-coisa' para remover a palavra 'coisa'\n\n");
    printf("Digite 0 (zero) para sair\n");
    trie *arvore = criarTrie();
    while(strcmp(entrada, "0")){
        printf(">");
        scanf("%s", entrada);
        if(entrada[0] == '+'){
            inserirEntrada(arvore, entrada);
        }/*else if(strcmp(entrada[0], "-"){
            ;
        }else{
            ;
        }*/
    }
}
