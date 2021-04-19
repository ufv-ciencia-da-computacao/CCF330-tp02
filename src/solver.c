#include "solver.h"

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

void solve(int **matrix, int lin, int col, tuple_t coord_i, tuple_t coord_f, int ***DP) {

    for (int i = 0; i < lin; i++) (*DP)[i][coord_f.x] = INT_MIN;
    for (int i = 0; i < col; i++) (*DP)[coord_f.y][i] = INT_MIN;

    for(int i=coord_f.y+1; i<=coord_i.y+1; i++) {
        for(int j=coord_f.x+1; j<=coord_i.x+1; j++) {
            if (i==coord_f.y+1 && j==coord_f.x+1) continue;
            else                                  (*DP)[i][j] = matrix[i-1][j-1] + max((*DP)[i-1][j], (*DP)[i][j-1]);   
        }
    }

}

int find_way(int **matrix, int **DP, int x, int y, tuple_t coord_f, tuple_t coord_i, int *vida, tuple_t** way, int* move_qtd) {

    if(coord_f.x == x || coord_f.y == y) return 1;
    
    (*way)[(*move_qtd)].x = x-1;
    (*way)[(*move_qtd)].y = y-1;
    (*move_qtd)++;

    if (x-1 != coord_i.x && y-1 != coord_f.y) *vida += matrix[y-1][x-1];

    if (*vida <= 0) return 0;


    if(DP[y-1][x] > DP[y][x-1]) return find_way(matrix, DP, x, y-1, coord_f, coord_i, vida, way, move_qtd);
    else                        return find_way(matrix, DP, x-1, y, coord_f, coord_i, vida, way, move_qtd);
}