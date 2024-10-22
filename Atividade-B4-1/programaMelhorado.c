
/*-------------------------------------------------------*/
/*     FATEC-São Caetano do Sul Estrutura de Dados       */
/*             Atividade BubbleSort                      */
/*       Objetivo: Ordenar Array                         */
/*                                                       */
/*           Autores: Kawai Bonilha Soares               */
/*                                        Data:14/10/2024*/
/*-------------------------------------------------------*/

#include <stdio.h>
#include <time.h>

void trocar(int *xp, int *yp) {
int temp = *xp;
*xp = *yp;
*yp = temp;
}

void bubbleSort(int arr[], int n) {
int i, j, trocas;
for (i = 0; i < n - 1; i++) {
trocas = 0; 
for (j = 0; j < n - i - 1; j++) {
if (arr[j] > arr[j + 1]) {
trocar(&arr[j], &arr[j + 1]);
trocas = 1; 
}
}
if (trocas == 0) { 
break;
}
}
}

void imprimirArray(int arr[], int tamanho) {
int i;
for (i = 0; i < tamanho; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}

int main() {
int n, i;

printf("Digite o número de elementos: ");
scanf("%d", &n);

int arr[n];

printf("Digite os elementos do array:\n");
for (i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}

printf("Array original: \n");
imprimirArray(arr, n);

clock_t inicio = clock();

bubbleSort(arr, n);

clock_t fim = clock();

double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000;

printf("Array ordenado: \n");
imprimirArray(arr, n);

printf("Tempo gasto para ordenar: %.4f ms\n", tempo_gasto);

return 0;
}
