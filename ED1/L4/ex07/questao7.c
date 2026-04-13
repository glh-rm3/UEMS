/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 4
Exercício: 7

Escreva uma função que, dado duas filas dinâmicas, concatene as duas filas. Retorne a fila concatenada
em F1. F2 deve ficar vazia.
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
}  Content;

typedef struct Element {
    Content data;
    struct Element *next;
} Elem;

typedef struct queue {
    struct Element *start;
    struct Element *end;
} Queue;

Queue * create_queue() {
    Queue *q = malloc(sizeof(Queue));
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

Queue * concatenated_queue(Queue *q0, Queue *q1) {
    if(q0 == NULL || q1 == NULL) return 0;

    if(q1->start == NULL) return q0;

    if(q0->start == NULL) {
        q0->start = q1->start;
        q0->end = q1->start;
    } else {
        q0->end->next = q1->start;
        q0->end = q1->end;
    }
       
    q1->start = NULL;
    q1->end = NULL;
    return q0;
}

int print_queue(Queue *q) {
    if(q == NULL) return 0;

    Elem *node = q->start;
    while(node != NULL) {
        printf("%d ", node->data.value);
        node = node->next;
    }
    printf("\n");
    return 1;
}
int free_queue(Queue *q) {
    if(q == NULL) return 0;

    Elem *node = q->start;
    while(node != NULL) {
        Elem *temp = node;
        node = node->next;
        free(temp);
    }
    free(q);
    return 1;
}

void FAILED_ADD(){
    puts("Failed to add to queue!");
}

void FAILED_PRINT() {
    puts("Failed to print!");
}

int main() {
    Queue *q0 = create_queue();
    Queue *q1 = create_queue();
    Content c0[4], c1[3];
    c0[0].value = 1;
    c0[1].value = 4;
    c0[2].value = 8;
    c0[3].value = 16; 

    c1[0].value = 32; 
    c1[1].value = 64; 
    c1[2].value = 128; 

    for(size_t i = 0; i < 4; i++) {
        if(!enqueue(q0, c0[i])) {
            FAILED_ADD();
            break;
        }
    }

    for(size_t i = 0; i < 3; i++) {
        if(!enqueue(q1, c1[i])) {
            FAILED_ADD();
            break;
        }
    }
    if(!print_queue(q0)) {
        FAILED_PRINT();
    }
    if(!print_queue(q1)) {
        FAILED_PRINT();
    }

    Queue *q2 = concatenated_queue(q0, q1);
    puts("concatenated queue: ");
    if(!print_queue(q2)) {
        FAILED_PRINT();
    }

    free_queue(q2);
    return 0;
}
