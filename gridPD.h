#ifndef GRIDPD_H
#define GRIDPD_H

#include "main.h"

typedef struct celula {
    int peso;
} celula;

typedef struct tabela {
    int i; //linhas
    int j; //colunas
    celula** celulas;
} tabela;



tabela* criaTabela(int, int);
int** criaMatriz(int, int);
void achaCaminhoPD(int**, tabela*); //calcula o melhor caminho usando programacao dinamica
void escolheCaminho(int**, tabela*, int, int);
void freeTabela(tabela*);
void freeMatriz(int**, int);

#endif