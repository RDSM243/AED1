#include <stdio.h>
#include <stdlib.h>

#define NAME_MAX 10

void *pBuffer; 
int *nPessoas; 

void addPessoa(){

  

  *nPessoas += 1;
}

int main(void){

  pBuffer = malloc(sizeof(int));
  nPessoas = (int*)pBuffer;
  *nPessoas = 0;


  return 0;
}
