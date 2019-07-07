#include <stdio.h>

void verifica(int a, int b, int c, int d, int e);
void ordena(int* a, int* b, int* c, int* d, int* e);

int main()
{
  int a, b, c, d, e;
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
  if((a < 0) || (b < 0) || (c < 0) || (d < 0) || (e < 0) || (a > 1000000) || (b > 1000000) || (c > 1000000)
  || (d > 1000000) || (e > 1000000)){
    return 0;
  }
  ordena(&a, &b, &c, &d, &e);
  ordena(&a, &b, &c, &d, &e);
  ordena(&a, &b, &c, &d, &e);
  ordena(&a, &b, &c, &d, &e);
  ordena(&a, &b, &c, &d, &e);
  ordena(&a, &b, &c, &d, &e);
  ordena(&a, &b, &c, &d, &e);
  ordena(&a, &b, &c, &d, &e);
  ordena(&a, &b, &c, &d, &e);
  ordena(&a, &b, &c, &d, &e);
  verifica(a, b, c, d, e);
  return 0;
}

void verifica(int a, int b, int c, int d, int e)
{
  int razao;

  if((a < b) && (b < c) && (c < d) && (d < e))
  {//ordem crescente de entrada
    if(((b/a) == (c/b)) && ((c/b) == (d/c)) &&((d/c) == (e/d)))
    {
      razao = b/a;
      printf("S\n%d %d %d %d %d\n%d\n", a, b, c, d, e, razao);
    }
    else{
      printf("N\n");
    }
  }
  else
  {
    printf("N\n");
  }
}

void ordena (int* a, int* b, int* c, int* d, int* e){
  int aux;
  if (*a > *b){
    aux = *a;
    *a = *b;
    *b = aux;
  }
  else if (*a > *c){
    aux = *a;
    *a = *c;
    *c = aux;
  }
  else if (*a > *d){
    aux = *a;
    *a = *d;
    *d = aux;
  }
  else if (*a > *e){
    aux = *a;
    *a = *e;
    *e = aux;
  }
  else if (*b > *c){
    aux = *b;
    *b = *c;
    *b = aux;
  }
  else if (*b > *d){
    aux = *b;
    *b = *d;
    *d = aux;
  }
  else if (*b > *e){
    aux = *b;
    *b = *e;
    *e = aux;
  }
  else if (*c > *d){
    aux = *c;
    *c = *d;
    *d = aux;
  }
  else if (*c > *e){
    aux = *c;
    *c = *e;
    *e = aux;
  }
  else if (*d > *e){
    aux = *d;
    *d = *e;
    *e = aux;
  }
}
