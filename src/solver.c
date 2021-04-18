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

void find_way(int **DP, int x, int y, tuple_t coord_f, FILE *file) {

    fprintf(file, "%d %d\n", y-1, x-1);

    if(coord_f.x+1 == x || coord_f.y+1 == y) return;

    if(DP[y-1][x] > DP[y][x-1]) find_way(DP, x, y-1, coord_f, file);
    else                        find_way(DP, x-1, y, coord_f, file);
}