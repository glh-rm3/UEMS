/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 2
Exercício: 11
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int **data;
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
    m->data = (int **) malloc(m->rows * sizeof(int *));
    if (m->data == NULL) {
        puts("Allocation error!");
        exit(1);
    }
    for (int i = 0; i < m->rows; i++) {
        m->data[i] = (int *) malloc(m->cols * sizeof(int));
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
            if (scanf("%d", &m->data[i][j]) != 1) {
                puts("Invalid value!");
                exit(1);
            }
        }
    }
    printf("Data saved successfully!\n\n");
}

void print_matrix(Matrix *m) {
    printf("== Matrix report ==\n");
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%4d", m->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int search_value(Matrix *m, int val) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            if (m->data[i][j] == val)
                return 1;
        }
    }
    return 0;
}

void free_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++)
        free(m->data[i]);
    free(m->data);
}

int main() {
    Matrix m;
    int val;

    m.rows = get_dimension("rows");
    m.cols = get_dimension("cols");
    alloc_matrix(&m);
    insert_data(&m);
    print_matrix(&m);

    printf("Enter a value to search: ");
    if (scanf("%d", &val) != 1) {
        puts("Invalid value!");
        exit(1);
    }

    int result = search_value(&m, val);
    printf("Value %d %s in the matrix.\n", val, result ? "found" : "not found");

    free_matrix(&m);
    return 0;
}
