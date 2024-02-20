#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct nodo {
    int valore;
    struct nodo *next;
} Node;

int is_emptyPila(Node* head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Node** head, Node* elemento){
    
    if(is_emptyPila(*head)){
        *head = elemento;
        elemento->next = NULL;
    }else{
        elemento->next = *head;
        *head = elemento;
    }
}

Node* pop(Node** head){
    Node* ret = *head;

    if(is_emptyPila(*head)){
        return NULL;
    }else{
        *head = ret->next;
        return ret;
    }
}

bool is_empty(Node* head){
    return head == NULL;
}

void enqueue(Node** head, Node** tail, Node* elem){
    if(is_empty(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Node* dequeue(Node** head, Node** tail){
    Node* ret = *head;
    if(is_empty(*head)){
        return NULL;
    }
    else{
        *head = ret->next;
    }
    if(*head == NULL){
        *tail = NULL;
    }
    return ret;
}

void stampaCoda(Node* head){
    Node* l = head;
    printf("\nValori Pila/Coda: ");
    while (l != NULL)
    {
        printf("%d ", l->valore);
        l = l ->next;
    }
}

void confronta(Node** headCoda, Node** headPila, Node** tailCoda){
    bool uguale = true;

    Node* coda = headCoda;
    Node* pila = headPila;

    while(uguale){
        Node* el1 = pop(headPila);
        Node* el2 = dequeue(headPila, tailCoda);
        if(el1->valore != el2->valore){
            uguale = false;
        }

        pila = pila->next;
        coda = coda->next;

        free(el1);
        free(el2);
    }

    if(uguale){
        printf("\nLa pila e la coda sonu uguali");
    }else{
        printf("\nLa pila e la coda sono diverse");
    }
}

int main(){
    Node* lista = NULL;
    Node* headPila = NULL;
    Node* headCoda = NULL;
    Node* tailCoda = NULL;

    for(int k = 0; k < 5; k++){
        Node* elemento = (Node*)malloc(sizeof(Node));
        //inserire valore casuale
        elemento->valore = rand() % 10 + 1;

        push(&headPila, elemento);
    }

    for(int k = 0; k < 5; k++){
        Node* elemento = (Node*)malloc(sizeof(Node));
        //inserire valore casuale
        elemento->valore = rand() % 1 + 1;

        enqueue(&headCoda, &tailCoda, elemento);
    }

    stampaCoda(headCoda);
    stampaCoda(headPila);

    confronta(&headCoda, &headPila, &tailCoda);
}