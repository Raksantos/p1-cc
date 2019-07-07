#include <stdio.h>

int somar_1(int x);
int somar_2(int y);

int main ()
{
  int resultado = somar_2(10);
  printf("%d\n", resultado);
}

int somar_1(int x)
{
    return x+1;
}

int somar_2(int y)
{
  int z = somar_1(y);
  z = somar_1(z);
  return z;
}
