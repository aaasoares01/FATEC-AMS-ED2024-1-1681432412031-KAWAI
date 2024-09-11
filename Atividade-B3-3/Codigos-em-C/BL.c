/* -------------------------------------------
Fatec São Caetano do Sul - Estrutura de Dados
Professor: Carlos Veríssimo
Proposta: Implementação de algoritmos de busca
Autor: Kawai Bonilha Soares
Data: 09/09/2024
------------------------------------------- */

int busa_linear(int A[], int n, int x) {
  for (int i = 1; i <= n; i++) {
    if (A[i] == x)
      return i;
  }

  return -1;
}