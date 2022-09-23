#include <stdio.h>

int quantElementos(int lista[], int tamanho) {
  int contador = 0;
  int i = 0;
  for (i = 0; i <= tamanho; i++) {
    if (i != 0 && lista[i] == 0) {
      break;
    } else {
      contador += 1;
    }
  }
  return contador;
}

int bubbleSort(int lista[], int quantElementos) {
  int temp = 0;
  int i = 0;
  int j = 0;
  for (i = 1; i < quantElementos; i++) {
    for (j = 0; j < quantElementos; j++) {
      if (lista[j] > lista[i]) {
        temp = lista[j];
        lista[j] = lista[i];
        lista[i] = temp;
      }
    }
  }
  return 0;
}

int selectionSort(int lista[], int quantElementos) {
  int indexMenorNumero;
  int temp;
  int i;
  int j;

  for(i = 0; i < quantElementos; i ++) {
    indexMenorNumero = i;
    for(j = i; j < quantElementos; j++) {
      if(lista[j] < lista[indexMenorNumero]) {
        indexMenorNumero = j;
      }
    }
    if(lista[i] > lista[indexMenorNumero]) {
      temp = lista[i];
      lista[i] = lista[indexMenorNumero];
      lista[indexMenorNumero] = temp;
    }
  }
}

int select(int lista[], int quantElementos, int numero) {
  int i = 0;

  for (i = 0; i <= quantElementos; i++) {
    if (numero == lista[i]) {
      return i;
    }
  }

  return -1;
}

int binarselect(int lista[], int quantElementos, int numero) {
  int p = 0;
  int q = quantElementos;
  int metade = (int)(q - p) / 2;

  while (p < q) {
    printf("%i \n", metade);
    if (numero == lista[metade]) {
      return metade;
    } else if (numero == lista[metade - 1]) {
      metade -= 1;
    } else if (numero < lista[metade]) {
      q = metade - 1;
    } else {
      p = metade + 1;
    }

    metade = (int)(q - p) / 2;
  }

  return -1;
}

int main() {
  int array[50] = {31, 36, 15, 33, 26, 97, 87, 14, 23, 4, 32, 25, 48, 57, 9, 93, 83, 98};
  int max = sizeof(array) / 4;
  int numElementos = quantElementos(array, max);

  int i;

  for (i = 0; i < numElementos; i++) {
    printf("%i,", array[i]);
  }

  selectionSort(array, numElementos);

  printf("\n\n\n");

  for (i = 0; i < numElementos; i++) {
    printf("%i,", array[i]);
  }

  int busca;

  printf("Digite o numero que voce deseja saber a posicao no array\n");
  scanf("%i", &busca);

  int position = binarselect(array, numElementos, busca);

  if (position != -1) {
    printf("\nO numero que voce escolheu esta na posicao %i", position);
  } else {
    printf("\nO numero que voce escolheu nao esta na lista");
  }

  return 0;
}