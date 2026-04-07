/****************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 3
Exercício: 10

Considere que a struct abaixo está armazenada na sua lista estática. Faça uma função para buscar
o produto de menor preço. A função deve retornar se a operação foi possível ou não.

 struct produto {
 	int codProd ; // codigo do produto
 	char nomeProd [10]; // nome do produto
 	float valor ; // valor do produto
 	int qtdeEstoque ; // quantidade disponivel em estoque
}
*****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROD 5

typedef struct {
	int cod_prod;
	int qtd_stock;
	float price;
	char desc_prod [10];
} Product;

typedef struct {
	int qtd;
	Product data[MAX_PROD];
} List;

List * create_list() {
	List *li = (List *) malloc(sizeof(List));
	if(li != NULL) {
		li->qtd = 0;
	}
	return li;
}

int insert_content(List *li, Product *p) {
	if(li == NULL) return 0;

	for(size_t i = 0; i < MAX_PROD; i++) {
		li->data[i] = p[i];
		li->qtd++;
	}
	return 1;
}

int find_min_price(List *li) {
	if(li == NULL || li->qtd == 0) return -1;

	int index = 0;
	for(size_t i = 1; i < li->qtd; i++) {
		if(li->data[i].price < li->data[index].price) {
			index = i;
		}
	}
	return index;
}

int main() {
	List *li = create_list();
	Product prod[MAX_PROD];
	prod[0].cod_prod = 1142;
	prod[0].qtd_stock = 4;
	prod[0].price = 32.5;
	strcpy(prod[0].desc_prod, "Keyboard");

	prod[1].cod_prod = 1145;
	prod[1].qtd_stock = 5;
	prod[1].price = 54;
	strcpy(prod[1].desc_prod, "Headset");

	prod[2].cod_prod = 1167;
	prod[2].qtd_stock = 7;
	prod[2].price = 1200;
	strcpy(prod[2].desc_prod, "Laptop");

	prod[3].cod_prod = 1177;
	prod[3].qtd_stock = 2;
	prod[3].price = 24;
	strcpy(prod[3].desc_prod, "Webcam");

	prod[4].cod_prod = 1189;
	prod[4].qtd_stock = 1;
	prod[4].price = 350;
	strcpy(prod[4].desc_prod, "Monitor");

	if(!insert_content(li, prod)) {
		puts("Failed to insert!");
	} else {
		puts("Success!");
	}

	int index = find_min_price(li);
	if(index == -1) {
		puts("No prices to consult...");
	} else {
		printf("Index %d\n", index);
		printf("Product ID: %d\n", prod[index].cod_prod);
		printf("Product Description: %s\n", prod[index].desc_prod);
		printf("Lowest Price: R$ %.2f\n", prod[index].price);
		printf("Available stock: %d\n", prod[index].qtd_stock);
	}
	
	free(li);
	return 0;
}
