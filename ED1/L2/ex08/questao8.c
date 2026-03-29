/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 2
Exercício: 8
*/

#include <stdio.h>
#include <stdlib.h>

int get_size() {
	int sz;
	printf("Enter a size: ");
	if(scanf("%d", &sz) != 1 || sz < 10) { //isso eh legal pq o usuario n consegue fazer integer overflow, se preencher o valor max suportado pelo int com sinal, 2147483648, fica negativo e o if da true rsrsrsrsrsr
        puts("Invalid value!");
        exit(1);
    }
	return sz;
}

void alloc(int sz, double **arr){
	*arr =  (double *) malloc(sz * sizeof(double));
	if(*arr == NULL) {
		puts("Allocation error!");
		exit(1);
	}
}

void attribution(double *arr) {
    for(size_t i = 0; i < 10; i++) {
        *(arr+i) = rand()% 101;
        printf("arr %zu\tvalue: %lf\n", i, *(arr+i));
    }
}

int main() {
	double *arr;
	alloc(get_size(), &arr);
	attribution(arr);	
    free(arr);
	return 0;
} 


