/*
author: Simone Arrigoni
date: 13/11/2023
es. lista 
testo creazione di una lista
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int valore;
    struct node* next;   
}Node;

int calcolaLunghezza(Node* lista){
    Node* l = lista;
    int lung = 0;
    while (l != NULL)
    {
        lung++;
        l = l ->next;
    }
    return lung; 
}

int ricorsivaLunghezza(Node* lista, int lung){
    Node* l = lista;
    if(l != NULL){
        lung++;
        lung = ricorsivaLunghezza(l->next, lung);
    }
    return lung;
}

int ricorsivaLunghezza2(Node* Lista){
    if (Lista->next != NULL){
        return 1 + ricorsivaLunghezza2(Lista->next);
    }
    return 1;
}

void stampaLista(Node* lista){
    Node* l = lista;
    printf("\nValori lista: ");
    while (l != NULL)
    {
        printf("%d ", l->valore);
        l = l ->next;
    }
}

void stampaListaRicorsiva(Node* lista){
    Node* l = lista;
    if(l != NULL){
        printf("%d ", l->valore);
        stampaListaRicorsiva(l->next);
    }
}

void aggiungiElementoInizio(Node** lista, int num){
    Node* head;
    head = (Node*)malloc(sizeof(Node));
    head->next = *lista;
    head->valore = num;
    *lista = head;
}

void aggiungiElementoFondo(Node** lista, int num){
    Node *l = *lista;
    while(l->next != NULL){
        l = l->next;
    }
    l->next = (Node*) malloc(sizeof(Node));
    l = l->next;
    l->valore = num;
    l->next = NULL;
}

void eliminaUltimoElemento(Node **lista){
    Node *l = *lista;
    Node *l2 = l;
    while (l->next != NULL){
        l2 = l;
        l = l->next;
    }
    l2->next = NULL;
    free(l);
}

int main(){
    int n;
    int lung = 0;
    Node* lista = NULL;
    Node* l;
    do{
        printf("inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (Node*) malloc(sizeof(Node));
                l = lista;
            } else {
                l->next = (Node*) malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n >= 0);

    l = lista;
    printf("numeri inseriti:\n");
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next;
    }
    printf("\n");
    printf("Numero di elementi: %d", calcolaLunghezza(lista));
    printf("\nNumero di elementi con ricorsiva: %d", ricorsivaLunghezza(lista, lung));
    printf("\nNumero di elementi con ricorsiva: %d", ricorsivaLunghezza2(lista));
    stampaLista(lista);
    printf("\nValori lista ricorsiva: ");
    stampaListaRicorsiva(lista);
    printf("\nInserisci un nuovo valore: ");
    scanf("%d", &n);
    aggiungiElementoFondo(&lista, n);
    stampaLista(lista);
    aggiungiElementoInizio(&lista, n);
    stampaLista(lista);
    eliminaUltimoElemento(&lista);
    stampaLista(lista);
    free(lista);
    return 0;
}