#include <stdio.h>
#include <stdlib.h>
#define DIM 10

void scambio(int *a, int *b){
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

void bubbleSort3(int vet[], int n) {
    int k,sup,sca;
    sup= n-1 ;
    while ( sup>0 ) {
        sca=0 ;
        for (k = 0; k < sup ; k++) {
            if (*(vet + k) > *(vet + k+ 1)){
                scambio((vet + k), (vet + k + 1));
                sca=k ;
            }
        }
        sup=sca ;
    }
}

void stampa(int vet[], int n){
    for(int k = 0; k < n; k++){
        printf("%d ", *(vet + k));
    }
}

int main(){
    int vet[DIM] = {7, 5, 3, 8, 3, 10, 1, 4, 9, 6};
    bubbleSort3(vet, DIM);
    stampa(vet, DIM);

    return 0;
}