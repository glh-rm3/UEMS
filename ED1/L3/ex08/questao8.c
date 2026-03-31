/*
Faça uma função para buscar a posição e o valor do maior elemento da lista estática, os quais deverão
ser retornados por referência. A função deve retornar se a operação foi possível ou não.		
*/

/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 3
Exercício: 8
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

int get_max_value(List *li, int *value, int *pos) {
	if(li == NULL || li->qtd == 0)
		return 0;

	int max_value = li->content[0].data_value;
	int max_pos = 0;
	
	for(int i = 1; i < li->qtd; i++) {
		if(li->content[i].data_value > max_value) {
			max_value = li->content[i].data_value;
			max_pos = i;
		}
	}
	*value = max_value;
	*pos = max_pos;
	return 1;
}

void MERROR() {
    puts("Memory Allocation Error!");
}

int main() {
	List *li = create_list();
	Content c0, c1, c2, c3, c4, c5;
    c0.data_value = 95;
    c1.data_value = 140;
    c2.data_value = 10;
    c3.data_value = 67;
    c4.data_value = 12;
    c5.data_value = 87;

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

	int max_value, pos;
	if(!get_max_value(li, &max_value, &pos)) {
    	puts("No reading done!");
	} else {
   		printf("Value: %d\tPos: %d\n", max_value, pos);
	}
	return 0;
}
