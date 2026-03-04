#include <stdio.h>
#include <stdlib.h>
int 
main() {
  int i, *p, *p1;
  p = (int *) malloc(5*sizeof(int));
  p1 = (int *) calloc(5, sizeof(int));
  printf("calloc \t\t malloc\n");
  for(i = 0; i < 5; i++) {
    printf("P1[%d] = %d\n", i, *(p+i));
    printf("P[%d] = %d\n", i, *(p1+i));

  }
}
