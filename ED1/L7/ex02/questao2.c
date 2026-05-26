/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 7
Exercício: 2

2. Escreva uma função iterativa que conta o número de nós de uma árvore binária.
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
}



/***** Recursiva *****/ 

void conta_no(struct NO* no, int *total_no) {
    if(no == NULL) return;
    
    conta_no(no->dir, total_no);
    (*total_no)++;
    conta_no(no->esq, total_no);
}

int contador(ArvBin *raiz) {
    if(raiz == NULL ||
      *raiz == NULL) {
        return 0;
    }

    int total_no =  0;
    conta_no(*raiz, &total_no);

    return total_no;
}

/***** ITERATIVO ****/   
int conta_no_iterativo(ArvBin *raiz) {
    if(raiz == NULL || 
       *raiz == NULL) {
        return 0;
    }
    
    Stack *st = create_stack();     // cria uma pilha 

    struct NO* atual = *raiz;       // atual aponta para a raiz da arvore   
    int total = 0;                  // contador 
    push(st, atual);                // empilha o ponteiro da raiz na pilha 

    while(!is_empty(st)) {          // enquanto a pilha não estiver vazia 
        atual = pop(st);            // atual recebe o item que estava na pilha, desempilhando a mesma 
        total++;                    // incrementa a cada desempilhada 
 
       if(atual->dir != NULL) {     // se a direita do meu atual for diferentenull 
            push(st, atual->dir);   // empilha atual direita 
        }
        if(atual->esq != NULL) {    // se esquerda do meu atual for diferente de null 
            push(st, atual->esq);   // empilha atual esquerda 
        }
    }

    free(st);                       // libera a pilha 
    return total;                   // retorna o total 

}

/***** END ITERATIVO *****/ 

int main() {
    ArvBin* raiz = cria_ArvBin();
    insere_ArvBin(raiz, 50);
    insere_ArvBin(raiz, 40);
    insere_ArvBin(raiz, 99);
    insere_ArvBin(raiz, 30);
    insere_ArvBin(raiz, 45);
    insere_ArvBin(raiz, 65);
    insere_ArvBin(raiz, 30);
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
    printf("\n\nTotal de no: %d\n", conta_no_iterativo(raiz));

    return 0;
}


