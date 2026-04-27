/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 5
Exercício: 7

Dado uma pilha que armazene números, escreva uma função para ordenar os valores da pilha em ordem
crescente.
****************************************************************************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct {
	int number;
} Content;

typedef struct stack{
	int qtd;
	Content data[MAX];
} Stack;

Stack * create_stack() {
	Stack *st;
	st = malloc(sizeof(st));
	if(st != NULL) {
		st->qtd = 0;
	}
	return st;
}

int is_full(Stack *st) {
    if(st == NULL) return -1;
    else return (st->qtd == MAX);
}

int is_empty(Stack *st) {
    if(st == NULL) return -1;
    else return (st->qtd == 0);
}   

Content peek(Stack *st) {
    Content empty = {-1};
    if() {

    }
}

int push(Stack *st, Content num) {
    if(is_full(st)) return 0;
    st->data[st->qtd] = num;
    st->qtd++;
    return 1;
}

Content pop(Stack *st) {
    Content empty = {-1};
    if(is_empty(st)) return empty;

    st->qtd--;
    return st->data[st->qtd];
}

sort_stack(Stack *st) {
    Stack *aux = create_stack();

    while(!is_empty(st)) {
        Content temp = pop(st);
        while(!is_empty(aux) {


        }
    }
}

int main() {
    Stack *st = create_stack();

    push(st, (Content){50});
    push(st, (Content){20});
    push(st, (Content){90});
    push(st, (Content){60});
    push(st, (Content){70});
    
    Stack *temp_print = create_stack();
    while(!is_empty(st)) {
        Content c = pop(st);
        printf("%d \n", c.number);
        push(temp_print, c);
    }

    while(!is_empty(temp_print))
        push(st, pop(temp_print)); //insere o content saida do pop da temporaria

    sort_stack(st);


}
