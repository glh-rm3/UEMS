/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 4
Exercício: 03

Implemente a função reverso, que reposiciona os elementos na fila dinâmica de tal forma que o início
da fila dinâmica torna-se o fim, e vice-versa.
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TAM 4

typedef struct {
    int value;
} Content;

typedef struct Element {
    Content data;
    struct Element *next;
} Elem;

typedef struct queue {
    struct Element *start;
    struct Element *end;
} Queue;

Queue * create_queue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    if(q != NULL) {
        q->start = NULL;
        q->end = NULL;
    }
    return q;
}

int enqueue(Queue *q, Content c) {
    if(q == NULL) return 0;
    Elem *node = malloc(sizeof(Elem));
    if(node == NULL) return 0;

    node->data = c;
    node->next = NULL;

    if(q->end == NULL) {
        q->start = node;
    } else {
        q->end->next = node;
    }
    q->end = node;
    return 1;
}

int print_queue(Queue *q) {
    if(q == NULL) return 0;

    Elem *node = q->start;
    while(node != NULL) {
        printf("%d\n", node->data.value);
        node = node->next;
    }
    return 1;
}

void FAILED_ADD(){
    puts("Failed to add to queue!");
}

void FAILED_PRINT() {
    puts("Failed to print!");
}

int main() {
    Queue *q = create_queue();
    Content c[TAM];
    c[0].value = 233;
    c[1].value = 333;
    c[2].value = 433;
    c[3].value = 533;

    for(size_t i = 0; i < sizeof(c)/sizeof(int); i++) {
        if(!enqueue(q, c[i])) {
            FAILED_ADD();
            break;
        }
    }
    
    if(!print_queue(q)) {
        FAILED_PRINT();
    } else {
        puts("Success!");
    }
    
    return 0;
}
