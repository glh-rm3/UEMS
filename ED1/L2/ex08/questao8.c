#include <stdio.h>
#include <stdlib.h>

int get_size() {
	int sz;
	printf("Enter a size: ");
	if(scanf("%u", &sz) != 1 || sz < 10)
		puts("Invalid value!");
	return sz;
}

void alloc(int sz, int **arr){
	int *arr =  (int *) malloc(sz * sizeof(double));
	if(*arr == NULL) {
		puts("Allocation error!");
		exit(1);
	}
}

void attribution(int *arr) {
		
}

int main() {
	int *arr;
	alloc(get_size(), &arr);
	attribution(arr);	
	return 0;
} 


