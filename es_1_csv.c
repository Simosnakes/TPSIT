/*
author: Arrigoni Simone
date
es.
*/
#include <stdio.h>
#include <stdlib.h>

#define RIGHEMAX 100

typedef struct{
    int numero;
    char nome[50];
    char genere[35];
    int uscita;
    char disponibilita[25];

}Film;

int leggiFile(int righeMax, Film lista[]){
    FILE *fp;
    int k = 0;

    fp = fopen("./listafilm.csv", "r");

    if(fp == NULL){
        printf("Il file non esiste");
    }else{
        while(k < righeMax && fscanf(fp,"%d %s %s %d %s", &lista[k].numero, &lista[k].nome, &lista[k].genere, &lista[k].uscita, &lista[k].disponibilita)!= EOF){
            k++;
        }
    }
    fclose(fp);

    return k;
}

void stampaTutto(Film lista[], int nfilm) {
    for(int k=0; k<nfilm; k++) {
        printf("%d %s %s %d %s\n", lista[k].numero, lista[k].nome, lista[k].genere, lista[k].uscita, lista[k].disponibilita);
    }
}


int main(){
    int nFilm;
    Film lista[RIGHEMAX];

    nFilm = leggiFile(RIGHEMAX, lista);

    stampaTutto(lista, nFilm);

}
