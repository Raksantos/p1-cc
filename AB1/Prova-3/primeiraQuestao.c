#include <stdio.h>

int numeroPrimo(int entrada, int count)
{
    if (entrada == 1 || entrada == 0)
    {
        return 0;
    }
    else if(count > 1){
        if(entrada%count == 0)
        {
            return 0;
        }
        else
        {
            return numeroPrimo(entrada, count-1);
        }
    }
    else{
        return 1;
    }
}

void verificaNumPrimo(int* num){
  if(numeroPrimo(*num, *num - 1)){
    *num += 1;
  }
}

void loop(int i, int d1, int d2, int d3, int d4, int d5){
  if(i < 100){
    int aux1, aux2, aux3, aux4, aux5;
    scanf("%d %d %d %d %d", &aux1, &aux2, &aux3, &aux4, &aux5);
    d1 += aux1;
    d2 += aux2;
    d3 += aux3;
    d4 += aux4;
    d5 += aux5;
    if(d1 > 50){
      d1 -= 50;
      verificaNumPrimo(&d1);
      verificaNumPrimo(&d2);
      verificaNumPrimo(&d3);
      verificaNumPrimo(&d4);
      verificaNumPrimo(&d5);
      loop(i+1, d1, d2, d3, d4, d5);
    }
    else if(d2 > 50){
      d2 -= 50;
      verificaNumPrimo(&d1);
      verificaNumPrimo(&d2);
      verificaNumPrimo(&d3);
      verificaNumPrimo(&d4);
      verificaNumPrimo(&d5);
      loop(i+1, d1, d2, d3, d4, d5);
    }
    else if(d3 > 50){
      d3 -= 50;
      verificaNumPrimo(&d1);
      verificaNumPrimo(&d2);
      verificaNumPrimo(&d3);
      verificaNumPrimo(&d4);
      verificaNumPrimo(&d5);
      loop(i+1, d1, d2, d3, d4, d5);
    }
    else if(d4 > 50){
      d4 -= 50;
      verificaNumPrimo(&d1);
      verificaNumPrimo(&d2);
      verificaNumPrimo(&d3);
      verificaNumPrimo(&d4);
      verificaNumPrimo(&d5);
      loop(i+1, d1, d2, d3, d4, d5);
    }
    else if(d5 > 50){
      d5 -= 50;
      verificaNumPrimo(&d1);
      verificaNumPrimo(&d2);
      verificaNumPrimo(&d3);
      verificaNumPrimo(&d4);
      verificaNumPrimo(&d5);
      loop(i+1, d1, d2, d3, d4, d5);
    }
    else if(d1 == 50){
      printf("Maria Magda ganhou 50 reais\n");
    }
    else if(d2 == 50){
      printf("Sofia ganhou 50 reais\n");
    }
    else if(d3 == 50){
      printf("Mikasa ganhou 50 reais\n");
    }
    else if(d4 == 50){
      printf("Pedrita ganhou 50 reais\n");
    }
    else if(d5 == 50){
      printf("Leticia ganhou 50 reais\n");
    }
    else{
      verificaNumPrimo(&d1);
      verificaNumPrimo(&d2);
      verificaNumPrimo(&d3);
      verificaNumPrimo(&d4);
      verificaNumPrimo(&d5);
      loop(i+1, d1, d2, d3, d4, d5);
    }
  }
  else{
    printf("Ninguem ganhou\n");
  }
}

int main()
{
  loop(0, 1, 1, 1, 1, 1);
  return 0;
}
