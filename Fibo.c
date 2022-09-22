#include <stdio.h>

int main() {
  int lista[50] = {10,22,35,46,63,76,88};
  int numElementos = 7;
  int metade = (int) numElementos / 2;
  int i, x, numeroNovo;
  numeroNovo = i = x = 0;
  int inserir = 0;

  printf("Digite um numero novo que você deseja adicionar na lista: ");
  scanf("%i", &numeroNovo);

  for(i = 0; i < numElementos; i++) {
    printf("%i,", lista[i]);
  }
  printf("\n\n\n");

  for(i = 0; i <= numElementos; i++) {
    if(lista[i] > numeroNovo) {
      for(x = numElementos; x >= i; x--) {
        lista[x+1] = lista[x];
      }
      lista[i+1] = lista[i];
      lista[i] = numeroNovo;
      numElementos++;
      inserir = 1;
      break;
    }
  }

  if(inserir == 0) {
    lista[numElementos] = numeroNovo;
    numElementos++;
  }


  for(i = 0; i < numElementos; i++) {
    printf("%i,", lista[i]);
  }

  return 0;
}