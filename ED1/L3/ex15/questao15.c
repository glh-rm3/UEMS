/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 3
Exercício: 15

 Escreva uma função que copie uma lista encadeada para um vetor.
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
	if(li != NULL)
		*li = NULL;
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

int size_list(List *li) {
	if(li == NULL) return 0;
	int cont = 0;
	Elem *node = *li;
	while(node != NULL) {
		cont++;
		node = node->prox;
	}
	return cont;
}

void free_list(List *li) {
	if(li != NULL) {
		Elem *node;
		while((*li) != NULL) { /**** (*li) eh o inicio  ***/  
			node = *li;        /***  node segura o *li  ***/ 
			*li = (*li)->prox; /*** primeiro passou a ser o prox ***/ 
			free(node);		   /*** limpamos o node, endrc que ficou para trás ***/  
		}
		free(li);
	}
}

int insert_vector(List *li, int vector[]) {
	if(li == NULL) return 0;
	
	int i = 0;
	Elem *node = *li;
	while(node != NULL) {
		vector[i] = node->data.value;
		node = node->prox;
		i++;
	}
	return 1;
}

void print_vector(int vector[], size_t TAM){
	for(size_t i = TAM; i > 0; i--) {
		printf("%d\n", vector[i-1]);
	}
}

void FAILED_INSERT() {
	puts("Failed to insert!");
}

int main() {
	List *li = create_list();
	Content c0, c1, c2, c3;
	c0.value = 135;	
	c1.value = 235;	
	c2.value = 335;	
	c3.value = 435;	

	if(!insert_begin(li, c0)) {
		FAILED_INSERT();
	}
	if(!insert_begin(li, c1)) {
		FAILED_INSERT();
	}
	if(!insert_begin(li, c2)) {
		FAILED_INSERT();
	}
	if(!insert_begin(li, c3)) {
		FAILED_INSERT();
	}
	
	//puts("DEBUG");
	size_t TAM = size_list(li);
	int vector[TAM];
	if(!insert_vector(li, vector)) {
		FAILED_INSERT();
	} else {
		print_vector(vector, TAM);
	}
		
	free_list(li);
	return 0;
}
