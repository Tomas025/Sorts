#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int TIPO_CHAVE;

typedef struct {
  TIPO_CHAVE chave;
} REGISTRO;

typedef struct {
  REGISTRO *array;
  int numElementos;
  int max;
} PILHA;

void iniciarPilha(PILHA *pilha, int n) {
  pilha->numElementos = 0;
  pilha->max = n;
  pilha->array = (REGISTRO *)malloc(n * sizeof(REGISTRO));
  printf("Pilha iniciada com sucesso");
}

void limparPilha(PILHA *pilha) {
  pilha->numElementos = 0;
  printf("\nA pilha foi limpa");
}

int verificarTamanho(PILHA *pilha, int maior, int menor) {
  if (maior >= pilha->max) {
    return 0;
  } else if (pilha->numElementos < (TIPO_CHAVE)menor) {
    return 1;
  } else {
    return -1;
  }
};

void redimensiona(PILHA *pilha) {
  int tempMaior = pilha->numElementos + 2;
  int tempMenor = pilha->numElementos * 0.66;
  int teste = verificarTamanho(pilha, tempMaior, tempMenor);
  if (teste == 0) {
    int i = 0;
    int tempArray[pilha->numElementos + 1];
    for (i = 0; i <= pilha->numElementos; i++) {
      tempArray[i] = pilha->array[i].chave;
    }
    free(pilha->array);
    pilha->array = (REGISTRO *)malloc((pilha->max * 2) * sizeof(REGISTRO));
    pilha->max = pilha->max * 2;
    for (i = 0; i <= pilha->numElementos; i++) {
      pilha->array[i].chave = tempArray[i];
    }
  } else if (teste == 1) {
    pilha->array = (REGISTRO *)malloc((tempMenor) * sizeof(REGISTRO));
    pilha->max = pilha->max * 0.66;
  }
};

void adicionarNaPilha(PILHA *pilha, REGISTRO n) {
  redimensiona(pilha);
  pilha->array[pilha->numElementos] = n;
  pilha->numElementos++;
  printf("\nFoi adicionado um numero na pilha");
};

void retirarDaPilha(PILHA *pilha) {
  if (pilha->numElementos != 0) {
    pilha->numElementos--;
    printf("\nFoi retirado o ultimo numero da pilha");
    redimensiona(pilha);
  } else {
    printf("\nNão tem nenhum elemento na pilha");
  }
};

void imprimirPilha(PILHA *pilha) {
  if (pilha->numElementos != 0) {
    int i = 0;
    int j = pilha->numElementos - 1;
    for (i = 0; j >= i; j--) {
      printf("\n%i", pilha->array[j].chave);
    }
  } else {
    printf("\nNão tem nenhum elemento na pilha");
  }
} //=)

// void merge(PILHA *pilha, int inicial, int metade, int final){
//     int fimMonteEsquerda = 0; //Considere 0 como falso e 1 como verdadeiro, indicando se é falso ou verdadeiro que esse monte chegou ao fim
//     int fimMonteDireita = 0; //Considere 0 como falso e 1 como verdadeiro, indicando se é falso ou verdadeiro que esse monte chegou ao fim
//     int tamanho = final - inicial + 1;
//     int topoMonteEsquerda = inicial;
//     int topoMonteDireita = metade + 1;
//     int *listaAuxiliar = malloc(tamanho * sizeof(REGISTRO));
//     int i, x = 0;
    
//     if (listaAuxiliar != NULL){
//         for (i = 0; i < tamanho; i++){
//             if (fimMonteEsquerda == 0 && fimMonteDireita == 0){
//                 if (pilha -> array[topoMonteEsquerda] < pilha -> array[topoMonteDireita]){
//                     listaAuxiliar[i] = pilha -> array[topoMonteEsquerda];
//                     topoMonteEsquerda += 1;
//                 }
//                 else{
//                     listaAuxiliar[i] = pilha -> array[topoMonteDireita];
//                     topoMonteDireita += 1;
//                 };

//                 if (topoMonteEsquerda > metade){
//                     fimMonteEsquerda = 1;
//                 }
//                 if (topoMonteDireita > final){
//                     fimMonteDireita = 1;
//                 }
//             }
//             else if (fimMonteEsquerda == 0){
//                 listaAuxiliar[i] = pilha -> array[topoMonteEsquerda];
//                 topoMonteEsquerda += 1;
//                 }
//                 else{
//                     listaAuxiliar[i] = pilha -> array[topoMonteDireita];
//                     topoMonteDireita += 1;
//                     }
//         }
//     }

//     int a = inicial;
//     for (x = 0; x < tamanho; x++){
//         pilha -> array[a] = listaAuxiliar[x];
//         a += 1;
//     }
    
//     free(listaAuxiliar);
// }


// void mergeSort(PILHA *pilha, int inicial, int final){
//     if(inicial < final){
//         int metade = round((final + inicial) / 2);
//         mergeSort(pilha, inicial, metade);
//         mergeSort(pilha, (metade + 1), final);
//         merge(pilha, inicial, metade, final);
//     }
// }


int main(void) {
  PILHA teste;
  REGISTRO numteste;
  REGISTRO numteste2;
  numteste.chave = 5;
  numteste2.chave = 2;
  iniciarPilha(&teste, 5);
  adicionarNaPilha(&teste, numteste);
  imprimirPilha(&teste);
  adicionarNaPilha(&teste, numteste2);
  imprimirPilha(&teste);
//  mergeSort(&teste, 0, teste.numElementos);
//  imprimirPilha(&teste);
  retirarDaPilha(&teste);
  imprimirPilha(&teste);
  limparPilha(&teste);
  imprimirPilha(&teste);
  return 0;
}