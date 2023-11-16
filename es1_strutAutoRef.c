/*
author: Arrigoni Simone
date
es.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valore;
    struct node* next;
}Node;

int calcolaLunghezza(Node *l){
    int k = 0;
    while(l != NULL){
        k++;
        l=l->next;
    }
    return k;
}

int main(){
    int n;
    Node* lista = NULL;
    Node* l;
    do{
        printf("Inserisci un numero reale o -1 per terminare\n");
        scanf("%d", &n);
        if(n >=0){
            if(lista == NULL){
                lista = (Node*)malloc(sizeof(Node));
                l = lista;
            }else{
                l->next = (Node*)malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    }while(n>=0);
    l = lista;
    printf("numeri inseriti:\n");
    while(l != NULL){
        printf("%d - %p \n", l->valore, l->next);
        l=l->next;
    }
    printf("\n");

    int lung = calcolaLunghezza(lista);
    printf("La lunghezza è: %d", lung);
    return 0;
}