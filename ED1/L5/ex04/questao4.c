/***************************************************************************************************
Nome: Guilherme Henrique Ferreira de Oliveira 
Matrícula: 54883
Lista: 5
Exercício: 4

Escreva um algoritmo, usando uma Pilha, que inverte as letras de cada palavra de um texto terminado
por ponto (.) preservando a ordem das palavras. Por exemplo, dado o texto:
ESTE EXERCÍCIO É MUITO FÁCIL.
A saída deve ser:
ETSE OICÍCREXE É OTIUM LICÁF
****************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct {
	char letter;
} Content;

typedef struct stack{
	int qtd;
	Content word[MAX];
} Stack;

Stack * create_stack() {
	Stack *st = malloc(sizeof(Stack));
	if(st != NULL) {
		st->qtd = 0;
	}
	return st;
}

int is_empty(Stack *st) {
	return (st == NULL || st->qtd == 0);
}

int push(Stack *st, Content c) {
	if(st == NULL) return 0;

	st->word[st->qtd] = c;
	st->qtd++;
	return 1;
}

Content pop(Stack *st) {
	Content empty = {-1};
	if(is_empty(st)) return empty;

	st->qtd--;
	return  st->word[st->qtd];
}

int main() {
    Stack *st = create_stack();

    char phrase[32] = "ESTE EXERCICIO E MUITO FACIL.";
    size_t word_size = strlen(phrase);

    for(size_t i = 0; i < word_size; i++) { //----------------------> passa pela string
        Content c; //-----------------------------------------------> cria um content para guardar o caracter da vez 
        c.letter = phrase[i]; // -----------------------------------> o caracter da vez foi guardado 
        if(c.letter !=  ' ' && c.letter != '.') { //----------------> se o caracter for diferente de espaço e diferente de ponto, eh letra e não separador
            push(st, c); //-----------------------------------------> se eh letra, empilha, pula o else if e vai para o prox caracter 
        } else { //-------------------------------------------------> se o caracter for igual ao sepador, seja espaço ou ponto 
            while(!is_empty(st)) { //-------------------------------> enquanto minha st não for esvaziada 
                Content rt = pop(st); //----------------------------> content para receber do desempilhamento que eh feito em st 
                printf("%c", rt.letter); //-------------------------> imprimindo os caracteres desempilhados  
            }
            if(c.letter != '.') printf(" "); //---------------------> se o separador for diferente de ponto, imprime o espaço
            else printf("."); //------------------------------------> senão, imprima o ponto 
        }
    }
    printf("\n");
    free(st);
    return 0;
}

