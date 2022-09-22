#include <stdio.h>

int fibo(int a) {
  if(a == 1) {
    return 1;
  } else if(a == 2) {
    return 1;
  } else {
    return fibo(a-1) + fibo(a-2);
  }
}

int fibo2(int x) {
  int y = 0;
  int z = 1;
  int temp;

  int i = 0;
  
  if(x == 1) {
    printf("0");
    return 0;
  } else if(x == 2) {
    printf("0,1,");
    return 0;  
  } else {
    printf("0,1,");
  }

  for(i=0; i <= x; i++) {
    printf("%i,", y + z);
    temp = y;
    z += y;
    y = z - temp;
  }  
}

int main() {

  int x = 5;
  int i = 0;
  int p = 0;

  printf("Digite a casa do valor de fibonati você deseja saber o valor interno: ");
  scanf("%i", &p);
  
  for(i = 1; i <= 8; i++) {
    printf("%i,", fibo(i));
  }

  fibo2(p);
  
  return 0;
}