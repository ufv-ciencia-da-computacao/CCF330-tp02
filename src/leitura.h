#ifndef LEITURA_H
#define LEITURA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} tuple_t;

int read_file(int ***matrix, int *lin, int *col, int *vida, tuple_t *coord_ini, tuple_t *coord_final, char *name);

#endif