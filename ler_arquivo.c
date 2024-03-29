#include <getopt.h>

#include "main.h"

// ***************************************************
// FUNCAO readLine RETIRADA DE:
// https://www.ime.usp.br/~pf/algoritmos/aulas/io2.html
// ***************************************************
// A função readLine lê uma linha (a partir da posição 
// corrente) do arquivo de texto infile e devolve uma
// string com o mesmo conteúdo da linha. O char \n que
// sinaliza o fim da linha não é armazenado como parte
// da string. A função devolve NULL se a posição
// corrente do arquivo estiver no fim do arquivo. Uso
// típico da função: 
//             s = readLine (infile);
// (Esta função é uma adaptação da função ReadLine da
// biblioteca simpio de Eric Roberts.)

char *readLine (FILE *infile) {
   int n = 0, size = 128, ch;
   char *line;
   line = malloc (size + 1);
   while ((ch = getc (infile)) != '\n' && ch != EOF) {
      if (n == size) {
         size *= 2;
         line = realloc (line, size + 1);
      }
      line[n++] = ch;
   }
   if (n == 0 && ch == EOF) {
      free (line);
      return NULL;
   }
   line[n] = '\0';
   line = realloc (line, n + 1);
   return line;
}

int openFile (int argc, char **argv, FILE **in, char *solution, FILE **out) {
    
    if (argc < 3) {
        perror("Faltam parametros para executar corretamente.\n");
        return -1;
    } else if (argc > 3) {
        perror("Parametros demais.\n");
        return -1;
    }

    *solution = *argv[1];
    *in = fopen(argv[2], "r");
    *out = fopen("saida.txt", "w+");

    return 1; //retorna em caso de sucesso
}

//resolucao com programacao dinamica
void readFilePD (FILE* inFile, FILE* outFile) {
    char *line = NULL;
    int casosTeste;
    //ler a primeira linha com o numero de casos de teste
    if ((line = readLine(inFile)) != NULL) {
        sscanf(line, "%d", &casosTeste);
    }
    for (int contLine = 0; contLine < casosTeste; contLine++) {
        int linhas, colunas;
        //ler o numero de linhas e colunas
        if ((line = readLine(inFile)) != NULL) {
            sscanf(line, "%d %d", &linhas, &colunas);
        }
        //matriz que adiciona os valores do grid
        int** matriz = criaMatriz(linhas, colunas);
        //tabela usada para guardar os calculos dos subproblemas
        tabela* tab = criaTabela(linhas, colunas);
        //lendo os valores do grid
        for (int i = 0; i < linhas; i++) {
            if ((line = readLine(inFile)) != NULL) {
                int num;
                int j = 0;
                char *proxNum = strtok(line, " ");
                while(proxNum != NULL) {
                    sscanf(proxNum, "%d", &num);
                    matriz[i][j] = num;
                    j++;
                    proxNum = strtok(NULL, " ");
                }
            }
        }
        //calculando o caminho que ele deve utilizar
        achaCaminhoPD(matriz, tab);
        fprintf(outFile, "%d\n", tab->celulas[0][0].peso);
        //libera o espaco alocado para a matriz e a tabela
        freeMatriz(matriz, linhas);
        freeTabela(tab);
    }
    free(line);
}

void readFileFB (FILE* inFile, FILE* outFile) {
    char *line = NULL;
    int casosTeste;
    //ler a primeira linha com o numero de casos de teste
    if ((line = readLine(inFile)) != NULL) {
        sscanf(line, "%d", &casosTeste);
    }
    for (int contLine = 0; contLine < casosTeste; contLine++) {
        int linhas, colunas;
        //ler o numero de linhas e colunas
        if ((line = readLine(inFile)) != NULL) {
            sscanf(line, "%d %d", &linhas, &colunas);
        }
        //tabela usada para guardar o grid
        tabelaFB* tab = criaTabelaFB(linhas, colunas);
        //lendo os valores do grid
        for (int i = 0; i < linhas; i++) {
            if ((line = readLine(inFile)) != NULL) {
                int num;
                int j = 0;
                char *proxNum = strtok(line, " ");
                while(proxNum != NULL) {
                    sscanf(proxNum, "%d", &num);
                    tab->celulas[i][j].peso = num;
                    j++;
                    proxNum = strtok(NULL, " ");
                }
            }
        }
        //calculando a energia que ele vai gastar
        int resultado = 0;
        int min = INT_MAX;
        calculaMinimoFB(tab, 0, 0, resultado, min);
        resultado = tab->energiaMinima;
        //verificando se mesmo com vida zero ele nao ficaria negativo
        //nesse caso ele deve comecar com 1
        if (resultado > 0) {
            fprintf(outFile, "%d\n", 1);
        } else {
            fprintf(outFile, "%d\n", (resultado * (-1)) + 1);
        }
        //libera o espaco alocado para a tabela
        freeTabelaFB(tab);
    }
    free(line);
}