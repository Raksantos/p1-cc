#include <stdio.h>

void loop(int num, int somaNando, int somaDunga)
{
  if (num > 0){
    if(aux%2 == 0){
      if(num == 2){
        somaDunga = somaDunga + 2;
      }
      else if(num == 4){
        somaDunga = somaDunga + 4;
      }
      else if(num == 6){
        somaDunga = somaDunga + 6;
      }
      else if(num == 8){
        somaDunga = somaDunga + 8;
      }
      loop(num/10, somaNando, somaDunga);
    }
    else if (aux%2 != 0){

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
