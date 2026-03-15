#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
}; 

typedef struct elemento* Lista;

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL) return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere no inicio
        *li = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    if(lista_vazia(li)){//lista vazia: insere no inicio
        no->prox = (*li);
        *li = no;
        return 1;
    }else{//procura onde inserir
        Elem *ant, *atual = *li;
        
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){ //insere inicio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista_inicio(Lista* li){
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;//lista vazia
    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;//lista vazia
    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == (*li)) // remove o primeiro
        *li = no->prox;
    else
        ant->prox = no->prox;
    
    free(no);
    
    return 1;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL) return 0;
    Elem *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL) return 0; //nao encontrado
    
    if(no == *li)
        *li = no->prox;
    else
        ant->prox = no->prox;
    
    free(no);
    
    return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0) return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL) //nao encontrado
        return 0; 
    else
        *al = no->dados;
    
    return 1;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL) return 0;
    Elem *no = *li;
    
    while(no != NULL && no->dados.matricula != mat)
        no = no->prox;
        
    if(no == NULL) //nao encontrado
        return 0; 
    else{
        *al = no->dados;
        return 1;
    }
}

void imprime(Lista *li) {
    if(li == NULL) return;
    if((*li) == NULL) return ;//lista vazia
	
	Elem *no = *li;
	
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

    int tam;
	insere_lista_inicio(li, a1);
	insere_lista_final(li, a2);
	insere_lista_inicio(li, a3);
	insere_lista_ordenada(li, a4);
	insere_lista_ordenada(li, a5);
	imprime(li);

    tam = tamanho_lista(li);
	printf("Tamnho: %d\n", tam);
	
	int mat;
	for(size_t i = 0; i < tam; i++) {
		printf("Digite uma mat para remover: ");
		scanf("%d", &mat);
		remove_lista(li, mat);
		imprime(li);
	}
	//imprime(li);
}
