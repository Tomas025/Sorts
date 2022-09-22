#include <stdio.h>

int quantElementos(int lista[]) {
    int contador = 0;
    int i = 0;
}

int select(int lista[], int quantElementos, int numero) {
    int i = 0;

    for(i = 0; i <= quantElementos; i++) {
        if(numero == lista[i]){
            return i;
        }
    }

    return -1;
}

int binarselect(int lista[], int quantElementos, int numero) {
    int p = 0;
    int q = quantElementos;
    int metade = (int) (q - p) / 2;

    while (p < q) {
        printf("%i \n", metade);
        if(numero == lista[metade]){
            return metade;
        } else if (numero == lista[metade-1]) {
            metade -= 1;
        } else if (numero < lista[metade]) {
            q = metade-1;
        } else {
            p = metade+1;
        }

        metade = (int) (q - p) / 2;
    }

    return -1;
}

int main() {
    int array[50] = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,60,70,80,90};
    printf("%i", sizeof(array) / 4);
    int numElementos = 20;
    int busca;

    int i;

    //

    printf("Digite o numero que voce deseja saber a posicao no array\n");
    scanf("%i", &busca);

    int position = binarselect(array,numElementos,busca);

    if (position != -1) {
        printf("\nO numero que voce escolheu esta na posicao %i", position);
    } else {
        printf("\nO numero que voce escolheu nao esta na lista");
    }

                                                    
    return 0;
}