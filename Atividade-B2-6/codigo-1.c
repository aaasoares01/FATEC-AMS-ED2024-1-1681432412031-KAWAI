/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Atendimento hospitalar através de FILA             */
/*                                                                          */
/*   Autor: Kawai Bonilha Soares                         Data:18/03/2024    */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <time.h>

void inserirNoArray(int array[], int tamanhoAtual, int valorInserir, int posicao) {
    for (int i = tamanhoAtual; i > posicao; i--) {
        array[i] = array[i - 1];
    }
    array[posicao] = valorInserir;
}

int main() {
    int array[6] = {10, 25, 40, 80};
    int tamanhoAtual = 4;
    int valorInserir = 30;
    int posicao = tamanhoAtual / 2;

    clock_t tempoInicio, tempoFim;
    double tempoGasto;

    tempoInicio = clock();
    inserirNoArray(array, tamanhoAtual, valorInserir, posicao);
    tempoFim = clock();

    tempoGasto = ((double) (tempoFim - tempoInicio)) / CLOCKS_PER_SEC;

    printf("Array após inserção: ");
    for (int i = 0; i <= tamanhoAtual; i++) {
        printf("%d ", array[i]);
    }
    printf("\nTempo de execução: %f segundos\n", tempoGasto);

    return 0;
}
