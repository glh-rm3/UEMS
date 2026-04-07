/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 3
Exercício: 16

Escreva uma função que concatena duas listas encadeadas (isto é, “amarra” a segunda no fim da
primeira) e retorna um ponteiro para a lista concatenada. As listas originais não devem ser alteradas.
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

List * create_list(){
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
	node->prox = (*li); //o proximo do meu node, é meu primeiro endereço, passei na frente
	*li = node; //node se tornou o primeiro endereço
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

List * concatenate_two_list(List *list_0, List *list_1) {

	List *cList = create_list();
	if(list_0 == NULL || list_1 == NULL) return 0;

	Elem *last = NULL;
	Elem *current = *list_0;

	while(current != NULL) {
		Elem *new = malloc(sizeof(Elem));
		new->data = current->data;
		new->prox = NULL;

		if(*cList == NULL) 
			*cList = new;
		else 
			last->prox = new;
		last = new;
		current = current->prox;
	}

	current = *list_1;

	while(current != NULL) {
		Elem *new = malloc(sizeof(Elem));
		new->data = current->data;
		new->prox = NULL;

		if(*cList == NULL)
			*cList = new;
		else
			last->prox = new;
		last = new;
		current = current->prox;
	}
	return cList;
}

void free_list(List *li) {
	if(li != NULL) {
		Elem *node;
		while((*li) != NULL) {
			node = *li;
			*li = (*li)->prox;
			free(node);
		}
	}
	free(li);
}

void FAILED_INSERT() {
    puts("Failed to insert!");
}

void ERROR_PRINT() {
	puts("Empty or non-existent list...");
}

int main() {
	List *li_0 = create_list();
	List *li_1 = create_list();
	List *li_full = create_list();

	Content for_list_0[2];
	Content for_list_1[4];

	for_list_0[0].value = 555;
	for_list_0[1].value = 777;

	for_list_1[0].value = 222;
	for_list_1[1].value = 444;
	for_list_1[2].value = 666;
	for_list_1[3].value = 888;

	for(size_t i = sizeof(for_list_0)/sizeof(int); i > 0; i--) {
		if(!insert_begin(li_0, for_list_0[i-1])) {
			FAILED_INSERT();	
			break;
		}
	}

	for(size_t i = sizeof(for_list_1)/sizeof(int); i > 0; i--) {
		if(!insert_begin(li_1, for_list_1[i-1])) {
			FAILED_INSERT();
			break;
		}
	}

	if(!print_list(li_0)) {
		ERROR_PRINT();
	}
	puts("::::");
	if(!print_list(li_1)) {
		ERROR_PRINT();
	}
	
	List * full_list = concatenate_two_list(li_0, li_1);
	puts("::::");
	if(!print_list(full_list)) {
		ERROR_PRINT();
	}

	free_list(full_list);
	free_list(li_0);
	free_list(li_1);
	return 0;
}
