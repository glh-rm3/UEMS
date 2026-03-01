/********************************************************************************************************
 *   Escreva um programa que contenha duas variáveis inteiras. Compare seus endereços e exiba o maior   *
 *   endereço.                                                                                          *
 ********************************************************************************************************/
#include <stdio.h>

int 
main() {
    int i = 750, j = 400, *aux;
    printf("%p = %d\n%p = %d\n", &i, i, &j, j);
  
    if(&j > &i) {
        aux = &j;
    } else {
        aux = &i;
    }
    printf("%p = %d\n", aux, *aux);
    return 0;
}
