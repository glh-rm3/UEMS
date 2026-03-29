/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 2
Exercício: 6
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int *arr = (int *) calloc(1500, sizeof(int));
	for(size_t i = 0; i < 1500; i++) {
		printf("Pos - %zu\tValue: %d\n", i, *(arr+i));
	}
	for(size_t i = 0; i < 1500; i++) {
		*(arr+i) = i;
		if(*(arr+i) < 10 || *(arr+i) > 1490) {
			printf("Pos - %zu\tValue: %d\n", i, *(arr+i));
		}
	}
	free(arr);
	return 0;
}
