/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 1
Exercício: 15
*/

/*********************************************************************************************************
 * Escreva um programa que receba um array de inteiros com 10 elementos digitados pelo usuário e         *
 * encontre o menor (min) e o maior (max) elemento desse array. Utilize ponteiros tanto para acessar o   *
 * array quanto para acessar as variáveis min e max, ou seja, são necessários pelo menos 3 ponteiros.    *
 *********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TAM 10
int 
main() {
    int *arr, *pMin = 0, *pMax = 0;
    arr = (int *) malloc(TAM*sizeof(int));
    if(arr == NULL) return -1;
    
    for(size_t i = 0; i < TAM; i++) {
        printf("Arr - %zu\tValue: ", i);
        scanf("%d", arr+i);
    }
    pMax = arr;
    pMin = arr;
    for(size_t i = 0; i < TAM; i++) {
        if(*(arr+i) > *pMax) {
            pMax = arr+i;
        }
        if(*(arr+i) < *pMin) {
            pMin = arr+i;
        }
    }
    printf("MAX: %d\n", *pMax);
    printf("MIN: %d\n", *pMin);
    return 0;
}

