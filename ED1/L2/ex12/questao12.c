/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 2
Exercício: 12
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    float **data;
} Matrix;

void clean_buffer() {
    int buf;
    while ((buf = getchar()) != '\n' && buf != EOF);
}

int get_dimension(const char *label) {
    int dim;
    printf("Enter number of %s: ", label);
    if (scanf("%d", &dim) != 1 || dim < 1) {
        puts("Invalid value!");
        exit(1);
    }
    return dim;
}

void alloc_matrix(Matrix *m) {
    m->data = (float **) malloc(m->rows * sizeof(float *));
    if (m->data == NULL) {
        puts("Allocation error!");
        exit(1);
    }
    for (int i = 0; i < m->rows; i++) {
        m->data[i] = (float *) malloc(m->cols * sizeof(float));
        if (m->data[i] == NULL) {
            puts("Allocation error!");
            exit(1);
        }
    }
}

void insert_data(Matrix *m) {
    printf("Enter matrix values:\n");
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("[%d][%d]: ", i, j);
            if (scanf("%f", &m->data[i][j]) != 1) {
                puts("Invalid value!");
                exit(1);
            }
        }
    }
    printf("Data saved successfully!\n\n");
}

void print_matrix(Matrix *m) {
    printf("== Matrix report ==\n");
    printf("+");
    for (int j = 0; j < m->cols; j++)
        printf("-----------+");
    printf("\n");

    for (int i = 0; i < m->rows; i++) {
        printf("|");
        for (int j = 0; j < m->cols; j++)
            printf(" %9.2f |", m->data[i][j]);
        printf("\n+");
        for (int j = 0; j < m->cols; j++)
            printf("-----------+");
        printf("\n");
    }
}

void free_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++)
        free(m->data[i]);
    free(m->data);
}

int main() {
    Matrix m;

    m.rows = get_dimension("rows");
    m.cols = get_dimension("cols");
    alloc_matrix(&m);
    insert_data(&m);
    print_matrix(&m);
    free_matrix(&m);

    return 0;
}
