#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct film{
    char* titolo;
    char* genere;
    int anno;
    struct film* next;
}Film;


bool is_empty(Film* head){
    return head == NULL;
}

void enqueue(Film** head, Film** tail, Film* elem){
    if(is_empty(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Film* dequeue(Film** head, Film** tail){
    Film* ret = *head;
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

void stampaCoda(Film* head){
    Film* l = head;
    while (l != NULL)
    {
        printf("\n%s ", l->titolo);
        printf("\n%s ", l->genere);
        printf("\n%d\n ", l->anno);
        l = l ->next;
    }
}

int main(){
    Film* head = (Film*)malloc(sizeof(Film));
    Film* tail = (Film*)malloc(sizeof(Film));

    head = NULL;
    tail = NULL;
    char* titolo;
    char* genere;
    int anno;

    Film* elemento = (Film*)malloc(sizeof(Film));

    printf("Inserisci il titolo del film: ");
    gets(titolo);
    printf("Inserisci il genere del film: ");
    gets(genere);
    printf("Inserisci l'anno del film: ");
    scanf("%d", &anno);

    elemento->titolo = titolo;
    elemento->genere = genere;
    elemento->anno = anno;

    enqueue(&head, &tail, elemento);

    Film* elemento2 = (Film*)malloc(sizeof(Film));

    printf("Inserisci il titolo del film: ");
    gets(titolo);
    printf("Inserisci il genere del film: ");
    gets(genere);
    printf("Inserisci l'anno del film: ");
    scanf("%d", &anno);

    elemento2->titolo = titolo;
    elemento2->genere = genere;
    elemento2->anno = anno;

    enqueue(&head, &tail, elemento2);

    stampaCoda(head);

    Film* temp = dequeue(&head, &tail);
    printf("\n%s", temp->titolo);

}