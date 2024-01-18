/*Espressione da scrivere {[3 + (5 + 6) * 2] + 1}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct el {
    char valore;
    struct el *next;

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
        printf("%d ", l->valore);
        l = l ->next;
    }
}

int main(){
    int n;
    bool num = false;
    //int lung = 0;
    Node* head = NULL;
    do{
        printf("inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        
        if(n >= 0){
            Node* elemento = (Node*)malloc(sizeof(Node));
            elemento->valore = n;
            push(&head, elemento);
        }
        
    } while (n >= 0);

    stampaPila(head);
    printf("\nFaccio la pop:");
    Node* remuved = pop(&head);
    printf("%d", remuved->valore);
    stampaPila(head);
    if(!num){
        printf("ciao");
    }
}