#include <stdio.h>
#include <stdlib.h>
#include "solver.h"

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

void solve(int **matrix, int lin, int col, int ***DP) {
    for (int i = 0; i < lin; i++) {
        (*DP)[i][0] = INT_MIN;
    }

    for (int i = 0; i < col; i++) {
        (*DP)[0][i] = INT_MIN;
    } 

    for (int i = 1; i < lin; i++) {
        for (int j = 1; j < col; j++) {
            if (i==1 && j==1) {
                (*DP)[i][j] = 0;
            } else {
                (*DP)[i][j] = matrix[i-1][j-1] + max((*DP)[i-1][j], (*DP)[i][j-1]);
            }
        }
    }
}