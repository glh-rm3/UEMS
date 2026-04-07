/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 3
Exercício: 13

Fazer uma função que copia uma lista L1 em outra L2, eliminando os elementos repetidos.

****************************************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>

#define MAX 5


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
		li->qtd;
	}
	return li;
}

int print_list(List *);
int copy_list_overwrite_duplicate(List *, List *);

int insert_content(List *li, Content c) {
	if(li == NULL) return 0;

	li->data[li->qtd] = c;
	li->qtd++;
	return 1;
}

int verify_duplicates(List *l1, List *l2) {
	if(l1 == NULL || l1->qtd == 0 || l2 == NULL || l2->qtd == 0) return 0;
	
	List *temp = create_list();
	if(temp == NULL) return 0;
	for(int i = 0; i < l1->qtd; i++) {
		int is_duplicate = 0;
		for(int j = 0; j < l2->qtd; j++) {
			if(l1->data[i].value == l2->data[j].value) {
				is_duplicate = 1;
				break;
			}
		}
		if(!is_duplicate) {
			temp->data[temp->qtd].value = l1->data[i].value;
			temp->qtd++;
		}
	}

	if(copy_list_overwrite_duplicate(temp, l2)) {
		puts("List L2 successfully overwritten!");
		free(temp);
		return 1;
	} else {
		free(temp);
		return 0;
	}
}

int copy_list_overwrite_duplicate(List *temp, List *l2) {
	if(temp == NULL || l2 == NULL || temp->qtd == 0 || l2->qtd == 0) return 0;
	for(int i = 0; i < temp->qtd; i++) {
		l2->data[i] = temp->data[i];
	}
	l2->qtd = temp->qtd;
	return 1;
}

int print_list(List *li) {
        if(li == NULL || li->qtd == 0) {
            return 0;
        }
        puts("::List::");
        for(size_t i = 0; i < li->qtd; i++) {
                printf("Content: %d\n", li->data[i].value);
        }
        return 1;
}

void MERROR() {
    puts("Memory Allocation Error!");
}

int main() {
	List *l1 = create_list();
	Content c[MAX];
	c[0].value = 15;	
	c[1].value = 30;	
	c[2].value = 45;	
	c[3].value = 60;	
	c[4].value = 75;

	for(int i = 0; i < MAX; i++) {
		if(!insert_content(l1, c[i])) {
			MERROR();
			break;
		}
	}
	printf("L1:\n");
	print_list(l1);
	List *l2 = create_list();
	Content d[MAX];
	d[0].value = 30;
	d[1].value = 80;
	d[2].value = 75;
	d[3].value = 90;
	d[4].value = 15;	

	for(int i = 0; i < MAX; i++) {
		if(!insert_content(l2, d[i])) {
			MERROR();
			break;
		}
	}

	printf("L2:\n");
	print_list(l2);

	if(!verify_duplicates(l1, l2)) {
		puts("Verification error!");
	} else {
		puts("Operation successful!");
	}

	printf("L2:\n");
	print_list(l2);
	free(l1);
	free(l2);
	return 0;
}
