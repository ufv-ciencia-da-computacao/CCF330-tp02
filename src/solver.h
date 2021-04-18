#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "leitura.h"

void solve(int **matrix, int lin, int col, tuple_t coord_i, tuple_t coord_f, int ***DP);

void find_way(int **DP, int x, int y, tuple_t coord_i, FILE *file);

#endif