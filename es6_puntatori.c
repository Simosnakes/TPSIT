#include <stdio.h>
#include <stdlib.h>
#define DIM 10
void scambio(int *a, int *b){
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

void selectionSort(int vet[], int n) {
    for(int *k = vet; k < vet + n -  1; k++) {
        int *kmin = k;
        for(int *j = (k + 1); j < vet + n; j++){
            if(*kmin > *j) // confronti
                kmin = j;
        }
        if(*kmin != *k)
            scambio(k, kmin); //scambi
        }
    return;
}

void stampa(int vet[], int n){
    for(int *k = vet; k < vet + n; k++){
        printf("%d ", *k);
    }
}

int main(){
    int vet[DIM] = {7, 5, 3, 8, 3, 10, 1, 4, 9, 6};
    selectionSort(vet, DIM);
    stampa(vet, DIM);

    return 0;
}