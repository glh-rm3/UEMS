/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 7
Exercício: 18

20. Monte uma árvore capaz de armazenar uma struct contendo as seguintes datarmações: nome do
município, área total do município (em km2) e a população. A árvore deverá ter funções para inserir
(pelo nome), percorrer e listar. Implemente também funções para:
(a) Contar o número de municípios, percorrendo os nos cadastrados na árvore
(b) Mostrar apenas os nomes dos municípios com mais de X habitantes. Por exemplo, X pode ser
100.000 pessoas.
(c) Mostrar a densidade demográfica de cada cidade. A densidade demográfica é a relação entre a
população e a área.
(d) Mostrar o somatório de área em km2 de todas as cidades juntas em relação ao território nacional
(em porcentagem).
(e) Mostrar as cidades em ordem alfabética, com todos os dados.
(f) Mostrar o nome da cidade com a maior população.

****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cidade {
    char nome_municipio[64];
    float area_totalkm2;
    int populacao;
    int id;
};

struct NO {
    struct cidade data;    
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvBin;

typedef struct Element {
	struct NO *cadastro;
	struct Element *prox;
} Elem, *List; // Item Elem para criar um nó, e ponteiro List

List * create_list() {
	List *li = malloc(sizeof(List));
	if(li != NULL)
		*li = NULL;
	return li;
}

// Insere no ínicio dinâmicamente
int insert_begin(List *li, struct NO *c) {
	if(li == NULL) return 0; 
	Elem *node = malloc(sizeof(Elem)); // cria um nó para guardar o item 
	if(node == NULL) return 0; // verifica se o nó foi alocado corretamente 

	node->cadastro = c; // nó data recebe Content 
	node->prox = (*li);	 // o proximo do meu nó, é o antigo primeiro
	*li = node; // então o primeiro item da lista, agora aponta para nó, pois *li recebe o endereço de node
	return 1;
}

// Função para verificar o tamanho da lista
int size_list(List *li) {
	if(li == NULL) return 0;
	int cont = 0; // criado um contador
	Elem *node = *li; // cria um nó apontando para o primeiro item da lista
	
	while(node != NULL) { // forma de "caminhar" na lista, até chegarmos no final, já que o prox do último elemento é NULL
		cont++; // contador incrementa 
		node = node->prox; // node caminha até o último elemento 
	}
	return cont; // retorna o valor do contador 
}

void free_list(List *li) {
	if(li != NULL) {
		Elem *node;
		while((*li) != NULL) { /**** (*li) eh o inicio  ***/  
			node = *li;        /***  node segura o *li  ***/ 
			*li = (*li)->prox; /*** primeiro passou a ser o prox ***/ 
			free(node);		   /*** limpamos o node, endrc que ficou para trás ***/  
		}
		free(li);
	}
}

int print_list(List *li) {
	if(li == NULL) return 0;
	
	Elem *node = *li;
	while(node != NULL) {
        puts("=========================================");
		printf("id: %d\n", node->cadastro->data.id);
		printf("cidade: %s\n", node->cadastro->data.nome_municipio);
		printf("populacao: %d\n", node->cadastro->data.populacao);
		printf("area em km2: %f\n", node->cadastro->data.area_totalkm2);
		node = node->prox;
	}
	return 1;
}

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

