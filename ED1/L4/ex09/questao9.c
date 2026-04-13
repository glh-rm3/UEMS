/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 4
Exercício: 9

Faça uma função que receba uma fila como argumento e retorne o valor armazenado em seu início. A
função deve remover também esse elemento.
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

int return_first_rm_first(Queue *q) {
    if(q == NULL || q->start == NULL) return -1;
    
    int first = q->start->data.value;
    Elem *temp = q->start;

    q->start = q->start->next;

    if(q->start == NULL) {
        q->end = NULL; 
    }
    free(temp);
    return first;
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
    Queue *q = create_queue();
    Content c[4];
    c[0].value = 500;
    c[1].value = 4;
    c[2].value = 8;
    c[3].value = 16;

    for(size_t i = 0; i < 4; i++) {
        if(!enqueue(q, c[i])) {
            FAILED_ADD();
            break;
        }
    }

    int rt = return_first_rm_first(q);
    if( rt == -1) {
        puts("Failed");
    } else {
        printf("First Value: %d\n", rt);
    }
    free_queue(q);
    return 0;
}


