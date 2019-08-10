#include <stdio.h>

int posicaoComecar(int i, int arrayAux[], int n)
{
  if(i < n){
    if(arrayAux[i] != 1){
      return i;
    }
    else{
      return posicaoComecar(i + 1, arrayAux, n);
    }
  }
  else{
    return n;
  }
}

void lerAux(int i, int array[], int n)
{
  if(i < n){
    if(i == 0){
      array[i] = 1;
      lerAux(i + 1, array, n);
    }
    array[i] = 0;
    lerAux(i + 1, array, n);
  }
}

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

int criancaVencedora(int i, int array[], int n, int posicaoArray, int arrayAux[])
{
  if(i < n){
    if(i == 0 || posicaoArray == 0){
      if(arrayAux == 0){
        arrayAux[i] = 1;
        posicaoArray += (array[i] - 1);
        if(posicaoArray >= n){
          posicaoArray = calculaPosicao(n + 1, posicaoArray);
          return criancaVencedora(i + 1, array, n, posicaoArray, arrayAux);
        }
        else{
          return criancaVencedora(i + 1, array, n, posicaoArray, arrayAux);
        }
      }
      else{
        posicaoArray += (array[i] - 1);
        if(posicaoArray >= n){
          posicaoArray = calculaPosicao(n + 1, posicaoArray);
          return criancaVencedora(i + 1, array, n, posicaoArray, arrayAux);
        }
        else{
          return criancaVencedora(i + 1, array, n, posicaoArray, arrayAux);
        }
      }
    }
    else{
      if(arrayAux[i] == 0){
        arrayAux[i] = 1;
        posicaoArray += array[i];
        if(posicaoArray >= n){
          posicaoArray = calculaPosicao(n, posicaoArray);
          return criancaVencedora(i + 1, array, n, posicaoArray, arrayAux);
        }
        else{
          return criancaVencedora(i + 1, array, n, posicaoArray, arrayAux);
        }
      }
      else{
        array[i] = posicaoComecar(i, arrayAux, n);
        posicaoArray += array[i];
        if(posicaoArray >= n){
          posicaoArray = calculaPosicao(n, posicaoArray);
          return criancaVencedora(i + 1, array, n, posicaoArray, arrayAux);
        }
        else{
          return criancaVencedora(i + 1, array, n, posicaoArray, arrayAux);
        }
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
  int array[n - 1], arrayAux[n - 1];
  ler(0, array, n - 1);
  lerAux(0, arrayAux, n - 1);
  printf("%d\n", criancaVencedora(0, array, n - 1, 0, arrayAux));
  return 0;
}
