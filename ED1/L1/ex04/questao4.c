/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 1
Exercício: 4
*/

/************************************************************************************************************
 *  Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do teclado. Em seguida,  *
 *  compare seus endereços e exiba o conteúdo do maior endereço.                                            *
 ************************************************************************************************************/

#include <stdio.h>

int 
main() {
    int i, j, *aux;
    printf("Input i: "); 
    scanf("%d", &i); 
    printf("Input j: ");
    scanf("%d", &j);
    
    if(&i < &j) aux = &j; // se endereço de i for menor que endereço de j, aux = endereço de j
    else aux = &i;        // senão, aux recebe endereço de i
    
    printf("\nContent: %d Address: %p\n", *aux, aux); // demonstra o conteúdo apontado por aux e o endereço que aux aponta
    printf("Address i: %p\n", &i);
    printf("Address j: %p\n", &j);
    puts("A Stack cresce para baixo!"); 

    return 0;
}
