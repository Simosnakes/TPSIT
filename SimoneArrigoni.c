#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct coda{
    int arrivo;
    int valore;
    struct coda* next;
}Coda;

typedef struct pila {
    int arrivo;
    int valore;
    struct pila *next;

} Pila;

int is_empty(Pila* head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Pila** head, Pila* elemento){
    
    if(is_empty(*head)){
        *head = elemento;
        elemento->next = NULL;
    }else{
        elemento->next = *head;
        *head = elemento;
    }
}

Pila* pop(Pila** head){
    Pila* ret = *head;

    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
        return ret;
    }
}


bool is_emptyCoda(Coda* head){
    return head == NULL;
}

void enqueue(Coda** head, Coda** tail, Coda* elem){
    if(is_emptyCoda(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Coda* dequeue(Coda** head, Coda** tail){
    Coda* ret = *head;
    if(is_emptyCoda(*head)){
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

void stampaPila(Pila* lista){
    Pila* l = lista;
    printf("\nValori pila:\n");
    while (l != NULL)
    {
        printf("Posizione: %d ", l->arrivo);
        printf("Valore: %d \n", l->valore);
        l = l ->next;
    }
}

void stampaCoda(Coda* head){
    Coda* l = head;
    printf("\nValori coda:\n");
    while (l != NULL)
    {
        printf("Posizione: %d ", l->arrivo);
        printf("Valore: %d \n", l->valore);
        l = l ->next;
    }
}

int main(){
    Coda* headCoda = NULL;
    Coda* tail = NULL;

    Pila* headPila = NULL;

    srand(time(NULL));

    for(int k = 0; k < 5; k++){
        Pila* elemento = (Pila*)malloc(sizeof(Pila));

        elemento->arrivo = k;
        //inserire valore casuale
        elemento->valore = rand() % 10 + 1;

        push(&headPila, elemento);
    }

    for(int k = 0; k < 5; k++){
        Coda* elemento = (Coda*)malloc(sizeof(Coda));
        elemento->arrivo = k;
        //inserire valore casuale
        elemento->valore = rand() % 10 + 1;

        enqueue(&headCoda, &tail, elemento);
    }

    stampaCoda(headCoda);
    stampaPila(headPila);

    Pila* scorriPila = headPila;
    Coda* scorriCoda = headCoda;
    Coda* scorriTail = tail;

    while(scorriPila != NULL && scorriCoda != NULL){
        Pila* remuved = pop(&scorriPila);
        Coda* temp = dequeue(&scorriCoda, &scorriTail);

        printf("Pila Valore %d, Arrivo: %d\n", remuved->valore, remuved->arrivo);
        printf("Coda Valore %d, Arrivo: %d\n", temp->valore, temp->arrivo);

        if(remuved->valore < temp->valore){
            printf("vincitore CODA\n");
            enqueue(&scorriCoda, &scorriTail, temp);
            free(remuved);
        }else{
            printf("vincitore PILA\n");
            push(&scorriPila, remuved);
            free(temp);
        }

        //scorriPila = scorriPila->next;
        //scorriCoda = scorriCoda->next;
    }

    if(scorriPila == NULL){
        printf("ha vinto la coda\n");
    }else{
        printf("ha vinto la pila\n");
    }

}