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

int insertionSort(int lista[], int quantElementos) {
  int i;
  int j;
  int temp;

  for (i = 1; i < quantElementos; i++) {
    for(j = i; j != 0 ; j--) {
      if(lista[j] < lista[j-1]) {
        temp = lista[j];
        lista[j] = lista[j-1];
        lista[j-1] = temp;
      }
    }
  }
}

int main() {
  // A quantidade de numeros e os numeros das listas são os mesmos mas colocados em posições diferentes (Obs.: na terceira lista não tem todos os numeros presentes nos outros dois pelo fato de repetir numeros)
  int arrayDesordenado[50] = {31, 36, 15, 33, 26, 97, 87, 14, 23, 4, 32, 25, 48, 57, 9, 93, 83, 98};
  int arrayInvertido[50] = {98, 97, 93, 87, 83, 57, 48, 36, 33, 32, 31, 26, 25, 23, 15, 14, 9, 4};
  int arrayComNumerosRepetidos[50] = {31, 31, 31, 31, 31, 31, 87, 87, 23, 23, 23, 25, 25, 57, 25, 57, 31, 87};
  
  // 4 é a quantidade de bytes de um inteiro
  int max = sizeof(arrayDesordenado) / 4; 

  // Função para saber a quantidade de elementos presentes na lista (Obs.: só chamei uma vez por que as outras são iguais)
  int numElementos = quantElementos(arrayDesordenado, max);
  int escolha;
  int escolha2;

  int condicaoParada = 1;
  int i;

  while(condicaoParada) {
    printf("Escolha um dos metodos de ordenacao de acordo com os numeros");
    printf("\n0 - Bubble Sort");
    printf("\n1 - Selection Sort");
    printf("\n2 - Insertion Sort");
    printf("\nDigite sua escolha: ");
    scanf("%i", &escolha);

    if(escolha == 0) {
      printf("\n\n--Você escolheu Bubble Sort--");
      printf("\nAgora escolha uma das opcoes para que seja ordernada, de acordo com o numero ");

      printf("\n0 - Lista Desordenado: ");
      for (i = 0; i < numElementos; i++) {
        if( i == numElementos - 1){
          printf("%i", arrayDesordenado[i]);
        } else {
          printf("%i,", arrayDesordenado[i]);
        }
      }

      printf("\n1 - Lista Invertida: ");
      for (i = 0; i < numElementos; i++) {
        if( i == numElementos - 1){
          printf("%i", arrayInvertido[i]);
        } else {
          printf("%i,", arrayInvertido[i]);
        }
      }

      printf("\n2 - Lista Com Numeros Repetidos:  ");
      for (i = 0; i < numElementos; i++) {
        if( i == numElementos - 1){
          printf("%i", arrayComNumerosRepetidos[i]);
        } else {
          printf("%i,", arrayComNumerosRepetidos[i]);
        }
      }

      printf("\n3 - As 3 listas");

      printf("\nDigite sua esolha: ");
      scanf("%i", &escolha2);

      if(escolha2 == 0) {
        printf("\n\nLista Desordenado: ");
        for (i = 0; i < numElementos; i++) {
          if( i == numElementos - 1){
            printf("%i", arrayDesordenado[i]);
          } else {
            printf("%i,", arrayDesordenado[i]);
          }
        }

        bubbleSort(arrayDesordenado, numElementos);
        for (i = 0; i < numElementos; i++) {
          if( i == numElementos - 1){
            printf("%i", arrayDesordenado[i]);
          } else {
            printf("%i,", arrayDesordenado[i]);
          }
        }
      }
    }




    printf("\n\n\n");

    for (i = 0; i < numElementos; i++) {
      printf("%i,", arrayDesordenado[i]);
    }
  }
  return 0;
}