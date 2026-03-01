/*****************************************************************************************************
 * Escreva um programa que declare duas variáveis do tipo inteiro e duas do tipo ponteiro de inteiro *
 * apontando para essas variáveis. Utilizando ponteiros, o programa deve ler dois números para essas *
 * variáveis e os imprimir, realizando as quatro operações básicas de matemática com esses números.  *
 *****************************************************************************************************/
#include <stdio.h>

int 
main() {
    int i, j, *pi, *pj;
    printf("Input i and j: ");
    scanf("%d %d", &i, &j);

    pi = &i;
    pj = &j;

    printf("Sum: %d\n", (*pi) + (*pj));
    printf("Sub: %d\n", (*pi) - (*pj));
    printf("Mult: %d\n", (*pi) * (*pj));
    printf("Div: %.4f\n", (float)(*pi) / (float)(*pj));

    return 0;
}
