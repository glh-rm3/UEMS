/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 1
Exercício: 9
*/

/******************************************************************************************************
 *  Crie um programa que contenha um array de float contendo 10 elementos. Utilizando aritmética de   *
 *  ponteiro, imprima o endereço de cada posição desse array.                                         *
 ******************************************************************************************************/ 
#include <stdio.h>

int 
main() {
    float arr[10] = {10.0, 10.1, 10.2, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8, 10.9};
    float *p;
    p = arr;
    for(size_t i = 0; i < sizeof(arr)/sizeof(int); i++) {
        printf("Arr[%zu]: %.1f Address: %p\n", i, *(p + i), (void*)(p + i));
    }
    return 0;
}
