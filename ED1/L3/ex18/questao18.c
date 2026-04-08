/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 3
Exercício: 18

Seja uma lista dinâmica e encadeada com elementos repetidos, implemente uma rotina para eliminar
todos as ocorrências de X da lista.
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
    node->prox = (*li);
    *li = node;
    return 1;
}

int free_x_list(List *li, int x) {
	if(li == NULL || *li == NULL) return 0;
	
	Elem *anterior = NULL;
    Elem *atual = *li;
	while(atual != NULL) {
		if(atual->data.value == x) {
			Elem *alvo = atual;
			if(anterior == NULL) {
				*li = atual->prox;
			} else {
				anterior->prox = atual->prox;
			}
			atual = atual->prox;
			free(alvo);
		} else {
			anterior = atual;
			atual = atual->prox;
		}
    }
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


void FAILED_INSERT() {
    puts("Failed to insert!");
}

int main() {
	List *li = create_list();
	Content c[6];

    c[0].value = 122;
    c[1].value = 133;
    c[2].value = 144;
    c[3].value = 133;
    c[4].value = 133;
    c[5].value = 155;

	for(size_t i = sizeof(c)/sizeof(int); i > 0; i--) {
    	if(!insert_begin(li, c[i-1])) {
        	FAILED_INSERT();
            break;
       	}
    }
	
	if(!free_x_list(li, 133)) {
		puts("Unsuccessful operation");
	} else {
		print_list(li);
	}
	return 0;
}


