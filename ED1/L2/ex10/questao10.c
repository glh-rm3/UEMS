/*
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 2
Exercício: 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define arg_desc 50

typedef struct{
    int id;
    int stock;
    float sale_price;
    char product_desc[arg_desc];
} product;

void clean_buffer() {
	int buf;
	while ((buf = getchar()) != '\n' && buf != EOF);
}

int get_size() {
	int sz;
	printf("Enter N: ");
	if(scanf("%d", &sz) != 1 || sz < 1) { 
		puts("Invalid value!");
        exit(1);
    }
	return sz;
}

void alloc_product(int sz, product **arr) {
    *arr = (product *) malloc(sz * sizeof(product));
    if(*arr == NULL) {
        puts("Allocation error!");
        exit(1);
    }
}

void insert_data(int sz, product *arr) {
    for(size_t i = 0; i < sz; i++) {
        printf("Index[%zu] - Product ID: ", i+1);
        if(scanf("%d", &(arr+i)->id) != 1 || (arr+i)->id < 1) {
            printf("Invalid value!\n");
            exit(1);
        }
        clean_buffer();

        printf("Index[%zu] - Product description: ", i+1);
        fgets((arr+i)->product_desc, arg_desc, stdin);
        arr[i].product_desc[strcspn(arr[i].product_desc, "\n")] = '\0';

        printf("Index[%zu] - Stock: ", i+1);
        if(scanf("%d", &(arr+i)->stock) != 1) {
            printf("Invalid value!\n");
            exit(1);
        }
        printf("Index[%zu] - Sale price: ", i+1);
        if(scanf("%f", &(arr+i)->sale_price) != 1) {
            printf("Invalid value!\n");
            exit(1);
        }
        printf("\n");
    }
    printf("Data saved successfully!\n\n");
}

void print_higher_price(int sz, product *arr) {
    printf("== Higher selling price ==\n");
    float phigher = arr[0].sale_price;
    int pos = 0;
    for(size_t i = 0; i < sz; i++) {
        if(phigher < (arr+i)->sale_price) {
            phigher  = (arr+i)->sale_price;
            pos = i;
        }
    }
    printf("Product ID[%d]\tDescription: %s\tSale Price: %.2f\tStock: %d\n",
           (arr+pos)->id,(arr+pos)->product_desc, (arr+pos)->sale_price, (arr+pos)->stock);
}

void print_stock(int sz, product *arr) {
    printf("== Largest Stock ==\n");
    float lStock = arr[0].stock;
    int pos = 0;
    for(size_t i = 0; i < sz; i++) {
        if(lStock < (arr+i)->stock) {
            lStock = (arr+i)->stock;
            pos = i;
        }
    }
    printf("Product ID[%d]\tDescription: %s\tSale Price: %.2f\tStock: %d\n",
           (arr+pos)->id,(arr+pos)->product_desc, (arr+pos)->sale_price, (arr+pos)->stock);
}
int main() {
    product *arr;
    int sz = get_size();
    alloc_product(sz, &arr);
    insert_data(sz, arr);
    print_higher_price(sz, arr);
    print_stock(sz, arr);
    free(arr);
    return 0;
}

