#ifndef GRID_H
#define GRID_H

#include "main.h"

typedef struct celula {
    //Variavel que indica a posicao da celula seguinte no caminho
    int posicaoProx[2]; //0 e a linha 1 a coluna
    int peso;
    int pesoMinCaminho;
} celula;

typedef struct tabela {
    int i; //linhas
    int j; //colunas
    celula** celulas;
} tabela;



tabela* criaTabela(int, int);
int** criaMatriz(int, int);
void achaCaminhoDP(int**,tabela*); //calcula o melhor caminho usando programacao dinamica
void escolheCaminho(tabela*, int, int);
void freeTabela(tabela*);
void freeMatriz(int**, int);

#endif