/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Exercícios envolvendo ponteiros e arrays           */
/*             Paradigama: Programação Modular                              */
/*                                                                          */
/*                                                       Data:18/03/2024    */
/*--------------------------------------------------------------------------*/

#include <stdio.h>
#define TAMANHO_ARRAY 5

// Programa 1
float encontrarMaiorElemento(float *array) {
    float maior = *array;
    for (int i = 1; i < TAMANHO_ARRAY; i++) {
        if (*(array + i) > maior) {
            maior = *(array + i);
        }
    }
    return maior;
}
// --------------------------------------------------------------


// Programa 2
float calcularSoma(float *array) {
    float soma = 0;
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        soma += *(array + i);
    }
    return soma;
}
// --------------------------------------------------------------


// Programa 3
void imprimirArray(float *array) {
    printf("Array: ");
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("%.2f ", *(array + i));
    }
    printf("\n");
}
// --------------------------------------------------------------


// Programa 4
void modificarArray(float *array, float multiplicador) {
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        *(array + i) *= multiplicador;
    }
}
// --------------------------------------------------------------


int main() {
    float notas[TAMANHO_ARRAY];

    printf("Insira as %d notas:\n", TAMANHO_ARRAY);
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
  
    // Resultado do programa 1
    printf("Maior elemento: %.2f\n", encontrarMaiorElemento(notas));
    // --------------------------------------------------------------

  
    // Resultado do programa 2
    printf("Soma dos elementos: %.2f\n", calcularSoma(notas));
    // --------------------------------------------------------------

  
    // Resultado do programa 3
    imprimirArray(notas);
    // --------------------------------------------------------------

    // Resultado do programa 4
    float multiplicador;
    printf("Digite o valor pelo qual multiplicar o array: ");
    scanf("%f", &multiplicador);
    modificarArray(notas, multiplicador);
    printf("Array modificado: \n");
    imprimirArray(notas);

    return 0;
}
