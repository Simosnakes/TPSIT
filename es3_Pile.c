/*Chiedere una stringa all'utente e verificare se è palindroma*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct no {
    char valore;
    struct no *next;

} Node;

int is_empty(Node* head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Node** head, Node* elemento){
    
    if(is_empty(*head)){
        *head = elemento;
        elemento->next = NULL;
    }else{
        elemento->next = *head;
        *head = elemento;
    }
}

Node* pop(Node** head){
    Node* ret = *head;

    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
        return ret;
    }
}

void stampaPila(Node* lista){
    Node* l = lista;
    printf("\nValori pila: ");
    while (l != NULL)
    {
        printf("%c ", l->valore);
        l = l ->next;
    }
}

int main(){
    Node* head = NULL;

    char* stringa;
    printf("Inserisci la parola: ");
    scanf("%s", stringa);

    int lung = strlen(stringa);
    bool palindroma = true;

    for(int k = 0; k < lung; k++){
        Node* elemento = (Node*)malloc(sizeof(Node));
        elemento->valore = *(stringa + k);
        push(&head, elemento);
    }
    
    for(int j = 0; j < lung; j++){
        Node* elemento = pop(&head);
        
        if(elemento->valore != *(stringa + j)){
            palindroma = false;
            printf("%d", lung);
        }

        free(elemento);
    }

    printf("ciao");

    if(palindroma == true){
        printf("è palindroma");
    }else{
        printf("non è palindroma");
    }
    
}