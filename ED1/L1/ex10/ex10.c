/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 1
Exercício: 10
*/

/***********************************************************************************************
 * Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas. Utilizando *
 * aritmética de ponteiro, imprima o endereço de cada posição dessa matriz                     *
 ***********************************************************************************************/
#include <stdio.h>

int 
main() {
    float m[3][3], *p = &m[0][0];

    for(size_t i = 0; i < sizeof(m)/sizeof(int); i++) {
        printf("Pos: %zu Addres: %p\n", i, (void*)(p + i)); 
    }
}
