/***************************************************************************************************
nome: guilherme henrique ferreira de oliveira 
matrícula: 54883
lista: 5
exercício: 8

desenvolva uma função para testar se duas pilhas p1 e p2 são iguais.
****************************************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
	int value;
} Content;

typedef struct stack {
	int qtd;
	Content data[MAX];
} Stack;

Stack *create_stack() {
	Stack *st = malloc(sizeof(Stack));
	if(st != NULL) {
		st->qtd = 0;
	}
	return st;
}

int is_full(Stack *st) {    
	if (st == NULL) return -1;
	return (st->qtd == MAX);
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

Content peek(Stack *st) {
	Content empty = {-1};
	if(is_empty(st) || st == NULL) return empty;

	return st->data[st->qtd];
}

Content pop(Stack *st) {
	Content empty = {-1};
	if(is_empty(st)) return empty;
	
	st->qtd--;
	return st->data[st->qtd];
}

int is_equal(Stack *st0, Stack *st1) {
	if(st0 == NULL || st1 == NULL) return -1;
	
	Stack *aux0 = create_stack(); //criei uma aux para não dar pop na st0 real
	Stack *aux1 = create_stack(); //criei uma aux para não dar pop na st0 real

	if(st0->qtd != st1->qtd) { //se qtd for diferente, não eh igual
		return 0;
	}

	int is_equal = 1;

	while(!is_empty(st0)) {
		Content c0 = pop(st0);
		Content c1 = pop(st1);

		push(aux0, c0);
		push(aux1, c1);

		if(c0.value != c1.value) {
			is_equal = 0;
			break;
		}
	}

	while(!is_empty(aux0)) {
		pus
	}

	return 1;
}

int main() {
	Stack *st0 = create_stack();
	Stack *st1 = create_stack();

	push(st0, (Content){34});
	push(st0, (Content){28});
	push(st0, (Content){36});

	push(st1, (Content){34});
	push(st1, (Content){28});
	push(st1, (Content){36});

	if(is_equal(st0, st1)) {
		puts("is equal!");
	} else 
		puts("is different");

	free(st0);
	free(st1);
	return 0;
}
