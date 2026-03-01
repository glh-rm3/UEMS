#include <stdio.h>

int main() {
  int x = 10, y = 20;
  int *p1;
  int *p2;

  printf("End de x: %p\n", &x);
  printf("End de y: %p\n", &y);

  p1 = &x;
  p2 = &y;
  printf("End de p1: %p\n", p1); 
  printf("End de p2: %p\n", p2);

  (p1)++;
  printf("End de p1: %p\n", p1); 
  printf("End de p2: %p\n", p2);
}
