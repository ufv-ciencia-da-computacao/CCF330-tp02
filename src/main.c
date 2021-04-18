#include <stdio.h>
#include <stdlib.h>
#include "leitura.h"
#include "solver.h"

int main () {
    int **matrix;
    int lin, col;
    tuple_t coord_ini, coord_final;
    int vida;

    read_file(&matrix, &lin, &col, &vida, &coord_ini, &coord_final, "input1");

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int **DP;
    DP = (int**) malloc((lin+1)*sizeof(int*));
    for (int i = 0; i < col+1; i++) DP[i] = (int*) malloc((col+1)*sizeof(int));;

    solve(matrix, lin+1, col+1, &DP);

    for (int i = 0; i < lin+1; i++) {
        for (int j = 0; j < col+1; j++) {
            printf("%d ", DP[i][j]);
        }
        printf("\n");
    }

    return 0;
}