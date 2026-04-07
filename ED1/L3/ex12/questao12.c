/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 3
Exercício: 12

Fazer uma função para verificar se uma lista está ordenada ou não (a ordem pode ser crescente ou
decrescente).
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct {
    int value;
} Content;

typedef struct {
    int qtd;
    Content data[MAX];
} List;

List * create_list() {
	List *li = (List*) malloc(sizeof(List));
	if(li != NULL) {
		li->qtd = 0;
	}
	return li;
}

int insert_one_content(List *li, Content c) {
	if(li == NULL) return 0;

	li->data[li->qtd] = c;
	li->qtd++;
    return 1;
}

int is_ascending(List *li) {
	if(li == NULL || li->qtd == 0) return -1;
	
	for(int i = 0; i < li->qtd -1; i++) {
		if(li->data[i].value > li->data[i+1].value) {
			return 0;
		}
	}
	return 1;
}

int is_descending(List *li) {
	if(li == NULL || li->qtd == 0) return -1;

	for(int i = 0; i < li->qtd -1; i++) {
		if(li->data[i].value < li->data[i+1].value) {
			return 0;
		}
	}
	return 1;
}

int main() {
	List *li = create_list();
	Content c[MAX];

	c[0].value = 40;
	c[1].value = 30;
	c[2].value = 20;
	c[3].value = 10;
	for(size_t i = 0; i < MAX; i++) {
		if(!insert_one_content(li, c[i])) {
			puts("Failed to insert!");
			break;
	 	}
	}

	int ret_asc = is_ascending(li);
	if(ret_asc == -1) {
		puts("The list does not exist or is empty...");
	} else if(ret_asc == 0) {
		puts("Error: List is not in ascending order");
	} else {
		puts("Success: List is in ascending order!");
	}
	
	int ret_des;
	if(ret_asc == 0) {
		ret_des = is_descending(li);
		if(ret_des == -1) {
			puts("The list does not exist or is empty...");
		} else if(ret_des == 0) {
			puts("Error: List is not in descending order");
		} else {
			puts("Success: List is in descending order!");
		}
	}

	free(li);
	return 0;
}
