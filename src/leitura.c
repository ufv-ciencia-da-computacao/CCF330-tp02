#include "leitura.h"

int read_file(int ***matrix, int *lin, int *col, int *vida, tuple_t *coord_ini, tuple_t *coord_final, char *name) {
    FILE *file;
    char path[100];
    char character[20];
    strcpy(path, "./data/");
    strcat(path, name);
    strcat(path, ".txt");

    file = fopen(path, "r");

    if (file == NULL) {
        perror("\nArquivo nao pode ser lido!");
        fclose(file);
        return 0;
    }

    while (!feof(file)) {
        fscanf(file, "%d %d %d", lin, col, vida);
        
        (*matrix) = (int**) malloc(*lin*sizeof(int*));
        for (int i = 0; i < *col; i++) (*matrix)[i] = (int*) malloc(*col*sizeof(int));

        for (int i = 0; i < *lin; i++) {
            for (int j = 0; j < *col; j++) {
                fscanf(file, "%s", character);
                if (character[0] == 'F') {
                    (*coord_final).y = i;
                    (*coord_final).x = j;
                    (*matrix)[i][j] = 0;
                } else if (character[0] == 'I') {
                    (*coord_ini).y = i;
                    (*coord_ini).x = j;
                    (*matrix)[i][j] = *vida;
                } else {
                    (*matrix)[i][j] = atoi(character);
                }                
            }
        }
    }

    fclose(file);
    return 1;
}
