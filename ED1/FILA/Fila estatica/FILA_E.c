#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
}; 

struct fila{
    int inicio, final, qtd;
    struct aluno dados[MAX];
};

typedef struct fila Fila;

Fila* cria_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_fila(Fila* fi){
    free(fi);
}

int tamanho_fila(Fila* fi){
    if(fi == NULL) return -1;
    
    return fi->qtd;
}

int fila_cheia(Fila* fi){
    if(fi == NULL) return -1;
    if(fi->qtd == MAX) return 1;
    else return 0;
}

int fila_vazia(Fila* fi){
    if(fi == NULL) return -1;
    if(fi->qtd == 0) return 1;
    else return 0;
}

int insere_fila(Fila* fi, struct aluno al){
	if(fi == NULL) return 0;
	if(fila_cheia(fi)) return 0;
	fi->dados[fi->final] = al;
	fi->final = (fi->final+1)%MAX;
	fi->qtd++;
	return 1;
}

int remove_fila(Fila* fi){
    if(fi == NULL || fila_vazia(fi)) return 0;
    fi->inicio = (fi->inicio+1) % MAX;
    fi->qtd--;
    return 1;
}


int consulta_fila(Fila* fi, struct aluno *al){
    if(fi == NULL || fila_vazia(fi)) return 0;
    *al = fi->dados[fi->inicio];
    return 1;
}

int imprime(Fila* fi) {
	if(fi == NULL || fila_vazia(fi)) return 0;

	//for(int i = fi->inicio; i < fi->qtd; (i + 1) % MAX) {
	int i = fi->inicio;
	while(i != fi->final) { 
		printf("matricula: %d\tnome: %s\n", fi->dados[i].matricula, fi->dados[i].nome);
		i = (i + 1) % MAX;
	}	
}

void ERROR() {
	printf("ERRO AO ALOCAR OU FILA CHEIA\n");
}

void FILA_VAZIA() {
	printf("FILA VAZIA\n");
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
