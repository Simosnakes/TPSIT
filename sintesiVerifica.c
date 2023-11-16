#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM 100
#define DIM_RIGA 200

typedef struct{
    int anno;
    int mese;
    int giorno;
}Data;

typedef struct{
    char* cognome;
    char* nome;
    Data nascita;
}Persona;

int contaRighe(char filename[], char riga[]){
    FILE *fp;
    int k = 0;

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("il file non esiste");
    }else{
        while(fgets(riga, DIM_RIGA, fp)){
            k++;
        }
    }

    fclose(fp);

    return k;
}

Persona scambio(Persona *a, Persona *b){
    Persona c;
    c = *a;
    *a = *b;
    *b = c;
}

void ordinaDec(Persona classe[], int nRighe){
    for(Persona *k = classe; k < classe + nRighe; k++){
        if(k->nascita.anno > (k + 1)->nascita.anno){
            scambio(k, (k + 1));
        }else{
            if(k->nascita.mese > (k + 1)->nascita.mese && k->nascita.anno == (k + 1)->nascita.anno ){
                scambio(k, (k + 1));
            }else{
                if(k->nascita.giorno > (k + 1)->nascita.giorno && k->nascita.mese == (k + 1)->nascita.mese && 
                k->nascita.anno == (k + 1)->nascita.anno){
                    scambio(k, (k + 1));
                }
            }
        }
    }
}

void stampa(Persona classe[], int nRighe){
    for(int k = 0; k < nRighe; k++){
        printf("%s %s %d %d %d\n", (classe + k)->cognome, (classe + k)->nome, (classe + k)->nascita.anno, (classe + k)->nascita.mese, (classe + k)->nascita.giorno);
    }
}

int main(){
    Persona *classe;
    FILE *fp;
    int counter = 0;
    char* campo;
    char riga[DIM_RIGA];
    char *nomeFile= "sintesiVerifica.csv";

    int righe = contaRighe(nomeFile, riga);

    classe = (Persona*)malloc(righe*sizeof(Persona));
    
    fp = fopen(nomeFile, "r");
    if(fp == NULL){
        printf("Il file non esiste");
        exit(1); //esce dal programma
    }

    while(fgets(riga, DIM_RIGA, fp)){
        campo = strtok(riga, ",");
        (classe + counter)->cognome = strdup(campo);

        campo = strtok(NULL, ",");        
        (classe + counter)->nome = strdup(campo); //(*(array_film + counter)).titolo = strdup(campo)

        campo = strtok(NULL, ",");  
        (classe + counter)->nascita.anno = atoi(campo);

        campo = strtok(NULL, ",");  
        (classe + counter)->nascita.mese = atoi(campo);
        
        campo = strtok(NULL, ",");  
        (classe + counter)->nascita.giorno = atoi(campo);

        counter ++;
    }

    ordinaDec(classe, righe);
    stampa(classe, righe);

    free(classe);

    return 0;
}