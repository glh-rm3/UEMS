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
    if(li != NULL) li->qtd = 0;
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
    if(li == NULL) return 0;
    if(lista_cheia(li)) return 0;
    
    int indice, i;
    i = indice = 0;
    while(i < li->qtd && a.matricula > li->dados[i].matricula)
        i++;
     
    indice = i;
    for(int i = li->qtd; i > indice; i--) {
        li->dados[i] = li->dados[i - 1];
    }
    li->dados[i] = a;
    li->qtd++;
} 

void imprime(Lista * li) {
    for(size_t i = 0; i < li->qtd; i++) {
        printf("Aluno: %s\t\t matricula: %d\t\t media %.2f\n", li->dados[i].nome, li->dados[i].matricula,
               (li->dados[i].n1 + li->dados[i].n2 + li->dados[i].n3) / 3);
    }
}

int main() {
    Lista *li = cria_lista();
    struct aluno a1 = {123, "Willian Bonner", 8.5, 7.0, 9.0};
    struct aluno a2 = {456, "Maria Gadu", 10.0, 5.5, 3.5};
    struct aluno a3 = {789, "Beta User", 2.0, 4.5, 5.5};
    struct aluno a4 = {101, "Red Pill aaaa", 6.0, 8.5, 8.5};
    struct aluno a5 = {411, "Renan Santos", 1.0, 6.5, 6.5};

    insere_ordenado(li, a1);
    insere_ordenado(li, a2);
    insere_ordenado(li, a3);
    insere_ordenado(li, a4);
    insere_ordenado(li, a5);

    imprime(li);
    printf("\nTamanho da lista: %d\n", tamanho_lista(li));    
    return 0;
}

