/*
Faça uma função para concatenar duas listas estáticas em uma terceira lista estática que deverá ser
retornada pela função. Não use funções já implementadas.
*/

/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 3
Exercício: 6
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
	int content_value;
} Content;

typedef struct {
	int qtd;
	Content value[MAX];
} List;
	
typedef struct {
	int qtd;
	Content value[MAX*2];
} Full_list;

List * create_list() {
	List *li = (List*) malloc(sizeof(List));
	if(li != NULL) {
		li->qtd = 0;
	}
	return li;
}	

int insert_content(List *li, Content c) {
	if(li == NULL) return 0;
	size_t i;	
	for(i = li->qtd; i > 0; i--) {
		li->value[i] = li->value[i-1];
	}
	
	li->value[i] = c;
	li->qtd++;
	return 1;
}

Full_list * Concatenate_List(List * li_0, List * li_1) {
	Full_list *fl = (Full_list *) malloc(sizeof(Full_list));
	if(fl != NULL) {
		fl->qtd = 0;
	}

	for(size_t i = 0; i < li_0->qtd; i++) {
		fl->value[fl->qtd] = li_0->value[i];
		fl->qtd++;
	}
	
	for(size_t j = 0; j < li_1->qtd; j++) {
		fl->value[fl->qtd] = li_1->value[j];
		fl->qtd++;
	}

	return fl;
}

void printf_Full_list(Full_list *fl) {
	if(fl == NULL) return;

	printf("Full List:");
	for(size_t i = 0; i < fl->qtd; i++) {
		printf(" %d ", fl->value[i].content_value);
	}
	printf("\n");
}

void merror() {
	puts("Memory Allocation Error!");
}

int main() {
	List *li_0 = create_list();
	List *li_1 = create_list();

	Content c0;
	Content c1;
	Content c2;
	Content c3;
	Content c4;
	Content c5;

	c0.content_value = 5;
	c1.content_value = 10;
	c2.content_value = 15;
	c3.content_value = 20;
	c4.content_value = 25;
	c5.content_value = 30;
	
	if(!insert_content(li_0, c0)) {
		merror();
	}
	if(!insert_content(li_0, c1)) {
		merror();
	}	
	if(!insert_content(li_0, c2)) {
		merror();
	}
	if(!insert_content(li_1, c3)) {
		merror();
	}
	if(!insert_content(li_1, c4)) {
		merror();
	}
	if(!insert_content(li_1, c5)) {
		merror();
	}

	Full_list *fl = Concatenate_List(li_0, li_1);
	printf_Full_list(fl);
	return 0;
}	
