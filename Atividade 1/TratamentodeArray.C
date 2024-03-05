#include <stdio.h>

int main() {
    int i, j, temp;
    int numeroInteiros[5];

    printf("Digite 5 números inteiros positivos:\n");
    for (i = 0; i < 5; i++) {
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

    printf("Números em ordem crescente:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", numeroInteiros[i]);
    }
    printf("\n");

    return 0;
}
