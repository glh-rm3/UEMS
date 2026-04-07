/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 3
Exercício: 14

Escreva uma função que crie uma lista encadeada a partir de um vetor.
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int value;
} Content;

typedef struct Element {
	Content data;
	struct Element *prox;
} Elem, *List; //apelido e apelido ponteiro

List * create_list() {
	List *li = (List*) malloc(sizeof(List));
	if(li != NULL)
	*li = NULL;
	return li;
}

int print_list(List *);

int insert_begin(List *li, int arr_num) {
	if(li == NULL) return 0;
	Elem *node = (Elem*) malloc(sizeof(Elem));
	if(node == NULL) return 0;

	Content c;
	c.value = arr_num;

	node->data = c;
	node->prox = (*li);
	*li = node;

	return 1;
}

int print_list(List *li){
	if(li == NULL) return 0;
	if((*li) == NULL) return 0;//lista vazia
	
	Elem *node = *li;

	puts("::List::");
	while(node != NULL) {
		printf("%d\n", node->data.value);
		node = node->prox;
	}
	return 1;
}

void free_list(List *li) {
    if(li != NULL) {
        Elem *node;
        while((*li) != NULL) {
            node = *li;
            *li = (*li)->prox;
            free(node);
        }
        free(li);
    }
}

int main() {
	List *li = create_list();
	int vet[5] = { 5, 25, 15, 35, 100};

	for(size_t i = sizeof(vet)/sizeof(int); i > 0; i--) {
		if(!insert_begin(li, vet[i-1])) {
			puts("Failed to insert!");
			break;
		}
	}

	if(!print_list(li)) {
		puts("Empty or non-existent list...");
	}
	free_list(li);

	return 0;
}
