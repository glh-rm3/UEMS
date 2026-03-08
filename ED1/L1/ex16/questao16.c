/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 1
Exercício: 16
*/

/*************************************************************************************************************
 *  Considere a seguinte declaração: int A, *B, **C, ***D; Escreva um programa que leia a variável ‘A’       *
 *  e calcule e exiba o dobro, o triplo e o quádruplo desse valor utilizando apenas os ponteiros B, C e D.   *
 *  O  ponteiro B deve ser usada para calcular o dobro, C o triplo e D o quádruplo.                          *
 *************************************************************************************************************/   

#include <stdio.h>

int 
main() {
    int A, *B, **C, ***D;

    printf("Value: ");
    scanf("%d", &A);
    
    B = &A;
    printf("Dobro: %d\t", *B * 2); 

    C = &B;
    printf("Triplo: %d\t", **C * 3);

    D = &C;
    printf("Quadruplo: %d\n", ***D * 4);
    return 0;
}
