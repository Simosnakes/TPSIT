/*
author: Arrigoni Simone
date
es.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM_RIGA 200
#define NUM_RIGHE 20000

typedef struct{

    int numero;
    char* titolo;
    char* genere;
    int anno;
    char* disponibilita;

}Film;


void trovaFilm(Film array_film[], int counter, int anno){
    for(int k = 0; k < counter; k++){
        if(array_film[k].anno == anno){
            printf("%s\n", array_film[k].titolo);
        }
    }  
}

void stampaTutto(Film array_film[], int counter){
    for(int k=0; k < counter; k++){
        printf("%d %s %s %d %s\n", array_film[k].numero, array_film[k].titolo, array_film[k].genere, array_film[k].anno, array_film[k].disponibilita);
    }
}


int main(){
    char filename[] = "./listafilm.csv";
    char riga[DIM_RIGA];
    FILE *fp;
    char* campo;
    Film array_film[NUM_RIGHE];
    int counter = 0, anno;

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Il file non esiste");
        exit(1); //esce dal programma
    }

    while(fgets(riga, DIM_RIGA, fp)){
        campo = strtok(riga, ",");//dentro campo trovo il primo campo della rica e il campo separatore che � la virgola
        array_film[counter].numero = atoi(campo);//converte in itero per conventire in float si usa atof()

        campo = strtok(NULL, ",");
        array_film[counter].titolo = strdup(campo);

        campo = strtok(NULL, ",");
        array_film[counter].genere = strdup(campo);

        campo = strtok(NULL, ",");
        array_film[counter].anno = atoi(campo);

        campo = strtok(NULL, ",");
        array_film[counter].disponibilita = strdup(campo);

        counter ++;
    }

    printf("Inserisci l'anno di un film: ");
    do{
        scanf("%d", &anno);
    }while(anno > 2023 || anno < 0);


    trovaFilm(array_film, counter, anno); 

    //stampaTutto(array_film, counter);
    return 0;
}
