#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct container {
    int codice;
    float peso;
    float tara;
    struct container *next;
} Container;

int is_empty(Container* head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Container** head, Container* elemento){
    
    if(is_empty(*head)){
        *head = elemento;
        elemento->next = NULL;
    }else{
        elemento->next = *head;
        *head = elemento;
    }
}

Container* pop(Container** head){
    Container* ret = *head;

    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
        return ret;
    }
}

void stampaPila(Container* lista){
    Container* l = lista;
    
    while (l != NULL){
        printf("\nValori container: ");
        printf("%d ", l->codice);
        printf("%.2f ", l->peso);
        printf("%.2f \n", l->tara);
        l = l ->next;
    }
}

int main(){
    Container* head = NULL;
    char* risp;

    do{
        Container* elemento = (Container*)malloc(sizeof(Container));
        printf("Inserisci codice del container: ");
        scanf("%d", &elemento->codice);
        printf("Inserisci il peso del container: ");
        scanf("%f", &elemento->peso);
        printf("Inserisci la tara del container: ");
        scanf("%f", &elemento->tara);
        
        push(&head, elemento);

        printf("Vuoi inserire atri container?");
        fflush(stdin);
        scanf("%s", risp);

    }while(strcmp(risp, "si") == 0);

    stampaPila(head);
}

