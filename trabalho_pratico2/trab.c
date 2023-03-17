#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

void push( Node** head, int val ) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = *head;
    *head = node;
}

bool isPalindrome(Node *head){
    int word_size = 0;        
    int *aux = NULL;

    while (head != NULL) {
        word_size++;
        aux = (int*)realloc(aux, sizeof(int)*word_size);
        aux[word_size-1] = head->val;
        head = head->next;
    }

    for(int i = word_size-1; i > 0; i--){
        if(aux[(word_size-1)-i] != aux[i]){
            return false;
        }
    }

    return true;
}

int main() {
    Node* head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 2);
    push(&head, 1);

    if(isPalindrome(head)){
        printf("\nA sequencia e um palindromo\n");
    }else{
        printf("\nA sequencia nao e um palindromo\n");
    }

    free(head);

    return 0;
}
