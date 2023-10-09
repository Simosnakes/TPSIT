#include <stdio.h>
#include <stdlib.h>
#define DIM 10

int sommaVett(int vet[], int dim){
    int somma = 0;
    for(int k = 0; k < dim; k++){
        somma += *(vet + k); //somma += vet[k];
    }

    return somma;
}

int main(){
    int vet[DIM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sommaVet = 0;
    sommaVet = sommaVett(vet, DIM);

    printf("%d", sommaVet);

    return 0;
}