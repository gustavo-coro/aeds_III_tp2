#include "main.h"

tabela* criaTabela(int linhas, int colunas) {
    tabela* tabelaTemp = (tabela*) malloc(sizeof(tabela));
    celula** celulaTemp = (celula**) malloc(sizeof(celula*) * (linhas));
    for (int i = 0; i < linhas; i++) {
        celulaTemp[i] = (celula*) malloc(sizeof(celula) * (colunas));
        for (int j = 0; j < colunas; j++) {
            celulaTemp[i][j].peso = INT_MAX;
        }
    }
    tabelaTemp->celulas = celulaTemp;
    tabelaTemp->i = linhas-1;
    tabelaTemp->j = colunas-1;
    return tabelaTemp;
}

void freeTabela(tabela* tab) {
    for (int i = 0; i <= tab->i; i++) {
        free(tab->celulas[i]);
    }
    free(tab->celulas);
    free(tab);
}

int** criaMatriz(int linhas, int colunas) {
    int** matriz = (int**) malloc(sizeof(int*) * (linhas));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(sizeof(int) * (colunas));
    }
    return matriz;
}

void freeMatriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void achaCaminhoPD(int** tabuleiro,tabela* tab) {
    //verificando o caso da matriz ser de dimensoes 1x1
    if ((tab->i == 0) && (tab->j == 0)) {
        int valorCelula = tabuleiro[0][0];
        if (valorCelula >= 0) {
            tab->celulas[0][0].peso = 1;
        } else {
            tab->celulas[0][0].peso = (valorCelula * -1) + 1;
        }
        return;
    }
    //saber quanto de energia e necessario para chegar na ultima celula
    if (tabuleiro[tab->i][tab->j] >= 0) {
        tab->celulas[tab->i][tab->j].peso = 1;
    } else {
        tab->celulas[tab->i][tab->j].peso = (tabuleiro[tab->i][tab->j] * (-1)) + 1;
    }
    //passa pela tabela comecando da ultima celula e indo ate a primeira
    for (int j = (tab->j); j >= 0; j--) {
        for (int i = (tab->i); i >= 0; i--) {
            escolheCaminho(tabuleiro, tab, i, j);
        }
    }
}

void escolheCaminho(int** tabuleiro, tabela* tab, int i, int j) {
    //verifica se a proxima posicao esta dentro dos limites
    if (i-1 >= 0) {
        //verificando se a proxima celula ja tem o peso necessario para chegar na atual
        if (tabuleiro[i-1][j] >= tab->celulas[i][j].peso) {
            tab->celulas[i-1][j].peso = 1;
        } else {
            int novoValor;
            novoValor = (tabuleiro[i-1][j] * (-1)) + tab->celulas[i][j].peso;
            //verificando qual o menor peso possivel para chegar na posicao
            if (tab->celulas[i-1][j].peso > novoValor) {
                tab->celulas[i-1][j].peso = novoValor;
            }
        }
    }
    if (j-1 >= 0) {
        if (tabuleiro[i][j-1] >= tab->celulas[i][j].peso) {
            tab->celulas[i][j-1].peso = 1;
        } else {
            int novoValor;
            novoValor = (tabuleiro[i][j-1] * (-1)) + tab->celulas[i][j].peso;
            if (tab->celulas[i][j-1].peso > novoValor) {
                tab->celulas[i][j-1].peso = novoValor;
            }
        }
    }
}