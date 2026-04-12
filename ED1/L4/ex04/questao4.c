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
    printf("\n");
    return 1;
}

int comp_queue(Queue *q1, Queue *q2) {
    if(q1 == NULL || q2 == NULL) return 0; 
    
    Elem *node1 = q1->start;
    Elem *node2 = q2->start;

    size_t sum = 0, size_q1 = 0, size_q2 = 0;
    size_t tam_data = sizeof(node1->data);

    while(node1 != NULL) {
//        printf("Sizeof q1: %zu\n", sizeof(node->data)); apenas para verificar se pega 4byte, tipo int 
        sum += sizeof(node1->data);   // sum = sum + tamanho do campo data, com isso sum pega o tamanho todo da lista
        node1 = node1->next;          
    }
    size_q1 = sum/tam_data;
    sum = 0;
    
    while(node2 != NULL) {
        sum += sizeof(node2->data);
        node2 = node2->next;
    }
    size_q2 = sum/tam_data;
    
    if(size_q1 > size_q2) {
        puts("Queue 1 > Queue 2");
    } else if(size_q1 == size_q2) {
        puts("Queue 1 == Queue 2");
    } else {
        puts("Queue 1 < Queue 2");
    }
    printf("Queue 1: %zu\nQueue 2: %zu\n ", size_q1, size_q2);
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

    comp_queue(q1, q2);
    if(!free_queue(q1)) {
        puts("Failed free queue!");
    } 
    if(!free_queue(q2)) {
        puts("Failed free queue!");
    }
    return 0;
}
