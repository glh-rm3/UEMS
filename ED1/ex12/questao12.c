/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 1
Exercício: 12
*/

/****************************************************************************************************
 * Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array do teclado *
 * e imprima o endereço das posições contendo valores pares.                                        *
 ****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int 
main() {
    int *arr;    

    arr = (int *) malloc(5 * sizeof(int));
    if(arr == NULL) {
        return -1;
    }
    for(size_t i = 0; i < 5; i++) {
        printf("Pos %zu \tvalue: ", i);
        scanf("%d", arr + i);
    }
    for(size_t i = 0; i < 5; i++) {
        if(*(arr+i) % 2 == 0) {
            printf("\nValue: %d\tAddress: %p\n", *(arr+i), arr+i);
        }
    }
    free(arr);
    return 0;
}
