/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 1
Exercício: 5
*/

/**********************************************************************************************************
 *  Faça um programa que leia duas variáveis do tipo inteiro (A e B) e duas do tipo ponteiro de inteiro   *
 *apontando para essas variáveis. Utilizando ponteiros, o programa deve retornar a soma do dobro dos      *
 *dois números lidos. O dobro de A na própria variável A e o dobro de B na própria variável B             *
 **********************************************************************************************************/
#include <stdio.h>

int 
main() {
    int A, B, *pa, *pb; // duas variáveis inteiras e dois ponteiros
    printf("Input A and B: ");
    scanf("%d %d", &A, &B);

    pa = &A; // atribuindo o endereço de A ao ponteiro pa
    pb = &B; // atribuindo o endereço de B ao ponteito pb

    *pa = *pa * 2; // conteúdo apontado por pa recebe conteúdo apontado vezes 2
    *pb = *pb * 2; // conteúdo apontado por pb recebe conteúdo apontado vezes 2

    printf("Sum: %d\n", (*pa) + (*pb)); // print da soma, somando os conteúdo apontados
    printf("A value: %d\nB value: %d\n", A, B); // mostra o valor resultado através da multiplicação anteriormente, feita utilizando o ponteiro
    
    return 0;
}
