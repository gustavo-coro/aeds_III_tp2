#include "main.h"

tabela* criaTabela(int linhas, int colunas) {
    tabela* tabelaTemp = (tabela*) malloc(sizeof(tabela));
    //sera adicionado uma linha e uma coluna extra para facilitar os calculos
    celula** celulaTemp = (celula**) malloc(sizeof(celula*) * (linhas+1));
    for (int i = 0; i <= linhas; i++) {
        celulaTemp[i] = (celula*) malloc(sizeof(celula) * (colunas+1));
    }
    //iniciando os valores das bordas como -infinito para nao atrapalhar os calculos
    for (int i = 0; i <= linhas; i++) {
        celulaTemp[i][colunas].peso = INT_MIN;
        celulaTemp[i][colunas].pesoMinCaminho = INT_MIN;
    }
    for (int j = 0; j <= colunas; j++) {
        celulaTemp[linhas][j].peso = INT_MIN;
        celulaTemp[linhas][j].pesoMinCaminho = INT_MIN;
    }
    tabelaTemp->celulas = celulaTemp;
    tabelaTemp->i = linhas;
    tabelaTemp->j = colunas;
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

void achaCaminhoDP(int** tabuleiro,tabela* tab) {
    //passa pela tabela comecando da ultima celula e indo ate a primeira
    for (int j = ((tab->j)-1); j >= 0; j--) {
        for (int i = ((tab->i)-1); i >= 0; i--) {
            escolheCaminho(tab, i, j);
            int iProx = tab->celulas[i][j].posicaoProx[0];
            int jProx = tab->celulas[i][j].posicaoProx[1];
            if ((i == (tab->i)-1) && (j == (tab->j)-1)) {
                tab->celulas[i][j].peso = tabuleiro[i][j];
            } else {
                tab->celulas[i][j].peso = tab->celulas[iProx][jProx].peso + tabuleiro[i][j];
            }
            if (tab->celulas[i][j].peso <= tab->celulas[iProx][jProx].pesoMinCaminho) {
                tab->celulas[i][j].pesoMinCaminho = tab->celulas[i][j].peso;
            } else {
                tab->celulas[i][j].pesoMinCaminho = tab->celulas[iProx][jProx].pesoMinCaminho;
            }
        }
    }
}

void escolheCaminho(tabela* tab, int i, int j) {
    //escolhe o proximo passo com base no menor do caminho ate agora
    //em caso de empate, escolhe o maior local
    if (tab->celulas[i+1][j].pesoMinCaminho == tab->celulas[i][j+1].pesoMinCaminho) {
        if (tab->celulas[i+1][j].peso >= tab->celulas[i][j+1].peso) {
            tab->celulas[i][j].posicaoProx[0] = i+1;
            tab->celulas[i][j].posicaoProx[1] = j;
        } else {
            tab->celulas[i][j].posicaoProx[0] = i;
            tab->celulas[i][j].posicaoProx[1] = j+1;
        }
    } else {
        if (tab->celulas[i+1][j].pesoMinCaminho >= tab->celulas[i][j+1].pesoMinCaminho) {
            tab->celulas[i][j].posicaoProx[0] = i+1;
            tab->celulas[i][j].posicaoProx[1] = j;
        } else {
            tab->celulas[i][j].posicaoProx[0] = i;
            tab->celulas[i][j].posicaoProx[1] = j+1;
        }
    }
}