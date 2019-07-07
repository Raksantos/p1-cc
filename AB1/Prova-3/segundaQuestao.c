#include <stdio.h>

void ordenacao(int i, int array[], int n)
{
  if(n > 0){
    if (i < n - 1){
      if(array[i] > array[i + 1]){
        int aux = array[i];
        array[i] = array[i + 1];
        array[i + 1] = aux;
        ordenacao(i+1, array, n);
      }
      else{
        ordenacao(i+1, array, n);
      }
    }
    else{
      ordenacao(0, array, n-1);
    }
  }
}

int verificaMenor(int i, int array[], int n, int contMenor){
  if (i < n){
    if(array[0] == array[i]){
      return verificaMenor(i+1, array, n, contMenor+1);
    }
    else{
      return verificaMenor(i+1, array, n, contMenor);
    }
  }
  else{
    return contMenor;
  }
}

int verificaMaior(int i, int array[], int n, int contMaior){
  if (i < n){
    if(array[n-1] == array[i]){
      return verificaMaior(i+1, array, n, contMaior+1);
    }
    else{
      return verificaMaior(i+1, array, n, contMaior);
    }
  }
  else{
    return contMaior;
  }
}

void ler(int i, int array[], int n)
{
  if(i < n){
    scanf("%d", &array[i]);
    ler(i+1, array, n);
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  int array[n];
  ler(0, array, n);
  ordenacao(0, array, n);
  int contMenor = verificaMenor(0, array, n, 0);
  int contMaior = verificaMaior(0, array, n, 0);
  printf("Maior: %d apareceu %d vezes\nMenor: %d apareceu %d vezes\n", array[n-1], contMaior, array[0], contMenor);
  return 0;
}
