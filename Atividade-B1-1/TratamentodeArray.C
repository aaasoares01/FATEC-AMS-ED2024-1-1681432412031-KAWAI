#include <stdio.h>

int main() {
    int i, j, temp;
    int numeroInteiros[5];

    printf("Insira 5 números inteiros:\n");
    for (i = 0; i < 5; i++) {
        printf("Número %d: ", i +  1);
        scanf("%d", &numeroInteiros[i]);
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4 - i; j++) {
            if (numeroInteiros[j] > numeroInteiros[j + 1]) {
                temp = numeroInteiros[j];
                numeroInteiros[j] = numeroInteiros[j + 1];
                numeroInteiros[j + 1] = temp;
            }
        }
    }
    printf("\n");   
  
    printf("Números ordenados em crescente:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", numeroInteiros[i]);
    }

    return 0;
}
