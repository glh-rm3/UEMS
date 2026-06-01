/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 7
Exercício: 9    

10. Escreva uma função que retorna verdadeiro se uma árvore binária é uma árvore binária de busca e
falso caso contrário.
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvBin;


/***** TREE *****/  
ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);
    free(raiz);
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int altura_ArvBin(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

int totalNO_ArvBin(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1); 
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0; // elemento ja existe
            }
            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

struct NO* remove_atual(struct NO* atual){
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2 ->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int remove_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL) return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
        }
    return 1;
}

int consulta_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL) return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info)
            return 1;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

void imprimeNO(struct NO* no, int nivel) {
        if(no == NULL) return;
        imprimeNO(no->dir, nivel + 1);
        for(int i = 0; i < nivel; i++) {
                printf("   ");
        }

        printf("%d\n", no->info);
        imprimeNO(no->esq, nivel + 1);
}
 
void imprime(ArvBin *raiz) {
    if(raiz == NULL || *raiz == NULL) {
        printf("Arvore vazia\n");
        return;
    }
    imprimeNO(*raiz, 0);
    printf("\n\n");
}

int arv_bin(struct NO* atual, int MIN, int MAX) {
    if(atual == NULL) return 1;

    // Se o valor do nó atual estourar os limites permitidos, não é árvore de busca!
    if (atual->info <= MIN || atual->info >= MAX) {
    return 0;
    }

    // Esquerda: o máximo vira o valor atual. Direita: o mínimo vira o valor atual.
    return arv_bin(atual->esq, MIN, atual->info) && arv_bin(atual->dir, atual->info, MAX);
}

int verifica_arvore_bin_busca(ArvBin *raiz) {
    if(raiz == NULL || *raiz == NULL) {
        printf("Arvore inexistente!");
        return -1;
    }

    struct NO* atual = *raiz;
    
    return arv_bin(atual, INT_MIN, INT_MAX);
}

int main() {
    ArvBin* raiz = cria_ArvBin();
    insere_ArvBin(raiz, 50);
    insere_ArvBin(raiz, 40);
    insere_ArvBin(raiz, 99);
    insere_ArvBin(raiz, 30);
    insere_ArvBin(raiz, 45);
    insere_ArvBin(raiz, 65);
    insere_ArvBin(raiz, 79);
    insere_ArvBin(raiz, 80);
    insere_ArvBin(raiz, 54);
    insere_ArvBin(raiz, 74);
    insere_ArvBin(raiz, 20);
    insere_ArvBin(raiz, 3);
    insere_ArvBin(raiz, 1);
    insere_ArvBin(raiz, 7);
    insere_ArvBin(raiz, 28);
    insere_ArvBin(raiz, 500);
    insere_ArvBin(raiz, 250);
    insere_ArvBin(raiz, 73);

    imprime(raiz);
    
    if(verifica_arvore_bin_busca(raiz)) {
        printf("Arvore de busca binaria!\n");
        printf("-------------------------------------\n");
    } else {
        printf("Nao eh arvore de busca binaria.\n");
        printf("-------------------------------------\n");
    }

    struct NO* no_bugado = *raiz;
    no_bugado = no_bugado->dir->dir->esq; // Caminha até o 250 (50 -> 99 -> 500 -> 250)
    no_bugado->info = 45;                 // Força o valor inválido

    imprime(raiz);  

    if(verifica_arvore_bin_busca(raiz)) {
        printf("Arvore de busca binaria!\n");
        printf("-------------------------------------\n");
    } else {
        printf("Nao eh arvore de busca binaria.\n");
        printf("-------------------------------------\n");
    }
    return 0;
}

