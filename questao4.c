#include <stdio.h>
#include <stdlib.h>
 
void printar(int *a, int colunas, int linhas) {
    int i, j, k = 0;
    int teste;
    int count = 0;
    int count2 = 0;
    int paginas = (colunas * linhas) / 100;
    for (i = 0; i < paginas; i++) {
        while(count < colunas & count2 < linhas) {
            for(j = 0 + count2; j < 50 + count2; j++) {
                if(j == 0 + count2) {
                    for ( k = 0 + count; k < 20 + count; k++) {
                        if(k == 0 + count) {
                            printf("\n");
                            printf("        COL %i", k);
                        } else if (k > 9) {
                            printf("   COL %i", k);
                        } else {
                            printf("   COL %i", k);
                        }
                    }
                }
                
                if (j == linhas) {
                    break;
                }
                    printf("\nROW %i", j);

               
                for(k = 0 + count; k < 20 + count; k++) {
                    if (k > colunas) {
                        break;
                    }
                    if (j > 9) {
                        if( k == 0 + count) {
                            printf("    %i", *((a + j * colunas) + k));
                        } else {
                            printf("       %i", *((a + j * colunas) + k));
                        }
                    } else {
                        if( k == 0 + count) {
                            printf("     %i", *((a + j * colunas) + k));
                        } else {
                            printf("       %i", *((a + j * colunas) + k));
                        }
                    }
                }
            }
            count = count + 20;
            if (count < colunas) {
                continue;
            } else {
                count = 0;
                count2 = count2 + 50;
            }
        }
    }
 
    scanf("%i", teste);
}
 
int main() {
    int m = 100;
    int n = 100;
    int array[m][n];
    int i, j;
 
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            array[i][j] = j;
        }
    }
 
    array[0][0] = 1;
 
    printar((int *)array, m, n);
    return 0;
 
}
