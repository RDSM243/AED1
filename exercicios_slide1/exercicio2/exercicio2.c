#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_SIZE 12

void add_name(char **names, int *chars_quant){

    char name[NAME_SIZE]; 
    int new_name_size;

    printf("\nDigite um nome(com 12 digitos): ");
    scanf("%s", &name);

    new_name_size = strlen(name);

    if (*names != NULL){
        *names = (char*)realloc(*names, (*chars_quant + new_name_size + 1) * sizeof(char));

        strcpy(*names+*chars_quant, name);
        *chars_quant += new_name_size + 1;

        printf("\nNome alocado com sucesso");
    }else{
        printf("\nFalha ao alocar o nome a memoria");
    }
}

void remove_name(char **names, int *chars_quant){
    if(chars_quant == 0){
        printf("\nNenhum nome foi armazenado");
    }else{
        char removed_name[NAME_SIZE];

        printf("\nDigite o nome a ser removido: ");
        scanf("%s", &removed_name);

        char *remove_name_pos = strstr(*names, removed_name);
        
        if (remove_name_pos == NULL){
            printf("\nNome nao encontrado");
            return;
        }
        
        int remove_name_size = strlen(removed_name);

        // tudo que vier depois desse nome sera realocado na posição do nome removido em diante
        memmove(remove_name_pos, remove_name_pos + remove_name_size + 1, *names + *chars_quant - (remove_name_pos + remove_name_size + 1) + 1);
        *chars_quant -= remove_name_size + 1;

        printf("\nNome removido com sucesso.");
    }
}

void list_names(char *names, int chars_quant){

    if(chars_quant == 0){
        printf("\nNenhum nome foi armazenado");
    }else{

        printf("\nLista de nomes : ");
        int i = 0;
        while (i < chars_quant)
        {
            printf("%s\n", names + i);
            i += strlen(names + i) + 1;
        }
    }

}

int main(void){

    int option, chars_quant = 0;
    char* names;

    add_name(&names, &chars_quant);

    list_names(names, chars_quant);

    remove_name(&names, &chars_quant);
    
    list_names(names, chars_quant);
    
    free(names);

    return 0;
}