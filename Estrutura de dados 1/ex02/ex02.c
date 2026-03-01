#include <stdio.h>

 /*
  * Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real e char.
  * Associe as variáveis aos ponteiros (use &). Modifique os valores de cada variável usando os ponteiros.
  * Imprima os valores das variáveis antes e após a modificação.
  * */

int main() {
  int n1 = 10;
  float n2 = 10.5;
  char c = 'c';
  
  int *p1;
  float *p2;
  char *pc;
  
  printf(" n1: %d n2: %f char c: %c\n", n1, n2, c);
  p1 = &n1;
  p2 = &n2;
  pc = &c;

  *p1 = 15;
  *p2 = 15.5;
  *pc = 'd';

  printf(" n1: %d n2: %f char c: %c\n", n1, n2, c);
  return 0;
}
