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
    if(is_empty(st)) return empty;
    
    return st->data[st->qtd -1];
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

int sort_stack(Stack *st) {
    if(st == NULL || st->qtd == 0) return 0;
    Stack *aux = create_stack();

    while(!is_empty(st)) {      // enquanto st não estiver vazia 
        Content temp = pop(st);     // pop no primeiro elemento, trazendo para temp 
        while(!is_empty(aux) && peek(aux).number > temp.number) { // Enquanto a aux não estiver vazia E o topo da aux for maior que o meu elemento atual
            // isso significa que o temp deveria estar ABAIXO desse elemento da aux.
            push(st, pop(aux));     // retiramos o elemento maior da aux e devolvemos ele para a st original.
            // é aberto o caminho para o temp encontrar seu lugar correto.
        }
        // agora que o caminho foi aberto ou a aux está vazia, ou o topo da aux é menor/igual a temp),
        // coloca o temp na pilha auxiliar.
        push(aux, temp);
    }
    
    // devolve para st
    while (!is_empty(aux)) {
        push(st, pop(aux));
    }

    free(aux);
    return 1;
}

int print_stack(Stack *st) {
    if(st == NULL || st->qtd == 0 ) return 0;

    Stack *temp_print = create_stack();
    while(!is_empty(st)) {
        Content c = pop(st);
        printf("[%d]\n", c.number);
        push(temp_print, c);
    }

    while(!is_empty(temp_print)) {
        push(st, pop(temp_print));
    }
    printf("====\n");
    return 1;
}

int main() {
    Stack *st = create_stack();

    push(st, (Content){50});
    push(st, (Content){20});
    push(st, (Content){90});
    push(st, (Content){60});
    push(st, (Content){70});
    
    print_stack(st);
    sort_stack(st);
    print_stack(st);
    return 0;
}
