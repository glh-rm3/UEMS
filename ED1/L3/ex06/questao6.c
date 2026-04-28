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

// estrutura para o conteúdo da lista
typedef struct {
	int content_value;
} Content;

// estrutura para a lista
typedef struct {
	int qtd;
	Content value[MAX];
} List;

// estrutura para a lista concatenada
typedef struct {
	int qtd;
	Content value[MAX*2]; // quando concatenada, teremos duas lista em um espaço de memória, logo MAX*2
} Full_list;

// função de criação de lista 
List * create_list() {
	List *li = (List*) malloc(sizeof(List)); // aloca memória dinamicamente para a estrutura da lista
	if(li != NULL) { 						 // verifica se a alocação foi bem-sucedida antes de acessar os dados 
		li->qtd = 0; 						 // inicializa a quantidade de elementos em 0
	}
	return li;	// retorna o ponteiro para a lista criada
}	

// está cheia? 
int is_full(List *li) {
	if(li == NULL) return -1; 
	return (li->qtd == MAX); // retorna 0 se for falso e 1 se verdadeiro 
}

// inserção de conteúdo na lista - Insere no ínicio 
int insert_content(List *li, Content c) {
	if(li == NULL || is_full(li)) return 0;  // se li == NULL ou estiver cheia.
	
	for(int i = li->qtd; i > 0; i--) { // seja uma lista [5] [9] [ ] [ ] [ ] [ ] ..., i = 2, enquanto i > 0, i decrementa
		li->value[i] = li->value[i-1]; // li->value[2] = value[1], ficando [5] [9] [9]
									   // li->value[1] = value[0], ficando [5] [5] [9]
									   // para o loop, resultando em [5] [5] [9]
	}
	
	li->value[0] = c; // insere o novo elemento na primeira posição
	li->qtd++; 		  // incrementa o qtd
	return 1;
}

// função de concatenação - talvez eu refatore isso 
Full_list * Concatenate_List(List * li_0, List * li_1){
	if(li_0 == NULL || li_1 == NULL) return NULL;

	Full_list *fl = (Full_list *) malloc(sizeof(Full_list)); // já criei a lista concatenada aqui mesmo 
	if(fl == NULL) return NULL;

	fl->qtd = 0;
	for(size_t i = 0; i < li_0->qtd; i++) {  // percorrer até li_0->qtd 
		fl->value[fl->qtd] = li_0->value[i]; // fl->value[0] = li_0->value[0] e assim por diante
		fl->qtd++; // qtd incrementa
	}
	
	for(size_t j = 0; j < li_1->qtd; j++) { // percorrer até l1_->qtd
		fl->value[fl->qtd] = li_1->value[j]; // mesma ideia do for de cima, mas qtd não inicia zerado; ele pega o caminho andado
		fl->qtd++; // qtd incrementa 
	}

	return fl; // retorna ponteiro de fl 
}

// função para impressão da lista concatenada 
void printf_Full_list(Full_list *fl) {
	if(fl == NULL) return;

	printf("Full List:");
	for(size_t i = 0; i < fl->qtd; i++) { // percorre todos os elementos de fl
		printf(" %d ", fl->value[i].content_value); // impressão comum do tipo inteiro para o campo value
	}
	printf("\n");
}

void ierror() {
	puts("null or full list!");
}

int main() {
	// criando as duas listas 
	List *li_0 = create_list(); 
	List *li_1 = create_list();

	// estes ifs são apenas para validar se teve memória. Sinceramente, preciso deixar isso mais elegante. 
	
	if(!insert_content(li_0, (Content){5})) {
	    ierror();
	}
	
	if(!insert_content(li_0, (Content){10})) {
	    ierror();
	}
	
	if(!insert_content(li_0, (Content){15})) {
	    ierror();
	}
	
	if(!insert_content(li_1, (Content){20})) {
	    ierror();
	}
	
	if(!insert_content(li_1, (Content){25})) {
	    ierror();
	}
	
	if(!insert_content(li_1, (Content){30})) {
	    ierror();
	}
	
	Full_list *fl = Concatenate_List(li_0, li_1); // chama a função de concatenação 
	printf_Full_list(fl); // chama a função de impressão
	return 0;
}	
