/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 2
Exercício: 1 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int *arr = (int* ) malloc(5*sizeof(int));
	if(arr == NULL) return -1;
	for(size_t i = 0; i < 5; i++) {
		printf("arr pos - %zu : ", i);
		scanf("%d", (arr +(int)i));
	}
	printf("\n");
	for(size_t j = 0; j < 5; j++) {
		printf("arr %zu\tValue: %d\n", j, *(arr+j));
	}

	free(arr);
	return 0;
}
