/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
}; 

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

struct descritor{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

typedef struct descritor Lista;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        li->inicio = NULL;
        li->final = NULL;
        li->qtd = 0;
    }
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem *no;
        while(li->inicio != NULL){
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL) return 0; 
    return li->qtd;
}

int insere_lista_inicio(Lista* li, struct aluno al){
	if(li == NULL) return 0;
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL) return 0;
	no->dados = al;
	no->prox = li->inicio;
	if(li->inicio == NULL)//lista vazia: insere inicio
		li->final = no;
	li->inicio = no;
	li->qtd++;
	return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
	if(li == NULL) return 0;
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL) return 0;
	no->dados = al;
	no->prox = NULL;
	if(li->inicio == NULL)//lista vazia: insere no inicio
		li->inicio = no;
	else
	    li->final->prox = no;
    li->final = no;
    li->qtd++;
	return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL || li->inicio == NULL) return 0;
    Elem *no = li->inicio;
    li->inicio = no->prox;
    free(no);
    if(li->inicio == NULL)
        li->final = NULL;
    li->qtd--;
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL || li->inicio == NULL) return 0;
    Elem *ant, *no = li->inicio;
    while(no->prox != NULL){//procura o ultimo
        ant = no;
        no = no->prox;
    }
    if(no == li->inicio){//remover o primeiro
        li->inicio = NULL;
        li->final = NULL;
    }else{
        ant->prox = no->prox;
        li->final = ant;
    }
    free(no);
    li->qtd--;
    return 1;
}

int insere_ordenado(Lista* li, struct aluno al) {
	if(li == NULL) return 0;
	Elem *no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL) return 0;

    Elem *ant, *atual = li->inicio;
	while(no != NULL && atual->dados.matricula < al.matricula){
        ant = atual;
        atual = atual->prox;
    }
    if(atual == li->inicio){ 
        atual->prox = li->inicio;
        li->final = no;
		li->qtd++;
    } else {
    	no->prox = ant->prox;
		ant->prox = no;
		li->qtd++;
    return 1;
	}
}
void imprime(Lista *li) {
	
	Elem *no = li->inicio;
	
	while(no != NULL) {
		printf("Aluno: %s\t\t matricula: %d\n", no->dados.nome, no->dados.matricula);
		no = no->prox;
	}
}

int main() {
    Lista *li = cria_lista();
    struct aluno a1 = {123, "Willian Bonner", 8.5, 7.0, 9.0};
    struct aluno a2 = {456, "Maria Gadu", 10.0, 5.5, 3.5};
    struct aluno a3 = {789, "Beta User", 2.0, 4.5, 5.5};
    struct aluno a4 = {101, "Red Pill aaaa", 6.0, 8.5, 8.5};
    struct aluno a5 = {411, "Renan Santos", 1.0, 6.5, 6.5};
	
	insere_lista_inicio(li, a1);
	insere_ordenado(li, a4);
	insere_ordenado(li, a3);
	imprime(li);
}

