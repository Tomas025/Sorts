#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

typedef int TIPO_CHAVE;

typedef struct {
  TIPO_CHAVE chave;
} REGISTRO;

typedef struct {
  REGISTRO *array;
  int numElementos;
  int max;
} PILHA;

void iniciarPilha(PILHA *pilha, int n){
  pilha -> numElementos = 0;
  pilha -> max = n;
  pilha -> array = (REGISTRO*) malloc(n * sizeof(REGISTRO));
  printf("Pilha iniciada com sucesso");
}

int verificarTamanho(PILHA *pilha, int maior, int menor) {
  if (maior >= pilha -> max) {
    return 0;
  } else if (pilha -> numElementos < (TIPO_CHAVE) menor) {
    return 1;
  } else {
    return -1;
  }
};

void redimensiona(PILHA *pilha) {
  int tempMaior = pilha -> numElementos + 2;
  int tempMenor = pilha -> numElementos * 0.66;
  int teste = verificarTamanho(pilha, tempMaior, tempMenor);
  if (teste == 0) {
    pilha -> array = (REGISTRO*) malloc((pilha -> max * 2) * sizeof(REGISTRO));
    pilha -> max = pilha -> max * 2;
  } else if (teste == 1) {
    pilha -> array = (REGISTRO*) malloc((tempMenor) * sizeof(REGISTRO));
    pilha -> max = pilha -> max * 0.66;
  }
};

void adicionarNaPilha(PILHA *pilha, REGISTRO n) {
  redimensiona(pilha);
  pilha -> array[pilha -> numElementos] = n;
  pilha -> numElementos++;
  printf("\nFoi adicionado o numero na pilha");
};

void retirarDaPilha(PILHA *pilha) {
  pilha -> numElementos--;
  printf("\nFoi retirado o ultimo numero da pilha. O numero retirado foi: ");
  redimensiona(pilha);
};

void imprimirPilha(PILHA *pilha) {
  
}

/*
iniciarPilha
adicionarNaPilha
retirarDaPilha
clear
sort
*/

int main(void) {
  PILHA teste;
  REGISTRO numteste;
  REGISTRO numteste2;
  numteste.chave = 5;
  numteste2.chave = 2;
  iniciarPilha(&teste, 5);
  adicionarNaPilha(&teste, numteste);
  adicionarNaPilha(&teste, numteste2);
  retirarDaPilha(&teste);
  return  0;
}