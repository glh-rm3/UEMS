/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 1
Exercício: 6
*/

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

    pi = &i; // pi agora aponta para o endereço de i 
    pj = &j; // pj agora aponta para o endereço de j

    printf("Sum: %d\n", (*pi) + (*pj));  // soma os conteúdos apontados pelos ponteiros 
    printf("Sub: %d\n", (*pi) - (*pj));  // subtrai os conteúdos apontados pelos ponteiros 
    printf("Mult: %d\n", (*pi) * (*pj)); // multiplica os conteúdos apontados pelos ponteiros 
    if((float)(*pj) == 0) {  // o denomindor é pj e ele nunca pode ser zero!
        puts("Invalid Operation!");
    } else {                 // senão eh 0, divide 
        printf("Div: %.4f\n", (float)(*pi) / (float)(*pj)); // divide os conteúdos apontados pelos ponteiros 
    }

    return 0;
}
