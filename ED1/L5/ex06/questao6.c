/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 5
Exercício: 6

Escreva um programa que utilize uma pilha para verificar se expressões aritméticas estão com a pa-
rentização correta. O programa deve verificar expressões para ver se cada “abre parenteses” tem um
“fecha parenteses” correspondente. Ex.:
Correto: ( ( ) ) – ( ( )( ) ) – ( ) ( )
Incorreto: )( – ( ( ) ( – ) ) ( (
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* create_stack() {
    Stack* st = (Stack*)malloc(sizeof(Stack));
    if (st != NULL) {
        st->top = NULL;
    }
    return st;
}

int is_empty(Stack* st) {
    return st->top == NULL;
}

void push(Stack* st, char c) {
    Node* new = (Node*)malloc(sizeof(Node));
    if (new != NULL) {
        new->data = c;
        new->next = st->top;
        st->top = new;
    }
}

char pop(Stack* st) {
    if (is_empty(st)) {
        return '\0';
    }
    Node* temp = st->top;
    char c = temp->data;
    st->top = st->top->next;
    free(temp);
    return c;
}

int check_parentization() {
    Stack* st = create_stack();
    char c;
    int is_valid = 1;

    printf("insert parentheses: ");

    while(scanf("%c", &c) == 1 && c != '\n') {
        if(c == '(') {
            push(st, c);
        } else if (c == ')') {
            if (is_empty(st)) {
                is_valid = 0;
            } else {
                char top_c = pop(st);
                if ((c == ')' && top_c != '(')) {
                    is_valid = 0;
                }
            }
        }
    }

    if(!is_empty(st) { //--------------------------> se sobrou algo na pilha, a expressão não está balanceada
        is_valid = 0;
    }

    while(!is_empty(st)) {
        pop(st);
    }
    free(st);

    return is_valid;
}

int main() {
    if (check_parentization()) {
        puts("Correct!");
    } else {
        puts("Incorret!"); 
    }
    return 0;
}

