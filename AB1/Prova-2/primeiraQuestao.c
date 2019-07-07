#include <stdio.h>

int verificaAmigo(int soma, int a, int b, int contNumAmigos){
  if(a <= b){
    if(soma == b){
        printf("%d e amigo de %d\n", soma, a);
        return contNumAmigos + 1;
    }
    else{
      verificaAmigo(soma, a + 1, b, contNumAmigos);
    }
  }
  else{
    return contNumAmigos;
  }
}

void somaAmigo(int a, int b, int i, int soma, int contNumAmigos)
{
  if(i < a )
  {
    if(a%i == 0){
      soma += i;
      contNumAmigos = verificaAmigo(soma, a, b, contNumAmigos);
      if(contNumAmigos > 0){
          somaAmigo(a + 1, b, i+1, soma, contNumAmigos);
      }
      else{
        somaAmigo(a, b, i+1, soma, contNumAmigos);
      }
    }
    else{
      somaAmigo(a, b, i+1, soma, contNumAmigos);
    }
  }
  else{
    if (i == a && a <= b){
      somaAmigo(a + 1, b, 1, 0, contNumAmigos);
    }
    if((i == a) && (a == b) && (contNumAmigos == 0)){
      printf("Nao existem numeros amigos\n");
    }
  }
}

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  somaAmigo(a, b, 1, 0, 0);
  return 0;
}
