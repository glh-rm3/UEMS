/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 5
Exercício: 10

Considere uma pilha P vazia e uma fila F não vazia. Utilizando apenas as funções da fila e da pilha,
escreva uma função que inverta a ordem dos elementos da fila.
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

typedef struct queue {
    int qtd;
    Content data[MAX];
} Queue;

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

int main() {

}
