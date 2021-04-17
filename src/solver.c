#include <stdio.h>
#include <stdlib.h>
#include "solver.h"

void solve(int ***matrix, int lin, int col) {
    int matrix[lin][col+1];

    for (int i = 0; i < lin; i++) {
        matrix[i][0] = INT_MIN;
        matrix[0][i] = INT_MIN;
    }
    
}