/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Atendimento hospitalar através de FILA             */
/*                                                                          */
/*                                                       Data:18/03/2024    */
/*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct No {
    int dado;
    struct No* proximo;
};

void inserirNaListaLigada(struct No** cabecaRef, int valorInserir, int posicao) {
    struct No* novoNo = (struct No*) malloc(sizeof(struct No));
    novoNo->dado = valorInserir;
    
    if (posicao == 0) {
        novoNo->proximo = *cabecaRef;
        *cabecaRef = novoNo;
        return;
    }

    struct No* noAtual = *cabecaRef;
    for (int i = 0; noAtual != NULL && i < posicao - 1; i++) {
        noAtual = noAtual->proximo;
    }

    if (noAtual == NULL || noAtual->proximo == NULL) {
        novoNo->proximo = NULL;
        noAtual->proximo = novoNo;
        return;
    }

    novoNo->proximo = noAtual->proximo;
    noAtual->proximo = novoNo;
}

void imprimirLista(struct No* no) {
    while (no != NULL) {
        printf("%d ", no->dado);
        no = no->proximo;
    }
    printf("\n");
}

int main() {
    struct No* cabeca = NULL;
    struct No* segundo = NULL;
    struct No* terceiro = NULL;
    struct No* quarto = NULL;

    cabeca = (struct No*) malloc(sizeof(struct No));
    segundo = (struct No*) malloc(sizeof(struct No));
    terceiro = (struct No*) malloc(sizeof(struct No));
    quarto = (struct No*) malloc(sizeof(struct No));

    cabeca->dado = 10;
    cabeca->proximo = segundo;

    segundo->dado = 25;
    segundo->proximo = terceiro;

    terceiro->dado = 40;
    terceiro->proximo = quarto;

    quarto->dado = 80;
    quarto->proximo = NULL;

    int valorInserir = 30;
    int posicao = 2;

    clock_t tempoInicio, tempoFim;
    double tempoGasto;

    tempoInicio = clock();
    inserirNaListaLigada(&cabeca, valorInserir, posicao);
    tempoFim = clock();

    tempoGasto = ((double) (tempoFim - tempoInicio)) / CLOCKS_PER_SEC;

    printf("Lista após inserção: ");
    imprimirLista(cabeca);
    printf("Tempo de execução: %f segundos\n", tempoGasto);

    return 0;
}
