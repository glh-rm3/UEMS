/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 4
Exercício: 6

Faça uma função que receba três filas, duas já preenchidas em ordem crescente e preencha a última
com os valores das duas primeiras em ordem crescente.
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

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

int join_queue_ascendig(Queue *q0, Queue *q1, Queue *q2) {
    if(q0 == NULL || q1 == NULL || q2 == NULL) return 0;
    Elem *node_0 = q0->start;
    Elem *node_1 = q1->start;

    while(node_0 != NULL && node_1 != NULL) {
        if(node_0->data.value < node_1->data.value) {
            enqueue(q2, node_0->data);
            node_0 = node_0->next;
        } else {  
            enqueue(q2, node_1->data);
            node_1 = node_1->next;
        }
    }

    //flush, sempre sobra um de uma das listas
    while(node_0 != NULL) {
        enqueue(q2, node_0->data);
        node_0 = node_0->next;
    }

    while(node_1 != NULL) {
        enqueue(q2, node_1->data);
        node_1 = node_1->next;
    }
    return 1;
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
 
void FAILED_DELETE() {
    puts("Failed to delete!");
}

int main() {    
    Queue *q0 = create_queue();
    Queue *q1 = create_queue();
    Queue *q2 = create_queue();

    Content c0[3], c1[3];
    c0[0].value = 10;
    c0[1].value = 20;
    c0[2].value = 30;

    c1[0].value = 9;
    c1[1].value = 15;
    c1[2].value = 25;

    for(size_t i = 0; i < 3; i++) {
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

    print_queue(q0);
    print_queue(q1);

    join_queue_ascendig(q0, q1, q2);
    print_queue(q2);
    free_queue(q0);
    free_queue(q1);
    free_queue(q2);
    return 0;
}
