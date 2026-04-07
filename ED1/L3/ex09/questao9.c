/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 3
Exercício: 8
*/

/*
Faça uma função para trocar de posição dois elementos de uma lista estática. A função deve retornar
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

int print_list_pos(List *li) {
	if(li == NULL || li->qtd == 0) {
		return 0;
	}
	puts("::Current list::");
	for(size_t i = 0; i < li->qtd; i++) {
		printf("Value: %d\tPos: %d\tAddress: %p\n",
		 li->content[i].data_value, i, &li->content[i].data_value);
	}
	return 1;
}

void get_pos(int *pos_0, int *pos_1, List *li) {
	puts("Choose a position: ");
	while(scanf("%d", pos_0) != 1 || *pos_0 < 0 || *pos_0 >= li->qtd) {
		puts("Invalid value! Try again...");
		clean_buffer();
	}
	puts("Choose one more position: ");
	while(scanf("%d", pos_1) != 1 || *pos_1 < 0 || *pos_1 >= li->qtd || *pos_1 == *pos_0) {
		puts("Invalid value! Try again...");
		clean_buffer();
	}
}

int invert_pos(List *li, int *pos_0, int *pos_1) {
	if (li == NULL || *pos_0 < 0 || *pos_0 >= li->qtd || *pos_1 < 0 || *pos_1 >= li->qtd) {
        return 0; 
    }
	int swap_value = li->content[*pos_0].data_value;
	li->content[*pos_0].data_value = li->content[*pos_1].data_value;
	li->content[*pos_1].data_value = swap_value;
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
	
	int pos_0, pos_1;
	if(!print_list_pos(li)) {
		puts("Empty list!");
	} else {
		get_pos(&pos_0, &pos_1, li);
	}

	if(!invert_pos(li, &pos_0, &pos_1)) {
		puts("Unsuccessful operation!");
	} else {
		puts("Successful operation!");
	}

	if(!print_list_pos(li))
		puts("Empty list!");

    return 0;
}

