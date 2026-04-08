/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 3
Exercício: 17

Escreva uma função que inverte a ordem das células de uma lista encadeada (a primeira passa a ser
última, segunda passa a ser penúltima etc.). Faça isso sem usar espaço auxiliar; apenas altere os
ponteiros.
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int value;
} Content;

typedef struct Element {
	Content data;
	struct Element *prox;
} Elem, *List;

List * create_list() {
	List *li = malloc(sizeof(List));
	if(li != NULL) {
		(*li) = NULL;
	}
	return li;
}

int insert_begin(List *li, Content c) {
	if(li == NULL) return 0;
	
	Elem *node = malloc(sizeof(Elem));
	if(node == NULL) return 0;

	node->data = c;
	node->prox = (*li);
	*li = node;
	return 1;
}

int list_inverter(List *li) {
	if(li == NULL) return 0;

	Elem *anterior = NULL;
	Elem *atual = (*li); 
	Elem *proximo = NULL;   
	
	while(atual != NULL) {
		proximo = atual->prox;
		atual->prox = anterior;
		anterior = atual;
		atual = proximo;
	}	

	*li = anterior;
	return 1;
}

int print_list(List *li) {
	if(li == NULL) return 0;

	Elem *node = *li;
	while(node != NULL) {
		printf("%d\n", node->data);
    	node = node->prox;
	}
	return 1;
}

void free_list(List *li) {
	Elem *node = *li;
	while((*li) != NULL) {
		node = *li;
		*li = (*li)->prox;
		free(node);
	}
	free(li);
}

void FAILED_INSERT() {
    puts("Failed to insert!");
}

void FAILED_INVERT() {
	puts("Failed to reverse the list...");
}

int main() {
	List *li = create_list();

	Content c[4];
	
    c[0].value = 222;
    c[1].value = 444;
    c[2].value = 666;
    c[3].value = 888;

    for(size_t i = sizeof(c)/sizeof(int); i > 0; i--) {
	    if(!insert_begin(li, c[i-1])) {
			FAILED_INSERT();
			break;
       }
	}

	if(!list_inverter(li)) {
		FAILED_INVERT();
	} else {
		if(!print_list(li)) {
			puts("No data.");
		}
	}
	free_list(li);
	return 0;
}
