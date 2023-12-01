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

Elemento* firstEven(Elemento* lista){
    Elemento* l = lista;

    while(l != NULL){
        if(l->valore % 2 == 0){
            return l;
        }else{
           l = l->next;
        } 
    }
    return NULL;
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

    Elemento* elemento = firstEven(lista);

    printf("La posizione del primo elemento paria e': %d", *elemento);
    //printf("\nLa posizione del primo elemento paria e': %d", elemento->valore);


    return 0;
}