#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int *vet;
    int dim;

    do {
        printf("Inserisci la dimensione del vettore:  ");
        scanf("%d", &dim);
    }while(dim < 0 || dim > 100);

    vet = (int*)malloc(dim*sizeof(int));

    int *k;
    for(k = vet; k < vet + dim; k++){
        printf("Inserisci il numero: ");
        scanf("%d", k);
    }

    int *j;
    for(j = vet; j < vet + dim; j++){
        printf("%d ", *j);
    }

    free(vet);
}