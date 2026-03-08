/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 1
Exercício: 8
*/

/********************************************************************************************************
 * Faça um programa que leia seis números e armazene-os em um vetor. Utilizando aritmética de ponteiro, *
 * imprima os valores do vetor. O programa deve apresentar também o endereço de memória desses números  *
 ********************************************************************************************************/
#include <stdio.h>

int 
main() {
    int _vet[6];
    int *p; 
    
    p = _vet;
    for(size_t i = 0; i < sizeof(_vet)/sizeof(int); i++) {
        printf("Vet[%d]: ", i);
        scanf("%d", p + i);
    }
    for(size_t i = 0; i < sizeof(_vet)/sizeof(int); i++) {
        printf("Value: %d Address: %p\n", *(p + i), p + i);
    }
    return 0;
}
