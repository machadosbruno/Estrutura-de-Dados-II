typedef struct trie {
    struct trie *filhos[4];
} trie;

criarTrie(){
    trie* arvore = malloc(sizeof(trie));
    return arvore;
}

inserirEntrada(trie *no, char entrada[100]){
    if(no != NULL){
        for(int i = 1; entrada[i] != '\0'; i++){
            if(entrada[i] == 'a'){
                trie *novoNo = criarTrie();
                if(novoNo != NULL){
                    no->filhos[0] = novoNo;
                    printf("%x\n", no->filhos[0]);
                }
            }
        }
    }
}
