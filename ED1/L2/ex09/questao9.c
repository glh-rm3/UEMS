/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 2
Exercício: 9
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define arg_name 60

typedef struct{
    int mat;
    char name[arg_name];
    int birth;
} aluno;

void clean_buffer() {
	int buf;
	while ((buf = getchar()) != '\n' && buf != EOF);
}

int get_size() {
	int sz;
	printf("Enter a size: ");
	if(scanf("%d", &sz) != 1 || sz < 1) { 
		puts("Invalid value!");
        exit(1);
    }
	return sz;
}

void alloc_aluno(int sz, aluno **arr) {
    *arr = (aluno *) malloc(sz * sizeof(aluno));
    if(*arr == NULL) {
        puts("Allocation error!");
        exit(1);
    }
}

void insert_data(int sz, aluno *arr) {
    for(size_t i = 0; i < sz; i++) {
        printf("Student %zu\tEnter mat: ", i+1);
        if(scanf("%d", &(arr+i)->mat) != 1 || (arr+i)->mat < 1) {
            printf("Invalid value!\n");
            exit(1);
        }
        clean_buffer();

        printf("Student %zu\tEnter name: ", i+1);
        fgets((arr+i)->name, arg_name, stdin);
        clean_buffer();

        printf("Student %zu\tYear of birth: ", i+1);
        if(scanf("%d", &(arr+i)->birth) != 1 || (arr+i)->birth > 2025 || (arr+i)->birth < 2025-120) {
            printf("Invalid value!\n");
            exit(1);
        }
        printf("\n");
    }
    printf("Data saved successfully!\n");
}

void print_data(int sz, aluno *arr) {
    printf("== Data report ==\n");
    for(size_t i = 0; i < sz; i++) {
        (arr+i)->name[strcspn((arr+i)->name, "\n")] = '\0';
        printf("Student[%zu]\tMat: %d\tName: %s\tBirth: %d\n", i+1, (arr+i)->mat,(arr+i)->name, (arr+i)->birth);
    }
}

int main() {
    aluno *arr;
    int sz = get_size();
    alloc_aluno(sz, &arr);
    insert_data(sz, arr);
    print_data(sz, arr);
    free(arr);
    return 0;
}
