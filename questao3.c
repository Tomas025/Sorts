#include <stdio.h>
#include <stdlib.h>
 
void orderna(int vetor2[], int tamanho2){
    int i, j, temp = 0;
    for(i = 0; i < tamanho2; i++) {
        for(j = i; j < tamanho2; j++) {
            if(vetor2[i] > vetor2[j]) {
                temp = vetor2[j];
                vetor2[j] = vetor2[i];
                vetor2[i] = temp;
            }
        }
    }
}
 
void calculaModaImprimi(int vetor3[], int tamanho3) {
    int *repeticao = (int*) malloc (tamanho3 * sizeof(int));
    int i, j;

    for (i = 0; i < tamanho3; i++) {
        repeticao[i] = 0;
    }
 
    for (i = 0; i < tamanho3; i++) {
        for(j = i; j < tamanho3; j++) {
            if(vetor3[i] == vetor3[j]) {
                repeticao[i] = repeticao[i] + 1;
            }
        }
    }
   
    int maiorRepeticao = repeticao[0];
    int countMaiorRepeticao = 0;
    int index = 0;
 
    for (i = 0; i < tamanho3; i++) {
        if (repeticao[i] > maiorRepeticao) {
            maiorRepeticao = repeticao[i];
            index = i;
        }
    }
   
    for (i = 0; i < tamanho3; i++) {
        if (repeticao[i] == maiorRepeticao) {
            countMaiorRepeticao++;
        }
    }
 
    if (countMaiorRepeticao > 1) {
        printf("\nNao existe uma moda");
    } else {
        printf("\n%i e a moda do array", vetor3[index]);
    }
   
}
 
void imprimiMedianaModa(int vetor[], int tamanho){
    int i = 0;
    orderna(vetor, tamanho);
    int metade = (tamanho / 2);
    printf("\n");
    if(tamanho % 2 == 0) {
        float mediana;
        mediana = (vetor[metade] + vetor[metade - 1]) / 2.0;
        printf("%.2f e a mediana do array", mediana);
    } else {
        printf("%i e a mediana do array", vetor[metade]);
    }
 
    for (i = 0; i < tamanho; i++) {
    }
    calculaModaImprimi(vetor, tamanho);
}
 
 
 
int main() {
    int vetor1[10] = {5,2,1,9,8,12,45,77,58,3};
    int vetor2[10] = {1,2,3,4,6,6,7,8,9,10};
    int vetor3[11] = {5,5,7,7,1,1,4,4,3,3,3};
    int vetor4[11] = {5,2,7,9,50,12,45,77,58,3,50};
    int vetor5[11] = {1,2,3,4,8,6,7,8,9,10,11};
    int vetor6[11] = {5,5,2,2,1,1,4,4,3,5,3};

    int sizeArray = sizeof(vetor1) / sizeof(int);
    int sizeArray2 = sizeof(vetor2) / sizeof(int);
    int sizeArray3 = sizeof(vetor3) / sizeof(int);
 
    int sizeArray4 = sizeof(vetor4) / sizeof(int);
    int sizeArray5 = sizeof(vetor5) / sizeof(int);
    int sizeArray6 = sizeof(vetor6) / sizeof(int);
 
    imprimiMedianaModa(vetor1, sizeArray);
    printf("\n");
    imprimiMedianaModa(vetor2, sizeArray2);
    printf("\n");
    imprimiMedianaModa(vetor3, sizeArray3);
    printf("\n");
    imprimiMedianaModa(vetor4, sizeArray4);
    printf("\n");
    imprimiMedianaModa(vetor5, sizeArray5);
    printf("\n");
    imprimiMedianaModa(vetor6, sizeArray6);
 
    return 0;
}

