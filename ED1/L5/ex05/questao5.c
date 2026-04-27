/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 5
Exercício: 5

Considere uma pilha que armazene caracteres. Escreva uma função que verifique se uma palavra é um
palíndromo.
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
	Stack *st = malloc(sizeof(Stack));
	if(st != NULL) {
		st->qtd = 0;
	}
	return st;
}

int is_empty(Stack *st) {
	return (st == NULL || st->qtd == 0);
}

int push(Stack *st, Content c) {
	if(st == NULL) return 0;

	st->word[st->qtd] = c;
	st->qtd++;
	return 1;
}

Content pop(Stack *st) {
	Content empty = {-1};
	if(is_empty(st)) return empty;

	st->qtd--;
	return  st->word[st->qtd];
}

int is_palindrome(Stack *st, const char* word,  size_t word_size) {
	if(st == NULL || is_empty(st)) return -1;

	int is = 1;
	for(size_t i = 0; i < word_size; i++) {
		Content c = pop(st);
		if(c.letter != word[i]) {
			is = 0;
			return is;
		}
	}
	return is;
}

void FAILED_INSERT() {
	puts("Failed to insert");
}

int main() {
	Stack *st = create_stack();
	char word[30];
	printf("word: ");
	scanf("%29s", word);

	size_t word_size = strlen(word);

	//empilhando
	for(size_t i = 0; i < word_size; i++) {
		Content c;
		c.letter = word[i];
		push(st, c);
	}
	
	if(!is_palindrome(st, word, word_size)) {
		puts("Not a palindrome.");
	} else 
		puts("Palindrome!");

	free(st);

	return 0;
}
