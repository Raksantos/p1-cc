#include <stdio.h>

double media();

int main ()
{
  double x;
  double y;
  double z;
  printf("Informe o primeiro número: ");
  scanf("%lf", &x);
  printf("Informe o segundo número: ");
  scanf("%lf", &y);
  printf("Informe o terceiro número: ");
  scanf("%lf", &z);
  printf ("%lf\n", media(x, y, z));
  return 0;
}

double media(double x, double y, double z)
{
  double media = (x + y + z)/3.0;
  return media;
}
