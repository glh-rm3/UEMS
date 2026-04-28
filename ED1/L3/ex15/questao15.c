/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 3
Exercício: 15

 Escreva uma função que copie uma lista encadeada para um vetor.
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int value;
} Content;

typedef struct Element {
	Content data;
	struct Element *prox;
} Elem, *List; // Item Elem para criar um nó, e ponteiro List

List * create_list() {
	List *li = malloc(sizeof(List));
	if(li != NULL)
		*li = NULL;
	return li;
}

// Insere no ínicio dinâmicamente
int insert_begin(List *li, Content c) {
	if(li == NULL) return 0; 
	Elem *node = malloc(sizeof(Elem)); // cria um nó para guardar o item 
	if(node == NULL) return 0; // verifica se o nó foi alocado corretamente 

	node->data = c; // nó data recebe Content 
	node->prox = (*li);	 // o proximo do meu nó, é o antigo primeiro
	*li = node; // então o primeiro item da lista, agora aponta para nó, pois *li recebe o endereço de node
	return 1;
}

// Função para verificar o tamanho da lista
int size_list(List *li) {
	if(li == NULL) return 0;
	int cont = 0; // criado um contador
	Elem *node = *li; // cria um nó apontando para o primeiro item da lista
	
	while(node != NULL) { // forma de "caminhar" na lista, até chegarmos no final, já que o prox do último elemento é NULL
		cont++; // contador incrementa 
		node = node->prox; // node caminha até o último elemento 
	}
	return cont; // retorna o valor do contador 
}

void free_list(List *li) {
	if(li != NULL) {
		Elem *node;
		while((*li) != NULL) { /**** (*li) eh o inicio  ***/  
			node = *li;        /***  node segura o *li  ***/ 
			*li = (*li)->prox; /*** primeiro passou a ser o prox ***/ 
			free(node);		   /*** limpamos o node, endrc que ficou para trás ***/  
		}
		free(li);
	}
}

// Função que insere itens da lista no vetor 
int insert_vector(List *li, int *vector) {
	if(li == NULL) return 0;
	
	int i = 0;
	Elem *node = *li; // cria um no apontando para a primeira posição da lista
	while(node != NULL) { // percorrer toda a lista
		vector[i] = node->data.value; // vector[i] = node->data.value, do nó atual 
		node = node->prox; // nó caminha para o próximo para preenchermos o vetor 
		i++; // incrementa i para não sobrescrever 
	}
	return 1;
}

// impressão comum do vetor, apenas para não poluir mais o main
void print_vector(int *vector, size_t TAM){
	for(size_t i = TAM; i > 0; i--) { 
		printf("%d\n", vector[i-1]);
	}
}

void FAILED_INSERT() {
	puts("Failed to insert!");
}

int main() {
	List *li = create_list();

	if(!insert_begin(li, (Content) {135})) {
		FAILED_INSERT();
	}
	if(!insert_begin(li, (Content) {235})) {
		FAILED_INSERT();
	}
	if(!insert_begin(li, (Content) {335})) {
		FAILED_INSERT();
	}
	if(!insert_begin(li, (Content) {435})) {
		FAILED_INSERT();
	}
	
	//puts("DEBUG");
	size_t TAM = size_list(li); // atribui o tamanho da lista para o TAM, que será o tamanho do nosso vetor
	int vector[TAM];
	if(!insert_vector(li, vector)) {
		FAILED_INSERT();
	} else {
		print_vector(vector, TAM);
	}
		
	free_list(li);
	return 0;
}
