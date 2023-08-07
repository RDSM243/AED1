#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 10
#define MAX_TELEFONE 10
#define PESSOA_TAM (sizeof(char)*MAX_NOME + sizeof(int) + sizeof(char)*MAX_TELEFONE + sizeof(void**)*2)

//PESSOA = NOME | IDADE | TELEFONE | pPessoaAnterior | pProxPessoa

void incluirPessoa(void *pBuffer);
void apagarPessoa(void *pBuffer);
void buscarPessoa(void *pBuffer);
void listarPessoas(void *pBuffer);

int main() {
    void *pBuffer = malloc(sizeof(int));
    int *opcao = (int*)pBuffer;
    *opcao = 0;

    while (*opcao != 5) {
        printf("\nAGENDA\n");
        printf("1. Incluir Pessoa\n");
        printf("2. Apagar Pessoa\n");
        printf("3. Buscar Pessoa\n");
        printf("4. Listar Pessoas\n");
        printf("5. Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", opcao);
        getchar();

        switch (*opcao) {
            case 1:
                incluirPessoa(pBuffer);
                break;
            case 2:
                apagarPessoa(pBuffer);
                break;
            case 3:
                buscarPessoa(pBuffer);
                break;
            case 4:
                listarPessoas(pBuffer);
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

void incluirPessoa(void *pBuffer) {
    int *numPessoas = (int*)pBuffer;

    (*numPessoas)++;

    pBuffer = (void*)realloc(pBuffer, (sizeof(int) + (*numPessoas) * PESSOA_TAM));

    void *novaPessoa = malloc(PESSOA_TAM);

    printf("\nDigite o nome: ");
    scanf("%s", novaPessoa);

    printf("Digite a idade: ");
    scanf("%d", (int*)novaPessoa+(sizeof(char)*MAX_NOME));

    printf("Digite o telefone: ");
    scanf("%s", (char*)novaPessoa+(sizeof(char)*MAX_NOME) + sizeof(int));

    void *pessoaAtual = (pBuffer + sizeof(int));

    if(*numPessoas == 1){
        *(void**)(novaPessoa+sizeof(char)*MAX_NOME+sizeof(int)+sizeof(char)*MAX_TELEFONE) = NULL;
        *(void**)(novaPessoa+sizeof(char)*MAX_NOME+sizeof(int)+sizeof(char)*MAX_TELEFONE+sizeof(void**)) = NULL;
        pessoaAtual = novaPessoa;
    } else {
        void *pessoaAnterior = NULL;
        void *pessoaAtual = pBuffer + sizeof(int);

        // encontrar posição para a nova pessoa na lista
        while (pessoaAtual != NULL && strcmp((char*)novaPessoa, (char*)pessoaAtual) > 0) {
            pessoaAnterior = pessoaAtual;
            pessoaAtual = *(void**)(pessoaAtual+sizeof(char)*MAX_NOME+sizeof(int)+sizeof(char)*MAX_TELEFONE);
        }

        // inserir a nova pessoa na lista
        if (pessoaAnterior == NULL) {
            *(void**)(novaPessoa+sizeof(char)*MAX_NOME+sizeof(int)+sizeof(char)*MAX_TELEFONE) = pessoaAtual;
            *(void**)(pessoaAtual+sizeof(char)*MAX_NOME+sizeof(int)+sizeof(char)*MAX_TELEFONE+sizeof(void**)) = novaPessoa;
            pessoaAtual = novaPessoa;
        } else {
            *(void**)(pessoaAnterior+sizeof(char)*MAX_NOME+sizeof(int)+sizeof(char)*MAX_TELEFONE) = novaPessoa;
            *(void**)(novaPessoa+sizeof(char)*MAX_NOME+sizeof(int)+sizeof(char)*MAX_TELEFONE+sizeof(void**)) = pessoaAtual;
            *(void**)(pessoaAtual+sizeof(char)*MAX_NOME+sizeof(int)+sizeof(char)*MAX_TELEFONE+sizeof(void**)) = novaPessoa;
        }
    }

    printf("\nPessoa incluida com sucesso!\n");
}

void apagarPessoa(void *pBuffer){

}

void buscarPessoa(void *pBuffer){

}

void listarPessoas(void *pBuffer){

}