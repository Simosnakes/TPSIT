/*
author: Simone Arrigoni
date: 13/11/2023
es. lista 
testo creazione di una lista
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct el {
    int valore;
    struct el *next;

} Elemento;

int sommaElementi(Elemento* lista, int m){
    if(lista == NULL){
        return -1;
    }

    Elemento* l = lista;
    int somma = 0;

    while(l != NULL){
        if(l->valore % m == 0){
            somma += l->valore;
        }
        l = l->next;
    }

    return somma;
}

int main(){
    int n;
    Elemento* l;
    Elemento* lista = NULL;

    do{
        printf("Inserisci un elemento (-1 per terminare): ");
        scanf("%d", &n);
        if(n>=0){
            if(lista == NULL){
                lista = (Elemento*)malloc(sizeof(Elemento));
                l = lista;
            }else{
                l->next = (Elemento*)malloc(sizeof(Elemento));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    }while(n>=0);

    int m;
    printf("inserisci l'elemento: ");
    scanf("%d", &m);

    printf("La somma degli elementi multipli e': %d", sommaElementi(lista, m));
    free(lista);
    free(head);
}