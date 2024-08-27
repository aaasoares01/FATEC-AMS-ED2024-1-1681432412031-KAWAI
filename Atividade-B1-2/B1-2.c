#include <stdio.h>

void caldesconto(int *preco,int *desconto,float *vf){
  
  *vf = *preco - (*preco * *desconto/100.0);
}

int preco;
int desconto;
float vf;

int main(void) {
  printf("digite o preço \n");
  scanf("%d", &preco);

  printf("digite o desconto \n");
  scanf("%d", &desconto);

  calcdesconto(&preco, &desconto, &vf);
  
  printf("preco %d\n deconto aplicado: %d%%\n  e valor final: %.2f", preco,desconto, vf);

  return 0;
}
