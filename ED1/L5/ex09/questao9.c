/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 5
Exercício: 9

Desenvolva uma operação para transferir elementos de uma pilha P1 para uma pilha P2 (cópia)
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct {
	int value;
} Content;

typedef struct stack{
	int qtd;
	Content data[MAX];
} Stack;

Stack * create_stack() {
	Stack *st = malloc(sizeof(Stack));
	if(st != NULL) {
		st->qtd = 0;
	}
	return st;
}

int is_empty(Stack *st) {
	return (st == NULL || st->qtd == 0);
}

int push(Stack *st, Content c) {
	if(st == NULL) return 0;

	st->data[st->qtd] = c;
	st->qtd++;
	return 1;
}

Content pop(Stack *st) {
	Content empty = {-1};
	if(is_empty(st)) return empty;

	st->qtd--;
	return st->data[st->qtd];
}

Content peek(Stack *st) {
    Content empty = {-1};
    if(st == NULL || st->qtd == 0) return empty;

    return st->data[st->qtd -1];
}

int copy_stack(Stack *st, Stack *new) {
    if(st == NULL || st->qtd == 0) return 0;

    Stack *aux = create_stack();
    while(!is_empty(st)) {  
        Content cp = pop(st); // desempilha st passando tudo para aux 
        push(aux, cp);        // empilha em aux 
    }

    while(!is_empty(aux)) {   // momento da devolução de st e atribuição ao new_st
        push(new, peek(aux)); // empilha apenas observando o topo de aux
        push(st, pop(aux));   // empilha removendo o topo de aux 
    }
    free(aux);
    return 1;
}

int print_stack(Stack *st) {
    if(st == NULL || st->qtd == 0) return 0;

    Stack *print_temp = create_stack();
    puts("Stack");
    while(!is_empty(st)) {
        Content c = pop(st);
        printf("[%d]\n", c.value);
        push(print_temp, c);
    }
    printf("====\n");
    while(!is_empty(print_temp)) {
        push(st, pop(print_temp));
    }
    free(print_temp);
    return 1;
}

int main() {
    Stack *st = create_stack();
    Stack *new_st = create_stack(); 

    push(st, (Content){8});
    push(st, (Content){16});
    push(st, (Content){32});
    push(st, (Content){64});
    push(st, (Content){128});
    
    copy_stack(st, new_st);
    print_stack(st);
    print_stack(new_st);

    free(st);
    free(new_st);
    return 0;
}
