#include <stdio.h>

void ler(int i, int array[], int n)
{
  if(i < n){
    scanf("%d", &array[i]);
    ler(i+1, array, n);
  }
}

int calculaPosicao(int n, int posicaoArray)
{
  if(posicaoArray >= n){
    posicaoArray -= n;
    return calculaPosicao(n, posicaoArray);
  }
  else {
    return posicaoArray;
  }
}

int criancaVencedora(int i, int array[], int n, int posicaoArray)
{
  if(i < n){
    if(i == 0 || posicaoArray == 0){
      posicaoArray += (array[i] - 1);
      if(posicaoArray >= n){
        posicaoArray = calculaPosicao(n + 1, posicaoArray);
        return criancaVencedora(i + 1, array, n, posicaoArray);
      }
      else{
        return criancaVencedora(i + 1, array, n, posicaoArray);
      }
    }
    else{
      posicaoArray += array[i];
      if(posicaoArray >= n){
        posicaoArray = calculaPosicao(n, posicaoArray);
        return criancaVencedora(i + 1, array, n, posicaoArray);
      }
      else{
        return criancaVencedora(i + 1, array, n, posicaoArray);
      }
    }
  }
  else{
    return posicaoArray;
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  int array[n - 1];
  ler(0, array, n - 1);
  printf("%d\n", criancaVencedora(0, array, n - 1, 0));
  return 0;
}
