#ifndef LER_ARQUIVO_H
#define LER_ARQUIVO_H

#include "main.h"

char *readLine (FILE*);
int openFile (int, char**, FILE**, char*, FILE**);
void readFileDP (FILE*, FILE*);

#endif