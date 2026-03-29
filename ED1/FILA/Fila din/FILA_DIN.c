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

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};
typedef struct fila Fila;

Fila* cria_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->final = NULL;
    }
    return fi;
}

void libera_fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no =fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_fila(Fila* fi){
    if(fi == NULL) return 0;
    int cont = 0;
    Elem *no = fi->inicio;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    
    return cont;
}

int fila_cheia(Fila* fi){
    return 0;
}

int fila_vazia(Fila* fi){
    if(fi == NULL) return -1;
    if(fi->inicio == NULL) return 1;
    else return 0;
}

int insere_fila(Fila* fi, struct aluno al){
	if(fi == NULL) return 0;
	Elem *no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL) return 0;
	no->dados = al;
	no->prox = NULL;
	if(fi->final == NULL)//fila vazia
	    fi->inicio = no;
    else    
        fi->final->prox = no;
    fi->final = no;
	return 1;
}

int remove_fila(Fila* fi){
    if(fi == NULL || fila_vazia(fi)) return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    return 1;
}

int consulta_fila(Fila* fi, struct aluno *al){
    if(fi == NULL || fila_vazia(fi)) return 0;
    *al = fi->inicio->dados;
    return 1;
}

void ERROR() {
        printf("ERRO AO ALOCAR OU FILA CHEIA\n");
}

void FILA_VAZIA() {
        printf("FILA VAZIA\n");
}

int imprime(Fila* fi) {
    if(fi == NULL || fila_vazia(fi)) return 0;

        //for(int i = fi->inicio; i < fi->qtd; (i + 1) % MAX) {
        /*int i = fi->inicio;
        while(i != fi->final) { 
                printf("matricula: %d\tnome: %s\n", fi->dados[i].matricula, fi->dados[i].nome);
                i = (i + 1) % MAX;
        }*/  
    Elem* no = fi->inicio;
	while(no != NULL) {
		printf("Aluno: %s\t\t matricula: %d\n", no->dados.nome, no->dados.matricula);
		no = no->prox;
	}
	return 1;

}

int main() {
    Fila *fi = cria_fila();

    struct aluno a1 = {123, "Willian Bonner", 8.5, 7.0, 9.0};
    struct aluno a2 = {456, "Maria Gadu", 10.0, 5.5, 3.5};
    struct aluno a3 = {789, "Luan Santana", 2.0, 4.5, 5.5};
    struct aluno a4 = {411, "Renan Santos", 1.0, 6.5, 6.5};

    if(!insere_fila(fi, a1)) {
        ERROR();
    }
    if(!insere_fila(fi, a2)) {
        ERROR();
    }
    if(!insere_fila(fi, a3)) {
        ERROR();
    }
    if(!imprime(fi)) {
        FILA_VAZIA();
    }
    if(!remove_fila(fi)) {
        FILA_VAZIA();
    }
    if(!remove_fila(fi)) {
        FILA_VAZIA();
    }
    printf("\n");
    if(!imprime(fi)) {
        FILA_VAZIA();
    }

    int TAM = tamanho_fila(fi);
    printf("Tamanho_fila = %d\n", TAM);
}

