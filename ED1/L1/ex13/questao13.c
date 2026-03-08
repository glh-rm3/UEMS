/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 1
Exercício: 13
*/

/******************************************************************************************************
 * Elabore um programa que receba duas strings digitadas pelo usuário e verifique se a segunda string *
 * ocorre dentro da primeira. Use aritmética de ponteiros para acessar os caracteres das strings.     *
 * ***************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARG_MAX 64

void get_string(char* s1, char* s2) {
    printf("Str1: ");
    fgets(s1, ARG_MAX, stdin);
    printf("Str2: ");
    fgets(s2, ARG_MAX, stdin);
    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';
}

void occ(char* s1, char* s2) {
    int i = 0;
    int flag = 0;
    if(*(s2) == '\0') return;
    if(strlen(s2) > strlen(s1)) return;

    while(*(s1+i) != '\0') {
        int j = 0;
        int find = 1;

        while(*(s2+j) != '\0') {
            if(*(s1+i+j) != *(s2+j) || *(s1+i+j) == '\0') {
                find = 0;
                break;
            }
            j++;
        }

        if(find == 1) {
            flag = 1;
            for(size_t k = 0; k < j; k++) {
                printf("Caracter: %c\tAddress: %p\n", *(s1+i+k), s1+i+k);
            }
            printf("\n");
        } 
        i++;
    }

    if(flag == 0) puts("No occurrence!");
}

int 
main() {
    char *str1 = (char*) malloc(ARG_MAX * sizeof(char));
    char *str2 = (char*) malloc(ARG_MAX * sizeof(char));
    
    if(str1 == NULL || str2 == NULL) return -1;

    get_string(str1, str2);
    occ(str1, str2);

    free(str1);
    free(str2);

    return 0;
}
