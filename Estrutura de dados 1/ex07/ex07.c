/*************************************************************************************************************
 * Faça um programa que declare três variáveis do tipo inteiro e três do tipo ponteiro de inteiro apontando  *
 * para essas variáveis. Utilizando ponteiros, leia três números e os imprima em ordem crescente. O          *
 * programa deve apresentar também o endereço de memória desses números.                                     *
 ************************************************************************************************************/
#include <stdio.h>

int
main() {
    int i, j, k, *pi, *pj, *pk;
    pi = &i;
    pj = &j;
    pk = &k;

    printf("Input i, j and k: ");
    scanf("%d %d %d", pi, pj, pk);

    int vet[3] = {*pi, *pj, *pk};

    int swap;
    for(size_t i = 0; i < 3; i++) {
        for(size_t j = i + 1; j < 3; j++) {
            if(vet[i] >= vet[j]) {
                swap = vet[i];
                vet[i] = vet[j];
                vet[j] = swap;
            }
        }
        printf("Value: %d Address: %p\n", vet[i], &vet[i]);
    }
    return 0;
}
