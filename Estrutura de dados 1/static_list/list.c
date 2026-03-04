#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct aluno{
    
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

typedef struct lista Lista;

Lista* cria_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

int tamanho_lista(Lista* li){
    if(li == NULL) return -1;
    else return(li->qtd);
}

int lista_cheia(Lista* li){
    if(li == NULL) return -1;
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li){
    if(li == NULL) return -1;
    return (li->qtd == 0);
}

int insere_final(Lista* li, struct aluno a){
    if(li == NULL) return 0;
    if(lista_cheia(li)) return 0;
    
    li->dados[li->qtd] = a;
    li->qtd++;
    
    return 1;
}

int insere_inicio(Lista* li, struct aluno a){
    if(li == NULL || lista_cheia(li)) return 0;
    
    for(int i = li->qtd; i>0; i--)
        li->dados[i] = li->dados[i-1];
    
    li->dados[0] = a;
    li->qtd++;
    
    return 1;
}

int remove_final(Lista* li){
    if(li == NULL || li->qtd ==0) return 0;
    li->qtd--;
    
    return 1;
}

int remove_inicio(Lista *li){
    if(li == NULL || li->qtd ==0) return 0;
    for(int i = 0; i < li->qtd-1; i++)
        li->dados[i] = li->dados[i+1];
    li->qtd--;
    return 1;
    
}

int busca_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos<= 0 || pos > li->qtd) return 0;
        
    *al = li->dados[pos-1];
        
    return 1;
}

int busca_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL) return 0;
        
    int i = 0;
        
    while(i< li->qtd && li->dados[i].matricula != mat)
        i++;
            
    if(i == li->qtd) // elemento nao encontrado
        return 0;
        
    *al = li->dados[i];
        
    return 1;
}

void libera_lista(Lista* li){
    if(li != NULL)
        free(li);
}

int main(){
	Lista* li = cria_lista();
	struct aluno a1 = {123, "Joao Silva", 8.5, 7.0, 9.0};
	struct aluno a2 = {456, "Maria Santos", 9.0, 8.5, 7.5};
			
	insere_final(li, a1);
	insere_final(li, a2);
			
	struct aluno res;
	if(busca_mat(li, 456, &res)) 
		printf("Aluno: %s\n", res.nome);
	libera_lista(li);
	return 0;
} 
