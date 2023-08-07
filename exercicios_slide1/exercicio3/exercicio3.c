#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 10
#define MAX_TELEFONE 10
#define PESSOA_TAM (sizeof(char)*MAX_NOME + sizeof(int) + sizeof(char)*MAX_TELEFONE + sizeof(void**))

//PESSOA = NOME | IDADE | TELEFONE | pProxPessoa

void imprimirMenu() {
    printf("\n\n-----------------------");
    printf("\nAGENDA ELETRONICA");
    printf("\n-----------------------\n");
    printf("1 - Incluir pessoa\n");
    printf("2 - Excluir pessoa\n");
    printf("3 - Buscar pessoa\n");
    printf("4 - Listar todas as pessoas\n");
    printf("5 - Sair\n");
}

void incluirPessoa(void *pBuffer) {
    int *numPessoas = (int*)pBuffer;
    char *nome, *telefone;
    int *idade;

    (*numPessoas)++;

    pBuffer = (void*)realloc(pBuffer, sizeof(int) + (*numPessoas) * PESSOA_TAM);

    nome = (char*)pBuffer + sizeof(int) + (*numPessoas - 1) * PESSOA_TAM;
    idade = (int*)(nome + sizeof(char)*MAX_NOME);
    telefone = (char*)(idade + sizeof(int));

    printf("\nDigite o nome: ");
    scanf("%s", nome);

    printf("Digite a idade: ");
    scanf("%d", idade);

    printf("Digite o telefone: ");
    scanf("%s", telefone);

    if(*numPessoas == 1){
        *(void**)(telefone+sizeof(char)*MAX_TELEFONE) = NULL;
    }else{
        *(void**)(telefone+sizeof(char)*MAX_TELEFONE) = NULL;
        void **pessoaAtual = (void**)pBuffer + sizeof(int) + (PESSOA_TAM * (*numPessoas-1));
        void **pPessoaAnterior = pessoaAtual-sizeof(void**);
        pPessoaAnterior = pessoaAtual;
    }

    printf("\nPessoa incluida com sucesso!\n");
}

void listarPessoa(void *pBuffer) {
    int *numPessoas = (int*)pBuffer;

    // Verifica se existem pessoas cadastradas
    if (*numPessoas == 0) {
        printf("\nNenhuma pessoa cadastrada!\n");
        return;
    }

    char *nome;
    int *idade;
    char *telefone;

    // Ponteiro para a primeira pessoa
    void **pessoaAtual = (void**)pBuffer + sizeof(int);

    // Percorre a lista de pessoas
    while (pessoaAtual != NULL) {
        nome = (char*)pBuffer + sizeof(int);
        idade = (int*)(nome + sizeof(char)*MAX_NOME);
        telefone = (char*)(idade + sizeof(int));

        printf("\nNome: %s", nome);
        printf("\nIdade: %d", *idade);
        printf("\nTelefone: %s", telefone);

        // Avança para a próxima pessoa
        pessoaAtual = (void**)(telefone + sizeof(char)*MAX_TELEFONE);
    }
}

int main() {
    void *pBuffer = malloc(sizeof(int));

    if (!pBuffer) {
        printf("\nErro de alocacao de memoria!\n");
        exit(1);
    }

    int *numPessoas = (int*)pBuffer;
    *numPessoas = 0;

    int opcao = 0;

    while (opcao != 5) {
        imprimirMenu();

        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluirPessoa(pBuffer);
                break;
            case 2:
                printf("\nOpcao ainda nao implementada!\n");
                break;
            case 3:
                printf("\nOpcao ainda nao implementada!\n");
                break;
            case 4:
                listarPessoa(pBuffer);               
                break;
            case 5:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    }

    free(pBuffer);

    return 0;
}