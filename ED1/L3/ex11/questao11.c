/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 3
Exercício: 11

Considere uma lista contendo números inteiros positivos. Faça uma função que retorne uma nova lista
contendo apenas os números pares da lista.

****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef struct {
    int value;
} Natural;

typedef struct {
    int qtd;
    Natural content[MAX];
} List;

List * create_list() {
    List *li = (List *) malloc(sizeof(List));
    if(li != NULL) {
        li->qtd = 0;
    }
    return li;
}

int insert_content(List *li, Natural *n) {
    if(li == NULL) return 0;

    for(size_t i = 0; i < MAX; i++) {
            li->content[i] = n[i];
            li->qtd++;
    }
    return 1;
}

int insert_one_content(List *li, Natural nat) {
    if(li == NULL) return 0;
    li->content[li->qtd] = nat;
    li->qtd++;
	return 1;
}

List * list_even(List *li) {
	List *list_even;
	int flag = 0;
	for(size_t i = 0; i < li->qtd; i++) {
		if(li->content[i].value % 2 == 0) {
			if(!insert_one_content(list_even, li->content[i])) {
				flag = 0;		
			} else {
				flag = 1;
			}
		}
	}

	if(!flag)
		puts("Failed to insert");
	puts("Success!");
	return list_even;
}

int print_list(List *li) {
        if(li == NULL || li->qtd == 0) {
            return 0;
        }
        puts("::List::");
        for(size_t i = 0; i < li->qtd; i++) {
                printf("Content: %d\n", li->content[i].value);
        }
        return 1;
}

int main() {
	List *li_nat = create_list();
	Natural nums[MAX];
	nums[0].value = 12;
	nums[1].value = 1;
	nums[2].value = 5;
	nums[3].value = 24;
	nums[4].value = 15;
	nums[5].value = 42;

	if(!insert_content(li_nat, nums)) {	
		puts("Failed to insert!");
    } else {
        puts("Success!");
    }
	print_list(li_nat);

	List *li_even = create_list();
	li_even = list_even(li_nat);
	print_list(li_even);

	free(li_nat);
	free(li_even);
	return 0;
}
