#include <stdio.h>
#include <stdlib.h>

int main() {
    int *num = NULL, i = 0, temp_input = 1;

    while(temp_input > 0) {
        printf("Enter a number %d: ", i);
        if(scanf("%d", &temp_input) != 1) break;

        if(temp_input > 0) {
            int *temp_ptr = realloc(num, (i + 1) * sizeof(int));
            if(temp_ptr == NULL) {
                free(num);
                return 1;
            }
            num = temp_ptr;
            num[i] = temp_input;
            i++;
        }
    }

    for(int j = 0; j < i; j++) {
        printf("Pos %d: %d\n", j, num[j]);
    }

    free(num);
    return 0;
}
