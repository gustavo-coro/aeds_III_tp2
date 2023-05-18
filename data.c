#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char **argv) {

    usleep(1000000);

    fclose(fopen(argv[1], "w"));
    FILE *exit = fopen(argv[1], "a");
    time_t t;

    int casosTeste;



    srand((unsigned)time(&t));
    casosTeste = 1 + (rand() % 10);
    fprintf(exit, "%d\n", casosTeste);
    while (casosTeste > 0) {
        int r, c;
        r = 1 + (rand() % 15);
        c = 1 + (rand() % 15);
        fprintf(exit, "%d %d\n", r, c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                fprintf(exit, "%d ", 100 - (rand() % 200));
            }
            fprintf(exit, "\n");
        }
        casosTeste--;
    }
    fclose(exit);
    return (0);
}