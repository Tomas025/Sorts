#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void merge(int lista[], int inicial, int metade, int final){
    int fimMonteEsquerda = 0; //Considere 0 como falso e 1 como verdadeiro, indicando se é falso ou verdadeiro que esse monte chegou ao fim
    int fimMonteDireita = 0; //Considere 0 como falso e 1 como verdadeiro, indicando se é falso ou verdadeiro que esse monte chegou ao fim
    int tamanho = final - inicial + 1;
    int topoMonteEsquerda = inicial;
    int topoMonteDireita = metade + 1;
    int *listaAuxiliar = malloc(tamanho * sizeof(int));
    int i, x = 0;
    
    if (listaAuxiliar != NULL){
        for (i = 0; i < tamanho; i++){
            if (fimMonteEsquerda == 0 && fimMonteDireita == 0){
                if (lista[topoMonteEsquerda] < lista[topoMonteDireita]){
                    listaAuxiliar[i] = lista[topoMonteEsquerda];
                    topoMonteEsquerda += 1;
                }
                else{
                    listaAuxiliar[i] = lista[topoMonteDireita];
                    topoMonteDireita += 1;
                };

                if (topoMonteEsquerda > metade){
                    fimMonteEsquerda = 1;
                }
                if (topoMonteDireita > final){
                    fimMonteDireita = 1;
                }
            }
            else if (fimMonteEsquerda == 0){
                listaAuxiliar[i] = lista[topoMonteEsquerda];
                topoMonteEsquerda += 1;
                }
                else{
                    listaAuxiliar[i] = lista[topoMonteDireita];
                    topoMonteDireita += 1;
                    }
        }
    }

    int a = inicial;
    for (x = 0; x < tamanho; x++){
        lista[a] = listaAuxiliar[x];
        a += 1;
    }
    
    free(listaAuxiliar);
}


void mergeSort(int lista[], int inicial, int final){
    if(inicial < final){
        int metade = round((final + inicial) / 2);
        mergeSort(lista, inicial, metade);
        mergeSort(lista, (metade + 1), final);
        merge(lista, inicial, metade, final);
    }
}

int main(){
    int vetor[20] = {42, 95, 97, 20, 11, 72, 93, 70, 99, 34, 82, 87, 71, 36, 75, 64, 77, 2, 51, 23};
    int tamanho = (sizeof(vetor) / sizeof(vetor[0])) - 1; //-1 pois o vetor começa seu índice no 0
    int comeco = 0;
    int a, b = 0;

    printf("Sem ordenacao: ");
    for (a = 0; a <= tamanho; a++){
        if (a == tamanho){
            printf("%i", vetor[a]);
        }
        else{
            printf("%i - ", vetor[a]);
        }
    }
    mergeSort(vetor, comeco, tamanho);

    printf("\n\nCom ordenacao: ");
    for (b = 0; b <= tamanho; b++){
        if (b == tamanho){
            printf("%i", vetor[b]);
        }
        else{
            printf("%i - ", vetor[b]);
        }
    }

    return 0;
}
