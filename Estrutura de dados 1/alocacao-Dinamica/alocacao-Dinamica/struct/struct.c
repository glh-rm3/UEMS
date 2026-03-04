#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[50];
  int idade;
} cad;

int
main() {
  cad *cadastro = (cad*) malloc(10*sizeof(cad));
  strcpy(cadastro[0].nome, "Maria");
  cadastro[0].idade = 30;
  strcpy(cadastro[1].nome, "Cecilia");
  cadastro[1].idade = 10;

  for(int i = 0; i < 2; i++) {
    printf("Nome: %s\n", cadastro[i].nome);
    printf("Idade: %d\n", cadastro[i].idade);
  }
  free(cadastro);
  return 0;
}
