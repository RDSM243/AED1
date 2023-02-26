#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_TAM 10

void adiciona_pessoas(void **pBuffer, int *n_pessoas){
    char nome[NOME_TAM];
    int idade, telefone;

    printf("Digite o nome (de ate 10 digitos): ");
    scanf("%s", nome);
    printf("Digite a idade: ");
    scanf("%d", &idade);
    printf("Digite o telefone: ");
    scanf("%d", &telefone);

    (*n_pessoas)++;

    *pBuffer = realloc(*pBuffer, (*n_pessoas) * (NOME_TAM + sizeof(int) * 2));

    int * p_quant = (int*)*pBuffer;
    char * p_nome = (char*)(p_quant + 1);
    int * p_idade = (int*)(p_nome + NOME_TAM);
    int * p_telefone = (int*)(p_idade + 1);

    strcpy(p_nome, nome);
    *p_idade = idade;
    *p_telefone = telefone;

    printf("\nDados alocados com sucesso.\n");
}

int main(void){

    void *pBuffer = NULL;
    int n_pessoas = 0;

    adiciona_pessoas(&pBuffer, &n_pessoas);

    free(pBuffer);

    return 0;
}
