/**********************************************************************************************************
 *  Faça um programa que leia duas variáveis do tipo inteiro (A e B) e duas do tipo ponteiro de inteiro   *
 *apontando para essas variáveis. Utilizando ponteiros, o programa deve retornar a soma do dobro dos      *
 *dois números lidos. O dobro de A na própria variável A e o dobro de B na própria variável B             *
 **********************************************************************************************************/
#include <stdio.h>

int 
main() {
    int A, B, *pa, *pb;
    printf("Input A and B: ");
    scanf("%d %d", &A, &B);

    pa = &A;
    pb = &B;

    *pa = *pa * 2;
    *pb = *pb * 2;

    printf("Sum: %d\n", (*pa) + (*pb));
    printf("A value: %d\nB value: %d\n", A, B);
    
    return 0;
}
