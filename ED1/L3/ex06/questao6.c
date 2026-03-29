#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
	fl->value[fl->qtd] = li_0->value[j];
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
	if(li == NULL) return -1;
	
	for(size_t i = li->qtd; i > 0; i--) {
		li->value[i] = li->value[i-1];
	}
	
	li->value[i] = c;
	li->qtd++;
	return 0;
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

int main() {
	List *li_0 = create_list();
	List *li_1 = create_list();

	Content c1 = {45};
	Content c1 = {90};
	
	if(!insert_content(li_0, c1) {
		
	}

	Full_list *fl = Concatenate_List(li_0, li_1);
	return 0;
}	
