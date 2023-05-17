#ifndef GRIDFB_H
#define GRIDFB_H
//estrategia usando forca bruta (FB)
#include "main.h"

typedef struct celulaFB {
    int peso;
    int pesoMinCaminho;
} celulaFB;

typedef struct tabelaFB {
    int i; //linhas
    int j; //colunas
    celulaFB** celulas;
    int energiaMinima;
} tabelaFB;

tabelaFB* criaTabelaFB(int, int);
void calculaMinimoFB(tabelaFB*, int, int, int, int); //calcula o melhor caminho usando forca bruta
void freeTabelaFB(tabelaFB*);



#endif