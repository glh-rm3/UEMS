/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 7
Exercício: 18

18. Escreva funções não recursivas para realizar os 3 tipos de percurso na árvore binária (dica: use uma
pilha):
(a) pré-ordem
(b) em-ordem
(c) pós-ordem
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvBin;

/***** STACK *****/ 

typedef struct stack {
    struct NO * pointer_node;
    struct stack *prox;
} *Stack, Elem;

Stack * create_stack() {
	Stack *st = malloc(sizeof(Stack));
	if(st != NULL) {
		*st = NULL;
	}
	return st;
}

int is_empty(Stack *st) {
    if(st == NULL)  return 1;
    if(*st == NULL) return 1;
    return 0;
}

int push(Stack *st, struct NO* pointer_tree) {
	if(st == NULL) return 0;

    Elem *node = malloc(sizeof(Elem));
    if(node == NULL) return 0;

	node->pointer_node = pointer_tree;
	node->prox = (*st);
    *st = node;
	return 1;
}

struct NO * pop(Stack *st) {
	if(is_empty(st)) return NULL;

    Elem *node = *st;
    struct NO* c = node->pointer_node;
    *st = node->prox;
	free(node);
	return c;
}

/***** END STACK SECTION *****/

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

int insere_recursivo(ArvBin *raiz, int valor) {
    if(raiz == NULL) return 0;


    if(*raiz == NULL) {
        struct NO* novo;
        novo = malloc(sizeof(struct NO));
        if(novo == NULL) return 0;

        novo->info = valor;
        novo->dir = NULL;
        novo->esq = NULL; 

        *raiz = novo;
        return 1;
    }

    if(valor == (*raiz)->info) {
        return 0;
    }

    if(valor < (*raiz)->info) {
        return insere_recursivo(&((*raiz)->esq), valor);
    } else {  
        return insere_recursivo(&((*raiz)->dir), valor);
    }
}   

int consulta_recursivo(ArvBin *raiz, int valor) {
    if(*raiz == NULL) return 0;
    struct NO* atual = *raiz;

    if(valor == (*raiz)->info) 
        return 1;
    
    if(valor > (*raiz)->info)
        return consulta_recursivo(&((*raiz)->dir), valor);
    else
        return consulta_recursivo(&((*raiz)->esq), valor);
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

int remove_recursivo(ArvBin *raiz, int valor) {
    if(raiz == NULL) return 0;
    struct NO* atual = *raiz;

    if(*raiz == NULL) return 0;

    if(valor == atual->info) {
        *raiz = remove_atual(atual);
        return 1;
    }

    if(valor > atual->info)
        return remove_recursivo(&((*raiz)->dir), valor);
    else
        return remove_recursivo(&((*raiz)->esq), valor);

}

void preOrdem_Iterativo(ArvBin *raiz) {
    if(raiz == NULL || *raiz == NULL) return;
    
    Stack *st = create_stack();
    push(st, *raiz);

    while(!is_empty(st)) {
        struct NO *atual = pop(st);
        printf("%d\n", atual->info);

        if(atual->dir != NULL) push(st, atual->dir);
        if(atual->esq != NULL) push(st, atual->esq);
    }
    
    free(st); 
}
void emOrdem_Iterativo(ArvBin *raiz) {
    if(raiz == NULL || *raiz == NULL) return;
    
    Stack *st = create_stack();
    struct NO *atual = *raiz;

    while(atual != NULL || !is_empty(st)) {
        while(atual != NULL) {
            push(st, atual);
            atual = atual->esq;
        }
        atual = pop(st);
        printf("%d\n", atual->info);
        atual = atual->dir;
    }
    
    free(st);
}

void posOrdem_Iterativo(ArvBin *raiz) {
    if(raiz == NULL || *raiz == NULL) return;
    
    Stack *st = create_stack();
    struct NO *atual = *raiz;
    struct NO *ultimoVisitado = NULL;

    while(atual != NULL || !is_empty(st)) {
        if (atual != NULL) {
            push(st, atual);
            atual = atual->esq;
        } else {
            struct NO *topo = pop(st);
            if (topo->dir != NULL && topo->dir != ultimoVisitado) {
                 push(st, topo);  
                 atual = topo->dir; 
            } else {
                printf("%d\n", topo->info);
                ultimoVisitado = topo;
            }
        }
    }
    
    free(st);
}


int main() {
    ArvBin* raiz = cria_ArvBin();
    insere_recursivo(raiz, 50);
    insere_recursivo(raiz, 40);
    insere_recursivo(raiz, 99);
    insere_recursivo(raiz, 30);
    insere_recursivo(raiz, 45);
    insere_recursivo(raiz, 65);
    insere_recursivo(raiz, 79);
    insere_recursivo(raiz, 80);
    insere_recursivo(raiz, 54);
    insere_recursivo(raiz, 74);
    insere_recursivo(raiz, 20);
    insere_recursivo(raiz, 3);
    insere_recursivo(raiz, 1);
    insere_recursivo(raiz, 7);
    insere_recursivo(raiz, 28);
    insere_recursivo(raiz, 500);
    insere_recursivo(raiz, 250);
    insere_recursivo(raiz, 73);

    imprime(raiz);
    printf("\nPre ordem: \n");
    preOrdem_Iterativo(raiz);
    printf("\nEm ordem: \n");
    emOrdem_Iterativo(raiz);
    printf("\nPos Ordem: \n");
    posOrdem_Iterativo(raiz);

    return 0;
}

