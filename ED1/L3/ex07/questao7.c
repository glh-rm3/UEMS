/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 3
Exercício: 7
*/

/*
Faça uma função para remover os n primeiros elementos de uma lista estática. A função deve retornar
se a operação foi possível ou não.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXT 6

typedef struct {
	int data_value;
} Content;

typedef struct {
	int qtd;
	Content content[MAXT];
} List;

void clean_buffer() {
	int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

List * create_list() {
	List *li = (List *) malloc(sizeof(List));
	if(li != NULL) {
		li->qtd = 0;
	}
	return li;
}

int insert_content(List *li, Content c) {
    if(li == NULL) return 0;
    li->content[li->qtd] = c;
	li->qtd++;

    return 1;
}

int remove_n(List *li, int n) {
	if(li == NULL || li->qtd == 0) return 0;
	for(size_t i = 0; i < li->qtd-n; i++) {
		li->content[i] = li->content[i+n];
	}
	li->qtd = li->qtd - n;
	return 1;
}

int size_list(List *li) {
	if(li == NULL) return -1;
	else return (li->qtd);
}

int get_n(List *li) {
	int n;
	printf("'N' must be less than Last size and > 0: ");
	while(scanf("%d", &n) != 1 || n < 1 || n > li->qtd) {
		puts("Invalid value! Try again...");
		clean_buffer();
	}
	return n;
}	

void print(List *li) {
	puts("List:");
	for(size_t i = 0; i < li->qtd; i++) {
		printf(" %d", li->content[i].data_value);
	}
	printf("\n");
}

void MERROR() {
    puts("Memory Allocation Error!");
}

int main() {
	List *li = create_list();
	Content c0, c1, c2, c3, c4, c5;
	c0.data_value = 10;
	c1.data_value = 100;
	c2.data_value = 1000;
	c3.data_value = 10000;
	c4.data_value = 100000;
	c5.data_value = 1000000;

	if(!insert_content(li, c0)) {
		MERROR();
	}
	if(!insert_content(li, c1)) {
		MERROR();
	}
	if(!insert_content(li, c2)) {
		MERROR();
	}
	if(!insert_content(li, c3)) {
		MERROR();
	}
	if(!insert_content(li, c4)) {
		MERROR();
	}
	if(!insert_content(li, c5)) {
		MERROR();
	}
	print(li);
	printf("List size: %d\n", size_list(li));

	if(!remove_n(li, get_n(li))) puts("Failed to remove!");
	else
		puts("Successfully removed!");

	print(li);
	return 0;
}

