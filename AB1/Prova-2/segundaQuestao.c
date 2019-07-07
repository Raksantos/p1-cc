#include <stdio.h>

int verificaImpar(int num)
{
  if (num == 1){
    return 1;
  }
  else if(num == 3){
    return 3;
  }
  else if(num == 5){
    return 5;
  }
  else if(num == 7){
    return 7;
  }
  else if(num == 9){
    return 9;
  }
}

int verificaPar(int num)
{
  if(num == 2){
    return 2;
  }
  else if(num == 4){
    return 4;
  }
  else if(num == 6){
    return 6;
  }
  else if(num == 8){
    return 8;
  }
}

void loop(int num, int somaNando, int somaDunga)
{
  if (num > 0){
    int aux = 0;
    aux = num%10;
    //printf("Valor pego: %d\n", aux);
    if(aux%2 == 0){
      int aux2 = 0;
      aux2 = verificaPar(aux);
      somaDunga = somaDunga + aux2;
      //printf("Soma Dunga: %d\n", somaDunga);
      loop(num/10, somaNando, somaDunga);
    }
    else{
      int aux2 = 0;
      aux2 = verificaImpar(aux);
      somaNando = somaNando + aux2;
      //printf("Soma Nando: %d\n", somaNando);
      loop(num/10, somaNando, somaDunga);
    }
  }
  else{
    if (somaDunga > somaNando){
      //printf("Valor somaNando: %d\n", somaNando);
      //printf("Valor somaDunga: %d\n", somaDunga);
      printf("Vencedor: Dunga\n%d Pontos de vantagem\n", somaDunga - somaNando);
    }
    else if (somaNando > somaDunga){
      //printf("Valor somaNando: %d\n", somaNando);
      //printf("Valor somaDunga: %d\n", somaDunga);
      printf("Vencedor: Nando\n%d Pontos de vantagem\n", somaNando - somaDunga);
    }
    else{
      //printf("Valor somaNando: %d\n", somaNando);
      //printf("Valor somaDunga: %d\n", somaDunga);
      printf("Empate\n");
    }
  }
}

int main()
{
  int num=0, somaNando=0, somaDunga=0;
  scanf("%d", &num);
  //printf("Valor do numero: %d\n", num);
  loop(num, somaNando, somaDunga);
  return 0;
}
