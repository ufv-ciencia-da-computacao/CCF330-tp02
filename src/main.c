#include <stdio.h>
#include <stdlib.h>
#include "leitura.h"
#include "solver.h"

int main (int argc, char* argv[]) {
    FILE *file;
    int **matrix;
    int **DP;
    int lin, col, vida;
    tuple_t coord_ini, coord_final;

    read_file(&matrix, &lin, &col, &vida, &coord_ini, &coord_final, argv[1]);

    // for (int i = 0; i < lin; i++) {
    //     for (int j = 0; j < col; j++) {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    DP = (int**) malloc((lin+1)*sizeof(int*));
    for (int i = 0; i < col+1; i++) DP[i] = (int*) malloc((col+1)*sizeof(int));;

    solve(matrix, lin+1, col+1, coord_ini, coord_final, &DP);

    /*for(int i=coord_final.y+1; i<=coord_ini.y+1; i++) {
        for(int j=coord_final.x+1; j<=coord_ini.x+1; j++) {
            printf("%d ", DP[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/

    tuple_t* way = (tuple_t*) malloc ((col*lin)*sizeof(tuple_t));

    int move_qtd = 0;

    file = fopen("./data/resultado.txt", "w");
    int result = find_way(matrix, DP, coord_ini.x+1, coord_ini.y+1, coord_final, coord_ini, &vida, &way, &move_qtd);
    if (result) {
        printf("%d\n", move_qtd);
        for (int i = 0; i < move_qtd; i++) {
            fprintf(file, "%d %d\n", way[i].y, way[i].x);
        }
        
    } else {
        fprintf(file, "Impossível\n");
    }
    
    fclose(file);
    return 0;
}