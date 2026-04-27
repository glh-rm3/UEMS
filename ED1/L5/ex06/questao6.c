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
#include <string.h>

#define MAX 30

typedef struct {
	char letter;
} Content;

typedef struct stack{
	int qtd;
	Content word[MAX];
} Stack;

Stack * create_stack() {
	Stack *st;
	st = malloc(sizeof(st));
	if(st != NULL) {
		st->qtd = 0;
	}
	return st;
}

void push(Stack *st, char c) {
    if(st->qtd < MAX -1) {
        st->qtd++;
        st->word[st->qtd].letter = c;
    }
}

char pop(Stack *st) { //remove
    if(st->qtd != 0) {
        char popped = st->word[st->qtd].letter;
        st->qtd--;
        return popped;
    }
    return '\0';
}

int is_empty(Stack *st) {
    if(st == NULL) return -1;
    return (st->qtd == 0);
}

int check_parentization(Stack *st, Content *word) {
    if(st == NULL) return 0;    

    int i = 0;
    while(st->word[i].letter != '\0') {
        char current = st->word[i].letter;
        if(current == '(') {
            push (st, current);
        } else if(current == ')') {
            if(is_empty(st)) {
                return 0;
            }
            pop(st);
        }
    }
    return is_empty(st);
}

void FAILED_INSERT() {
	puts("Failed to insert");
}

int main() {
	Stack *st = create_stack();
	Content *word;
	word = malloc(30 * sizeof(Content));
	if(word == NULL) return -1;

    printf("insert parentheses: ");
	for(size_t i = 0; i < 30; i++) {
		scanf("%c", &(word+i)->letter);
		if((word+i)->letter == '\n') {
            break; 
        }
        if(!check_parentization(st, word)) {
            puts("Incorret!");
        } else 
            puts("Correct!");
    }
    return 0;
}



