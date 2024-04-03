/* -------------------------------------------------------*
9  * FATEC-São Caetano do Sul Estrutura de Dados          *
10 *                         Avaliação N1 - Parte I       *
11 * Objetivo: Controlar Estoque de produtos              *
12 *                                                      *
13 * Autores: <Bruno Tonaki & Kawai Soares>               *
14 *                                       Data:02/04/2024*
15 *------------------------------------------------------*
16 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[50];
  int codigo;
  float preco;
  int quantidade;
} Produto;

void cadastrarProduto(Produto estoque[], int *quantidadeProdutos) {
  printf("Nome do produto: ");
  scanf("%s", estoque[*quantidadeProdutos].nome);

  printf("Código do produto: ");
  scanf("%d", &estoque[*quantidadeProdutos].codigo);

  printf("Preço do produto: ");
  scanf("%f", &estoque[*quantidadeProdutos].preco);

  printf("Quantidade do produto: ");
  scanf("%d", &estoque[*quantidadeProdutos].quantidade);

  (*quantidadeProdutos)++;
}
