#include <stdio.h>
#include <stdlib.h>

int 
main() {
  int *p;
  p = (int *) malloc(5*sizeof(int));
  if(p == NULL) {
    puts("ERRO: Memoria insuficiente!\n");
    system("pause");
    exit(1);
  }
  for(int i = 0; i < 5; i++) {
    printf("Digite o valor da posicao %d: ", i);
    scanf("%d", p + i);
    printf("Valor digitado: %d", *(p+i));
  }

}
