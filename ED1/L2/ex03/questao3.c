#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clean_buffer() {
	int buf;
	while ((buf = getchar()) != '\n' && buf != EOF);
}

int get_size(unsigned int *sz) {
	printf("Enter a size: ");
	if(scanf("%u", sz) != 1) return -1;
	clean_buffer();
	return 0;
}

void alloc_string(char **str, unsigned int *size) {
	*str = (char *) malloc(*size * sizeof(char));
	if(*str == NULL) return;
}

void get_content(char *str, unsigned int *size) {
	printf("Write a string: ");
	fgets(str, *size, stdin);
}

void print_string(char *str, unsigned int *size) {
	const char *vg = "aeiouAEIOU";
	char *aux = (char *) malloc(*size +1 * sizeof(char));
	if(aux == NULL) return;
	int k = 0;
	for(size_t i = 0; i < *size && *(str+i) != '\0'; i++) {
		int vogal = 0;
		for(size_t j = 0; j < strlen(vg); j++) {
			if(*(str+i) == *(vg+j)) {
				vogal = 1;
				break;
			}
		}
		if(!vogal) {
			*(aux+k) = *(str+i);
			k++;
		}
	}
	*(aux+k) = '\0';
	printf("%s\n", aux);
	free(aux);
}

int main() {
	unsigned int size;
	char *str;
	int vsize = get_size(&size);
	if(vsize != 0) {
		puts("Falha ao ler o tamanho!");
		exit(1);
	}
	
	alloc_string(&str, &size);
	get_content(str, &size);
	print_string(str, &size);
	free(str);
	return 0;
}
