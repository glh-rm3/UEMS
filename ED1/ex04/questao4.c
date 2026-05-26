/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 7
Exercício: 4

4. Escreva uma função para inserir um elemento em um árvore binária NÃO ordenada. Sua função deve
deixar a árvore o mais balanceada possível. Uma árvore binária NÃO ordenada, é uma árvore binária
que não é uma Árvore Binária de Busca (ABB)
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvBin;

/***** QUEUE SECTION *****/ 

typedef struct Element {
    struct NO * pointer_node;
    struct Element *next;
} Elem;

typedef struct queue {
    struct Element *start;
    struct Element *end;
} Queue;

Queue * create_queue() {
    Queue *q = malloc(sizeof(Queue));
    if(q != NULL) {
        q->start = NULL;
        q->end = NULL;
    }
    return q;
}

int enqueue(Queue *q, struct NO *pointer_tree) {
    if(q == NULL) return 0;
    Elem *node = malloc(sizeof(Elem));
    if(node == NULL) return 0;

    node->pointer_node = pointer_tree;
    node->next = NULL;

    if(q->end == NULL) {
        q->start = node;
    } else {
        q->end->next = node;
    }
    q->end = node;
    return 1;
}

int is_empty(Queue *q) {
    if(q == NULL) return -1;
    if(q->start == NULL) return 1;
    return 0;
}

struct NO * dequeue(Queue *q) {
    if (!q || !q->start) return NULL;

    Elem *temp = q->start;
    struct NO* pointer_tree = q->start->pointer_node;
    q->start = q->start->next;
    if (!q->start) q->end = NULL;
    free(temp);
    return pointer_tree;
}

int print_queue(Queue *q) {
    if(q == NULL) return 0;

    Elem *node = q->start;
    while(node != NULL) {
        printf("%p ", node->pointer_node);
        node = node->next;
    }
    printf("\n");
    return 1;
}

int free_queue(Queue *q) {
    if(q == NULL) return 0;

    Elem *node = q->start;
    while(node != NULL) {
        Elem *temp = node;
        node = node->next;
        free(temp);
    }
    free(q);
    return 1;
}

/****** END QUEUE SECTION *****/


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

/***** INSERE NAO ORDENADO - QUASE COMPLETA *****/

int insere_nao_ordenado(ArvBin* raiz, int valor) {
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*)malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;

    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    
    if(*raiz == NULL) {
        *raiz = novo;
        return 1;
    } 

    Queue *q = create_queue();
    struct NO *atual;
    enqueue(q, *raiz);

    while(!is_empty(q)) {
        atual = dequeue(q);
        if(atual->esq == NULL) {
            atual->esq = novo;
            free(q);
            return 1;
        } else {
            enqueue(q, atual->esq);
        }

        if(atual->dir == NULL) {
            atual->dir = novo;
            free(q);
            return 1;
        } else {
            enqueue(q, atual->dir);
        }
    }
    return 0;
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
    while(no2->dir != NULL) { 
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

/***** END TREE SECTION *****/

int main() {
    ArvBin* raiz = cria_ArvBin();
    insere_nao_ordenado(raiz, 50);
    insere_nao_ordenado(raiz, 40);
    insere_nao_ordenado(raiz, 99);
    insere_nao_ordenado(raiz, 30);
    insere_nao_ordenado(raiz, 45);
    insere_nao_ordenado(raiz, 65);
    insere_nao_ordenado(raiz, 79);
    insere_nao_ordenado(raiz, 80);
    insere_nao_ordenado(raiz, 54);
    insere_nao_ordenado(raiz, 74);
    insere_nao_ordenado(raiz, 20);
    insere_nao_ordenado(raiz, 3);
    insere_nao_ordenado(raiz, 1);
    insere_nao_ordenado(raiz, 7);
    insere_nao_ordenado(raiz, 28);
    insere_nao_ordenado(raiz, 500);
    insere_nao_ordenado(raiz, 250);
    insere_nao_ordenado(raiz, 73);

    imprime(raiz);
    return 0;
}

