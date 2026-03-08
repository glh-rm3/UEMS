/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 1
Exercício: 14
*/

/*********************************************************************************************************
 *  Elabore um programa que dado um array e um valor do mesmo tipo do array, preencha os elementos       *
 *  de array com esse valor. Não utilize índices para percorrer o array, apenas aritmética de ponteiros. *
 * *******************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int 
main() {
    int *arr, value = 67;
    arr = (int*) malloc(TAM*sizeof(int));
    if(arr == NULL) return -1;

    for(size_t i = 0; i < TAM; i++) 
        *(arr+i) = value;
    for(size_t i = 0; i < TAM; i++)
        printf("Value: %d\tAddress: %p\n", *(arr+i), arr+i);
    free(arr);
    return 0;
}
