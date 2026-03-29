/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 2
Exercício: 4
*/

#include <stdio.h>
#include <stdlib.h>

int get_size(int *n) {
	printf("Enter a n: ");
	if(scanf("%u", n) != 1 || *n < 1) return 0;
	return 1;
}

int vector_generator(int **arr, int *n) {
	*arr = (int *) malloc(*n * sizeof(int));
	if(*arr == NULL) return 0;
	return 1;
}

void read_vector(int *arr, int *n) {
	for(size_t i = 0; i < *n; i++) {
		printf("arr - pos %zu value: ", i);
		if(scanf("%d", arr+i) != 1) {
			puts("Failed to read a number!");
			exit(1);
		}
	}
}

void view_mult(int *arr, int *n) {
	int num;
	printf("Enter a x: ");
	if(scanf("%d", &num) != 1) {
		puts("Failed to read a number!");
		exit(1);
	}

	printf("Multiple Numbers: ");
	for(size_t i = 0; i < *n; i++) {
		if(*(arr+i) % num == 0) {
			printf("%d ", *(arr+i));
		}	
	}
	printf("\n");
}

int main() {
	int n, *arr;
	if(!get_size(&n)) {
		puts("Failed to read a number!");
		exit(1);
	}

	if(!vector_generator(&arr, &n)) {
		puts("Allocation error!");
		exit(1);
	} else {
		puts("Memory Successfully Allocated!");
	}
	read_vector(arr, &n);
	view_mult(arr, &n);
	free(arr);
	return 0;
}
