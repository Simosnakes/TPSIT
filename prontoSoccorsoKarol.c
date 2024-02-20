#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct paziente{
    char* colore;
    char* nome;
    int eta;
    
    struct paziente* next;
}Paziente;

bool is_empty(Paziente* head){
    return head == NULL;
}

void enqueue(Paziente** head, Paziente** tail, Paziente* elem){
    if(is_empty(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Paziente* dequeue(Paziente** head, Paziente** tail){
    Paziente* ret = *head;
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

void stampaCoda(Paziente* head){
    Paziente* l = head;
    while (l != NULL)
    {
        printf("\n%s ", l->nome);
        printf("\n%d ", l->eta);
        printf("\n%s\n ", l->colore);
        l = l ->next;
    }
}

int main(){
    Paziente* headBianca = NULL;
    Paziente* tailBianca = NULL;
    Paziente* headVerde = NULL;
    Paziente* tailVerde = NULL;
    Paziente* headGiallo = NULL;
    Paziente* tailGiallo = NULL;
    Paziente* headRosso = NULL;
    Paziente* tailRosso = NULL;
    char* risp = (char*)malloc(sizeof(char));

    do{
        Paziente* p = (Paziente*)malloc(sizeof(Paziente));

        printf("inserisci il nome del paziente: ");
        fflush(stdin);
        scanf("%s", p->nome);
        printf("inserisci l'eta del paziente: ");
        fflush(stdin);
        scanf("%d", &p->eta);
        printf("inserisci il colore del paziente: ");
        fflush(stdin);
        scanf("%s", p->colore);
        
        if(strcmp("rosso", p->colore) == 0){
            enqueue(&headRosso, &tailRosso, p);
        }
        if(strcmp("verde", p->colore) == 0){
            enqueue(&headVerde, &tailVerde, p);
        }
        if(strcmp("bianco", p->colore) == 0){
            enqueue(&headBianca, &tailBianca, p);
        }
        if(strcmp("giallo", p->colore) == 0){
            enqueue(&headGiallo, &tailGiallo, p);
        }

        printf("ci sono altri pazienti?: ");
        fflush(stdin);
        scanf("%s", risp);
    }while(strcmp(risp, "si") == 0);

    stampaCoda(headVerde);

    return 0;
}