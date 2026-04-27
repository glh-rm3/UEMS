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
    int start, end, qtd;
    Content data[MAX];
} Queue;

Stack * create_stack() {
	Stack *st = malloc(sizeof(Stack));
	if(st != NULL) {
		st->qtd = 0;
	}
	return st;
}

Queue *create_queue() {
    Queue *q = malloc(sizeof(Queue));
    if(q != NULL) {
        q->start = 0;
        q->end = 0;
        q->qtd = 0;
    }
    return q;
}

int is_full_queue(Queue *q) {
    if(q == NULL) return 0;
    return (q->qtd == MAX);
}

int is_empty_queue(Queue *q) {
    if(q == NULL) return 0;
    return (q->qtd == 0);
}

int enqueue(Queue *q, Content c) {
    if(q == NULL) return 0;
    if(is_full_queue(q)) return 0;

    q->data[q->end] = c;
    q->end = (q->end+1)%MAX;
    q->qtd++;
    return 1;
}

Content dequeue(Queue *q) {
    Content empty = {-1};
    if(q == NULL || is_empty_queue(q)) return empty;

    Content c = q->data[q->start];
    q->start = (q->start+1)%MAX; 
    q->qtd--;
    return c;
}

int is_empty_stack(Stack *st) {
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
	if(is_empty_stack(st)) return empty;

	st->qtd--;
	return st->data[st->qtd];
}

Content peek(Stack *st) {
    Content empty = {-1};
    if(st == NULL || st->qtd == 0) return empty;

    return st->data[st->qtd -1];
}

int invert(Stack *st, Queue *q) {
    if(st == NULL || q == NULL) return 0;

    while(!is_empty_queue(q)) {
        push(st, dequeue(q));
    }

    while(!is_empty_stack(st)) {
        enqueue(q, pop(st));
    }
    return 1;
}

int print_queue(Queue *q) {
    if(q == NULL || q->qtd == 0) return 0;
    
    printf("Queue: ");
    Queue *print_temp = create_queue();
    while(!is_empty_queue(q)) {
        Content c = q->data[q->start];
        printf("[%d] ", c.value);
        enqueue(print_temp, dequeue(q));
    }

    while(!is_empty_queue(print_temp)) {
        enqueue(q, dequeue(print_temp));
    }
    printf("\n");
    free(print_temp);
    return 1;
}

int main() {
    Stack *st = create_stack();
    Queue *q  = create_queue();
    
    enqueue(q, (Content) {4});
    enqueue(q, (Content) {6});
    enqueue(q, (Content) {8});
    enqueue(q, (Content) {10});
    enqueue(q, (Content) {12});

    print_queue(q);
    invert(st, q);
    print_queue(q);

    free(q);
    free(st);
    return 0;
}
