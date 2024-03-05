#include <stdio.h>

int main() {
    int i, j, temp;
    int numeros[5];

    printf("Digite 5 números positivos:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &numeros[i]);
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4 - i; j++) {
            if (numeros[j] > numeros[j + 1]) {
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    printf("Números em ordem crescente:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
