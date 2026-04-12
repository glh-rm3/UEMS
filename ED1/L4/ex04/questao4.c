/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 4
Exercício: 4

Desenvolva uma função para testar se uma fila F1 tem mais elementos do que uma fila F2. Não utilize
o nó descritor “qtd” para tal finalidade.
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define Tam0 4
#define Tam1 5

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

    node->data = c;              // guarda o conteudo / payload
    node->next = NULL;           // fila FIFO, quem entra sempre vai pro final
                                 // logo o proximo eh null
    if(q->end == NULL) {         // se o fim eh null, o inicio tbm eh
        q->start = node;         // como esse eh o primerio e unico elemento, inicio aponta p ele
    } else {                     // caso tenha algo na fila, avisa para o ultimo que o prox dele nao aponta mais pra null
        q->end->next = node;     // agora aponta p ele.          
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

int comp_queue(Queue *q1, Queue *q2) {
    if(q1 == NULL || q2 == NULL) return 0; 
    Elem *node = 
    int contq1, contq2;
    contq1 = contq2 = 0;
    
}

void FAILED_ADD(){
    puts("Failed to add to queue!");
}

void FAILED_PRINT() {
    puts("Failed to print!");
}
 
void FAILED_REVERSE() {
    puts("Failed to reverse!");
}

int main() {
    Queue *q1 = create_queue();
    Queue *q2 = create_queue();
    
    Content c0[Tam0], c1[Tam1];
    c0[0].value = 1;
    c0[1].value = 4;
    c0[2].value = 8;
    c0[3].value = 16; 

    c1[0].value = 32; 
    c1[1].value = 64; 
    c1[2].value = 128; 
    c1[3].value = 256; 
    c1[4].value = 512;

    for(size_t i = 0; i < Tam0; i++) {
        if(!enqueue(q1, c0[i])) {
            FAILED_ADD();
            break;
        }
    }
    for(size_t i = 0; i < Tam1; i++) {
        if(!enqueue(q2, c1[i])) {
            FAILED_ADD();
            break;
        }
    }
    if(!print_queue(q1) || !print_queue(q2)) {
        FAILED_PRINT();
    } else {
        puts("Success!");
    }
}
