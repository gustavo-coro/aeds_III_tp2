#include "main.h"

tabelaFB* criaTabelaFB(int linhas, int colunas) {
    tabelaFB* tabelaFBTemp = (tabelaFB*) malloc(sizeof(tabelaFB));
    celulaFB** celulaFBTemp = (celulaFB**) malloc(sizeof(celulaFB*) * (linhas));
    for (int i = 0; i < linhas; i++) {
        celulaFBTemp[i] = (celulaFB*) malloc(sizeof(celulaFB) * (colunas));
    }
    tabelaFBTemp->celulas = celulaFBTemp;
    tabelaFBTemp->i = linhas-1;
    tabelaFBTemp->j = colunas-1;
    tabelaFBTemp->energiaMinima = INT_MIN;
    tabelaFBTemp->celulas[linhas-1][colunas-1].pesoMinCaminho = INT_MIN;
    return tabelaFBTemp;
}

void freeTabelaFB(tabelaFB* tab) {
    for (int i = 0; i <= tab->i; i++) {
        free(tab->celulas[i]);
    }
    free(tab->celulas);
    free(tab);
}

void calculaMinimoFB(tabelaFB* tab, int iInicio, int jInicio, int soma, int min) {
    if ((iInicio == tab->i) && (jInicio == tab->j)) {
        int somaAux = tab->celulas[iInicio][jInicio].peso + soma;
        if (somaAux < min) {
            min = somaAux;
        }
        if (tab->energiaMinima < min) {
            tab->energiaMinima = min;
        }
        return;
    }
    if ((iInicio+1 <= tab->i)) {
        int somaAux = tab->celulas[iInicio][jInicio].peso + soma;
        if (somaAux < min) {
            min = somaAux;
        }
        calculaMinimoFB(tab, iInicio+1, jInicio, somaAux, min);
        
    }
    if ((jInicio+1 <= tab->j)) {
        int somaAux = tab->celulas[iInicio][jInicio].peso + soma;
        if (somaAux < min) {
            min = somaAux;
        }
        calculaMinimoFB(tab, iInicio, jInicio+1, somaAux, min);
    }
}