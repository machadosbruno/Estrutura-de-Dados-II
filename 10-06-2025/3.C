int funcao(char *str, int M){
    int soma = 0;
    int i = 0;
    while(str[i] != '\0'){
        soma = soma + i * (int)str[i];
        i++;
    }
    return soma;
}