        printf("%d\n", no->data.id);
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

int insere_recursivo(ArvBin *raiz, struct cidade cad, int cod) {
    if(raiz == NULL) return 0;


    if(*raiz == NULL) {
        struct NO* novo;
        novo = malloc(sizeof(struct NO));
        if(novo == NULL) return 0;

        novo->data = cad;
        novo->dir = NULL;
        novo->esq = NULL; 

        *raiz = novo;
        return 1;
    }

    if(cod == (*raiz)->data.id) {
        return 0;
    }

    if(cod < (*raiz)->data.id) {
        return insere_recursivo(&((*raiz)->esq), cad, cod);
    } else {  
        return insere_recursivo(&((*raiz)->dir), cad, cod);
    }
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

int remove_recursivo(ArvBin *raiz, struct cidade novo, int cod) {
    if(raiz == NULL) return 0;
    struct NO* atual = *raiz;

    if(*raiz == NULL) return 0;

    if(cod == atual->data.id) {
        *raiz = remove_atual(atual);
        return 1;
    }

    if(cod > atual->data.id)
        return remove_recursivo(&((*raiz)->dir), novo, cod);
    else
        return remove_recursivo(&((*raiz)->esq), novo, cod);

}

void conta_no(struct NO* no, int *total_no) {
    if(no == NULL) return;
    
    conta_no(no->dir, total_no);
    (*total_no)++;
    conta_no(no->esq, total_no);
}

int quantos_municipios(ArvBin *raiz) {
    if(raiz == NULL ||
      *raiz == NULL) {
        return 0;
    }

    int total_no =  0;
    conta_no(*raiz, &total_no);

    return total_no;
}

void populacao_maior_50k(struct NO* no) {
    if(no == NULL) return; 
    
    if(no->data.populacao > 50000) {
        printf("\n%s | populacao: %d\n", no->data.nome_municipio, no->data.populacao);
    }
    
    populacao_maior_50k(no->esq);
    populacao_maior_50k(no->dir);  
}

void densidade_geografica(struct NO* no) {
    if(no == NULL) return;

    float densidade = (float)no->data.populacao / no->data.area_totalkm2;
    printf("%s   | Densidade geografica: %2.f\n", no->data.nome_municipio, densidade);

    densidade_geografica(no->esq);
    densidade_geografica(no->dir);
}

float soma_territorio(struct NO* no) {
    if(no == NULL) return 0;

    return no->data.area_totalkm2 + soma_territorio(no->esq) + soma_territorio(no->dir);
}

int consulta_recursivo(ArvBin *raiz, int cod) {
    if(*raiz == NULL) return 0;
    struct NO* atual = *raiz;

    if(cod == (*raiz)->data.id) 
        return 1;
    
    if(cod > (*raiz)->data.id)
        return consulta_recursivo(&((*raiz)->dir), cod);
    else
        return consulta_recursivo(&((*raiz)->esq), cod);
}

void listando(List *li, struct NO* no) {
    if(no == NULL) return;
    
    insert_begin(li, no);
    listando(li, no->esq);
    listando(li, no->dir);
}

int order_list(List *li) {
    if(li == NULL || *li == NULL) return 0;

    int trocou = 1;
    Elem* atual;
    Elem* ultimo = NULL;

    while(trocou) {
        trocou = 0;
        atual = *li;

        while(atual->prox != ultimo) {
            if(strcmp(atual->cadastro->data.nome_municipio, atual->prox->cadastro->data.nome_municipio) > 0) {
                struct NO* temp = atual->cadastro;
                atual->cadastro = atual->prox->cadastro;
                atual->prox->cadastro = temp;

                trocou = 1;
            }
            atual = atual->prox;
        }
        ultimo = atual;
    }
    return 1;
}

int exibe_ordem_alfabetica(ArvBin *raiz) {
    if(raiz == NULL) return 0;
    
    struct NO* no = *raiz;
    List *li = create_list();
    listando(li, no);
    order_list(li);
    print_list(li);
    free_list(li);
    return 1;
}

struct NO* busca_maior_populacao(struct NO* no) {
    if (no == NULL) return NULL;

    struct NO* max_atual = no;

    struct NO* max_esq = busca_maior_populacao(no->esq);
    struct NO* max_dir = busca_maior_populacao(no->dir);

    if (max_esq != NULL && max_esq->data.populacao > max_atual->data.populacao) {
        max_atual = max_esq;
    }

    if (max_dir != NULL && max_dir->data.populacao > max_atual->data.populacao) {
        max_atual = max_dir;
    }

    return max_atual;
}

void exibe_maior_populacao(ArvBin *raiz) {
    if(raiz == NULL || *raiz == NULL) {
        printf("Arvore vazia.\n");
        return;
    }

    struct NO* campeao = busca_maior_populacao(*raiz);

    if(campeao != NULL) {
        printf("Cidade com maior populacao: %s (%d habitantes)\n", 
                campeao->data.nome_municipio, 
                campeao->data.populacao);
    }
}

int main() {
    ArvBin* raiz = cria_ArvBin();
    insere_recursivo(raiz, (struct cidade) {"Nova Andradina", 4776.0, 44170, 67}, 67); 
    insere_recursivo(raiz, (struct cidade) {"Maringa", 487.912, 409657, 41}, 41); 
    insere_recursivo(raiz, (struct cidade) {"Curitiba", 435.406, 1773718, 24}, 24); 
    insere_recursivo(raiz, (struct cidade) {"Xique-xique", 5079.0, 44757, 29}, 29); 
    insere_recursivo(raiz, (struct cidade) {"Londrina", 1647.7, 555965, 70}, 70); 
    insere_recursivo(raiz, (struct cidade) {"Jardim", 2130.0, 23981, 50}, 50);

    imprime(raiz);
    puts("--------------------------------------------------");
    printf("Total de %d municipios\n\n", quantos_municipios(raiz));
    struct NO* busca;
    busca = *raiz;
    puts("--------------------------------------------------");
    puts("populacao maior que 50k: ");
    populacao_maior_50k(busca);
    puts("--------------------------------------------------");
    puts("densidade geografica: ");
    densidade_geografica(busca);
    puts("--------------------------------------------------");
    float somatorio_territorio = soma_territorio(busca);
    printf("Somatorio dos territorios: %f\n", somatorio_territorio);
    puts("--------------------------------------------------");

    float area_brasil = 8509360.85;
    printf("O somatorio do territorio abrange %.2f%% do territorio brasileiro\n", (somatorio_territorio*100)/area_brasil);
    puts("--------------------------------------------------");
    printf("Exibe em ordem alfabetica: \n");
    exibe_ordem_alfabetica(raiz);
    puts("--------------------------------------------------");
    exibe_maior_populacao(raiz);

    return 0;
}

