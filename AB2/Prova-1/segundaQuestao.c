#include <stdio.h>

void ler(int i, int array[], int n)
{
  if(i < n){
    scanf("%d", &array[i]);
    ler(i+1, array, n);
  }
}

int calculaTunelSaida(int array[], int n, int i, int contador)
{
  if(array[i] != -1){
    i = array[i];
    return calculaTunelSaida(array, n, i, contador + 1);
  }
  else{
    return i;
  }
}

int main()
{
  int n, tunelInicial;
  scanf("%d", &n);
  int array[n];
  ler(0, array, n);
  scanf("%d", &tunelInicial);
  printf("%d\n", calculaTunelSaida(array, n, tunelInicial, 0));
  return 0;
}
