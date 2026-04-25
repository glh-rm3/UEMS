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
	Stack *st;
	st = malloc(sizeof(st));
	if(st != NULL) {
		st->qtd = 0;
	}
	return st;
}

int insert_stack(Stack *st, Content letter) {
	if(st == NULL) return 0;
	st->word[st->qtd] = letter;
	st->qtd++;
	return 1;
}

int check_palindrome(Stack *st) {
	if(st == NULL) return 0;

	int cont = 0;
	size_t j = 0;
	for(size_t i = st->qtd; i > 0; i--) {
		if(st->word[j]->letter == st->word[i-1].letter) {
			cont++;
		}
		j++;
    }
	
	printf("%d", cont);

}

void FAILED_INSERT() {
	puts("Failed to insert");


}

int main() {
	Stack *st = create_stack();
	Content *word;
	word = malloc(30 * sizeof(Content));
	if(word == NULL) return -1;

	int word_tam = 0;
	for(size_t i = 0; i < 30; i++) {
		scanf("%c", &(word+i)->letter);
		if((word+i)->letter == '\n') {
            break; 
        }
		word_tam++;
	}
	
	for(size_t i = 0; i < word_tam; i++) {
		if(!insert_stack(st, word[i])) {
			FAILED_INSERT();
		}
	}
	check_palindrome(st);
	free(word);
}
