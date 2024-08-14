/* ----------------------------------------------------------------**
 * FATEC-São Caetano do Sul Estrutura de Dados *
 * Atividade B3-1-Cálculo tempo execuçao-Insertion Sort *
 * Autor: Kawai Bonilha Soares * * Data:13/08/2024 *
 * --------------------------------------------------------------*/

// 10t(n) + 10t(n²) + 2t

#include <stdio.h>

int * insertion_sort(int arr[], int n) { // t
    for(int j = 1; j < n; j++) {         // 3t(n) 
        int key = arr[j];                // 2t(n)
        int i = j - 1;                   // 2t(n)
        while(i >= 0 && arr[i] > key) {  // 4t(n²)
            arr[i + 1] = arr[i];         // 4t(n²)
            i -= 1;                      // 2t(n²)
        }
        arr[i + 1] = key;                // 3t(n)
    }
    return arr;                          // t
}



void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main(void) {
    int A[] = {10, 21, 5, 12, 6};
    print_array(insertion_sort(A, 5), 5);
}
