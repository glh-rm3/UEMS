/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 5
Exercício: 14

A conversão de números inteiros, na base 10, para outras bases numéricas se dá através de sucessivas
divisões de um dado valor n pelo valor da base na qual se queira converter. Faça um programa para
obter a conversão numérica, de acordo com a opção do usuário, utilizando uma pilha:
(a) Decimal para Binário.
(b) Decimal para Octal.
(c) Decimal para Hexadecimal
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
} Content;

typedef struct stack{
    Content data;
    struct stack *prox;
} *Stack, Elem;

void clean_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Stack * create_stack() {
    Stack *st = malloc(sizeof(Stack));
    if(st != NULL) {
        *st = NULL;
    }
    return st;
}

int is_empty(Stack *st) {
    if(st == NULL)  return 1;
    if(*st == NULL) return 1;
    return 0;
}

int push(Stack *st, Content c) {
    if(st == NULL) return 0;

    Elem *node = malloc(sizeof(Elem));
    if(node == NULL) return 0;

    node->data = c;
    node->prox = (*st);
    *st = node;
    return 1;
}

Content pop(Stack *st) {
    Content empty = {-1};
    if(is_empty(st)) return empty;

    Elem *node = *st;
    Content c = node->data;
    *st = node->prox;
    free(node);
    return c;
}

void convert_base(int num, int base) {
    if (num == 0) {
        printf("0\n");
        return;
    }

    Stack *st = create_stack();

    while (num > 0) {
        Content c;
        c.value = num % base;
        push(st, c);
        num = num / base;
    }

    while (!is_empty(st)) {
        Content c = pop(st);
        
        if (base == 16) {
            printf("%X", c.value);
        } else {
            printf("%d", c.value);
        }
    }
    printf("\n");
    
    free(st);
}

int main() {
    int num, option;

    printf("--- Base Converter ---\n");
    printf("Enter a decimal number (positive integer): ");
    
    while(scanf("%d", &num) != 1 || num < 0) {
        clean_buffer();
        printf("Invalid input. Enter a positive integer: ");
    }

    printf("\nSelect the base for conversion:\n");
    printf("1 - Binary (Base 2)\n");
    printf("2 - Octal (Base 8)\n");
    printf("3 - Hexadecimal (Base 16)\n");
    printf("Option: ");
    
    while(scanf("%d", &option) != 1 || option < 1 || option > 3) {
        clean_buffer();
        printf("Invalid option. Try again (2, 8 or 16): ");
    }

    printf("\nResult: ");
    switch(option) {
        case 1:
            convert_base(num, 2);
            break;
        case 2:
            convert_base(num, 8);
            break;
        case 3:
            convert_base(num, 16);
            break;
    }

    return 0;
}
