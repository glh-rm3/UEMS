/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 5
Exercício: 11

Escreva um programa que acumula n valores da sequencia de Fibonacci em uma pilha
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	unsigned long long value;
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

Content peek(Stack *st) {
    Content empty = {-1};
    if(st == NULL || is_empty(st)) return empty;

    return (*st)->data;
}

/* só para destacar que odeio recursividade. Meu cerébro ferve
int fib(int n) {
    if(n <= 2) 
        return 1;
    else
        return fib (n - 1) + fib (n - 2);
}
*/ 

unsigned long long int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;

    unsigned long long a = 1, b = 1, res = 0;
    for (int i = 3; i <= n; i++) {
        res = a + b;
        a = b;
        b = res;
    }
    return res;
}

int main() {
    Stack *st = create_stack();
    
    int n;
    printf("Enter a N: ");
    while(scanf("%d", &n) != 1 || n < 0 || n > 92) { // n = 93 == integer overflow
        clean_buffer();
        puts("Try again (enter a positive integer)!");
        
    }

    for(int i = 0; i <= n; i++) {
        Content c;
        c.value = fibonacci(i);
        push(st, c);
    }

    printf("\nFibonacci Stack (Top to Bottom):\n");
    while(!is_empty(st)) {
        Content c = pop(st);
        printf("[%ld]\n", c.value);
    }
    printf("\n");
    free(st);
    return 0;
}
