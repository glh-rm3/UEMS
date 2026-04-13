/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 4
Exercício: 11

Escreva um programa que leia uma sequência de linhas, onde cada linha contém a informação da ordem
de chegada e categoria do cliente e imprima a ordem de atendimento (considere que todos chegaram
antes de começar o atendimento).
****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int bypasses;
} Content;

typedef struct Element {
    Content data;
    struct Element *next;
} Elem;

typedef struct {
    Elem *start;
    Elem *end;
} Queue;

Queue *create_queue() {
    Queue *q = malloc(sizeof(Queue));
    if (q) { q->start = q->end = NULL; }
    return q;
}

int enqueue(Queue *q, Content c) {
    if (!q) return 0;
    Elem *node = malloc(sizeof(Elem));
    if (!node) return 0;
    node->data = c;
    node->next = NULL;
    if (!q->end) q->start = node;
    else q->end->next = node;
    q->end = node;
    return 1;
}

Content dequeue(Queue *q) {
    Content empty = {-1, 0};
    if (!q || !q->start) return empty;
    Content val = q->start->data;
    Elem *temp = q->start;
    q->start = q->start->next;
    if (!q->start) q->end = NULL;
    free(temp);
    return val;
}

void increment_bypasses(Queue *q_geral, int idoso_id) {
    Elem *node = q_geral->start;
    while (node) {
        if (node->data.id < idoso_id)
            node->data.bypasses++;
        node = node->next;
    }
}

int main() {
    Queue *q_geral = create_queue();
    Queue *q_idoso = create_queue();
    int id;
    char tipo[10];

    while (scanf("%d %s", &id, tipo) == 2) {
        Content c = {id, 0};
        if (strcmp(tipo, "geral") == 0)
            enqueue(q_geral, c);
        else
            enqueue(q_idoso, c);
    }

    while (q_geral->start || q_idoso->start) {
        if (!q_idoso->start) {
            printf("%d ", dequeue(q_geral).id);
        } else if (!q_geral->start) {
            printf("%d ", dequeue(q_idoso).id);
        } else if (q_geral->start->data.bypasses >= 2) {
            printf("%d ", dequeue(q_geral).id);
        } else {
            Content i = dequeue(q_idoso);
            printf("%d ", i.id);
            increment_bypasses(q_geral, i.id);
        }
    }

    printf("\n");
    return 0;
}


/*
*    1 geral 
*    2 idoso
*    3 geral
*    4 idoso
*    5 geral
*
*    |  ./questao11  tem que dar entrada nos dados e mandar o parametro | ./questao11, pelo menos no meu pc
*    funciona, mas outra hr arrumo, faltam 6 minutos pra anexar;
*   
*
*/ 
