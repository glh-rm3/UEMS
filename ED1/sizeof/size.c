#include <stdio.h>

typedef struct {
  int x, y;
} ponto;

int 
main() {
  ponto p;
  printf("Char: %zu\n", sizeof(char));
  printf("Int: %zu\n", sizeof(int));
  printf("float: %zu\n", sizeof(float));
  printf("double: %zu\n", sizeof(double));
  printf("float: %zu\n", sizeof(p));
    
}
