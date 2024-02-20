#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct paziente {
    char* nome;
    char* colore;
    int eta;
    
    struct paziente *next;
} Paziente;

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
    while (l != NULL){
        /*if(strcmp(l->colore, "bianco") == 0){
            printf("Coda codice bianco \n");
        }else{
            if(strcmp(l->colore, "verde") == 0){
                printf("Coda codice verde \n");
            }else{
                if(strcmp(l->colore, "giallo") == 0){
                    printf("Coda codice giallo \n");
                }else{
                    if(strcmp(l->colore, "rosso") == 0){
                        printf("Coda codice rosso \n");
                    }   
                }
            }
        }*/

        printf("%s ", l->nome);
        printf("%d ", l->eta);
        printf("%s\n", l->colore);
        l = l ->next;
    }
}

int calcolaLunghezza(Paziente* head){
    Paziente* h = head;
    int lung = 0;
    while (h != NULL)
    {
        lung++;
        h = h->next;
    }
    return lung; 
}

void freeCodaRicors(Paziente* head){
    if(head->next != NULL){
        freeCodaRicors(head->next);
    }
    free(head);
}

int main(){
    Paziente* headBianco = NULL;
    Paziente* tailBianco = NULL;

    Paziente* headVerde = NULL;
    Paziente* tailVerde = NULL;

    Paziente* headGiallo = NULL;
    Paziente* tailGiallo = NULL;

    Paziente* headRosso = NULL;
    Paziente* tailRosso = NULL;

    int risp;

    do{
        Paziente* paziente = (Paziente*)malloc(sizeof(Paziente));

        printf("Inserisci il nome del paziente: ");
        fflush(stdin);
        scanf("%s", paziente->nome);

        printf("%s", paziente->nome);

        printf("Inserisci l'eta: ");
        scanf("%d", &paziente->eta);

        printf("Inserisci il codice: ");
        fflush(stdin);
        scanf("%s", paziente->colore);

        if(strcmp(paziente->colore, "bianco") == 0){
            enqueue(&headBianco, &tailBianco,paziente);
        }
        if(strcmp(paziente->colore, "verde") == 0){
            enqueue(&headVerde, &tailVerde, paziente);
        }
        if(strcmp(paziente->colore, "giallo") == 0){
            enqueue(&headGiallo, &tailGiallo, paziente);
        }
        if(strcmp(paziente->colore, "rosso") == 0){
            enqueue(&headRosso, &tailRosso, paziente);
        }   

        printf("\nVuoi inserire atri pazienti?\n");
        //fflush(stdin);
        scanf("%d", &risp);

        printf("\n%d\n", risp);

    }while(risp != 1); /* strcmp(risp, "si") == 0*/

    printf("\nciao\n");


    stampaCoda(headBianco);
    stampaCoda(headGiallo);
    stampaCoda(headVerde);
    stampaCoda(headRosso);

    int lungBianco = calcolaLunghezza(headBianco);
    int lungVerde = calcolaLunghezza(headVerde);
    int lungGiallo = calcolaLunghezza(headGiallo);
    int lungRosso = calcolaLunghezza(headRosso);

    printf("Persone in coda codice bianco: %d\n", lungBianco);
    printf("Persone in coda codice verde: %d\n", lungVerde);
    printf("Persone in coda codice giallo: %d\n", lungGiallo);
    printf("Persone in coda codice rosso: %d\n", lungRosso);

    return 0;
}

