/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 4
Exercício: 5

Dada uma fila de inteiros, escreva um programa que exclua todos os números negativos.
****************************************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
} Content;

typedef struct Element{
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

int delete_negative(Queue *q) {
    if(q == NULL) return 0;
    
    Elem *atual = q->start;
    Elem *prev = NULL;
    
    while(atual != NULL) {
        if(atual->data.value < 0) { 
            Elem *temp = atual;
            if(prev == NULL) {  // Se prev é NULL, vai deletar o primeiro elemento da fila
                q->start = atual->next;   // meu inicio agora eh o segundo elemeno
            } else { //deleta o nó no meio da fila, meu prox anterior eh o proximo do atual agora [A] -> [-B] -> [C] disso fica [A] -> [C]
                prev->next = atual->next;
            }

            if(atual->next == NULL) {
                q->end = prev; // Se tiver que deletar o útlimo 
            }

            atual = atual->next; //atual avança, prev fica parado 
            free(temp);
        } else {
            prev = atual;
            atual = atual->next;
        }
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
    Queue *q = create_queue();
        
    Content c0[4];
    c0[0].value = -1;
    c0[1].value = 3;
    c0[2].value = -4;
    c0[3].value = 7; 

    for(size_t i = 0; i < 4; i++) {
        if(!enqueue(q, c0[i])) {
            FAILED_ADD();
            break;
        }
    }

    print_queue(q);
    if(!delete_negative(q)) {
        FAILED_DELETE();
    } else {
        print_queue(q);
    }

    if(!free_queue(q)) {
        puts("Failed free queue!");
    } 
    return 0;
}

