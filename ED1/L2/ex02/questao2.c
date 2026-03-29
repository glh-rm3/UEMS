/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 2
Exercício: 2
*/

#include <stdio.h>
#include <stdlib.h>

void alloc(int **arr, unsigned int tam) {
	*arr = (int*) malloc(tam*sizeof(int));
	if(*arr == NULL) return;
	
	for(size_t i = 0; i < tam; i++) {
		scanf("%d", *arr+i);
	}
}

void par_impar(int *arr, unsigned int tam) {
	int cPar = 0, cImp = 0;
	for(size_t i = 1;  i <= tam; i++) {
		if((*arr+i) % 2 != 0) {
			cImp++;
		} else {
			cPar++;
		}
	}
	printf("qtd par: %d\nqtd impar: %d: ", cPar, cImp);
}

int main() {
	int vtype, *arr;
	unsigned int tam;
	printf("tam value: ");
	vtype = scanf("%d", &tam);
	if(vtype != 1) return -1;

	alloc(&arr, tam);
	par_impar(arr, tam);
	free(arr);
	return 0;
}

