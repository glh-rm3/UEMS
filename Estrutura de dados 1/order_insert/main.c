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

int insere_ordenado(Lista* li, struct aluno a) {
    if(li == NULL) puts("teste");
    if(lista_cheia(li)) return 0;
    
    int indice = 0;
    for(int i = 0; i < li->qtd; i++) {
        if(a.matricula > li->dados[i].matricula) {
               indice = li->qtd;
               printf("%d", indice);
       }
    } 
    
    for(int i = li->qtd; i < indice; i--) {
        li->dados[i] = li->dados[i - 1];
        li->dados[i] = a;
        printf("%d", a.matricula);
        li->qtd++;
    }
    puts("debug");
} 

void imprime() {
    
}

int main() {
    Lista *li = cria_lista();
    struct aluno a1 = {123, "Joao Silva", 8.5, 7.0, 9.0};
    struct aluno a2 = {456, "Maria Santos", 9.0, 8.5, 7.5};
    struct aluno a3 = {789, "Beta Santos", 9.0, 8.5, 7.5};
    struct aluno a4 = {101, "Red Santos", 9.0, 8.5, 7.5};
    struct aluno a5 = {411, "Pil Santos", 9.0, 8.5, 7.5};

    insere_ordenado(li, a4);
    
}

