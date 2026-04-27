/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 5
Exercício: 5

Considere uma pilha que armazene caracteres. Escreva uma função que verifique se uma palavra é um
palíndromo.
<<<<<<< HEAD
****************************************************************************************************/
=======
****************************************************************************************************/ 
>>>>>>> 888b6efaf5cc3753b83bb90ba2474b90d99952d8

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
<<<<<<< HEAD
	st = malloc(sizeof(Stack));
=======
	st = malloc(sizeof(st));
>>>>>>> 888b6efaf5cc3753b83bb90ba2474b90d99952d8
	if(st != NULL) {
		st->qtd = 0;
	}
	return st;
}

<<<<<<< HEAD
int is_empty(Stack *st) {
	return (st == NULL || st->qtd == 0);
}

int push(Stack *st, Content letter) {
=======
int insert_stack(Stack *st, Content letter) {
>>>>>>> 888b6efaf5cc3753b83bb90ba2474b90d99952d8
	if(st == NULL) return 0;
	st->word[st->qtd] = letter;
	st->qtd++;
	return 1;
<<<<<<< HEAD
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
=======

}

int is_palindrome(Stack *st) {
	if(st == NULL) return 0;

	int start = 0;
	int end = st->qtd -1;
    
    while(start < end) {
        if(st->word[start].letter != st->word[end].letter) 
            return 0;
         start = start + 1;
        end = end - 1;  
    }
    return 1;
>>>>>>> 888b6efaf5cc3753b83bb90ba2474b90d99952d8
}

void FAILED_INSERT() {
	puts("Failed to insert");
}

int main() {
	Stack *st = create_stack();
<<<<<<< HEAD
	char word[30];
	printf("insert a word: ");
	scanf("%29s", word);

	size_t word_size = strlen(word);

	//empilhando
	for(size_t i = 0; i < word_size; i++) {
		Content c;
		c.letter = word[i];
		push(st, c);
	}
	
	if(!is_palindrome(st, word, word_size)) {
		puts("It is not a palindrome!");
	} else 
		puts("is palindrome!");

	free(st);

	return 0;
=======
	Content *word;
	word = malloc(30 * sizeof(Content));
	if(word == NULL) return -1;

    printf("insert a word: ");
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
    if(!is_palindrome(st)) {
        puts("it is not a palindrome!");
    } else {
        puts("is palindrome!");
    }

	free(word);
    return 0;
>>>>>>> 888b6efaf5cc3753b83bb90ba2474b90d99952d8
}
