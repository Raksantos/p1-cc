#include <stdio.h>

int main(){
  char t, h, w;
  double a, l, s;
  double taxaSucesso;
  scanf("%c %c %c %lf %lf %lf", &t, &h, &w, &a, &l, &s);
  if(t == 'A'){
    if (a < 1.50){
      s += 2;
      if (taxaSucesso > 100){
        printf("A taxa de sucesso do anao para entrar em Novigrad e de 100.00%\n");
      }
      else if (taxaSucesso < 0){
        printf("A taxa de sucesso do anao para entrar em Novigrad e de 0.00%\n");
      }
      else {
        taxaSucesso = 10 * ((s + l)/2.0);
        printf("A taxa de sucesso do anao para entrar em Novigrad e de %.2lf%\n", taxaSucesso);
      }
    }
    else if(a > 1.80){
      s -= 5;
      if (taxaSucesso > 100){
        printf("A taxa de sucesso do anao para entrar em Novigrad e de 100.00%\n");
      }
      else if (taxaSucesso < 0){
        printf("A taxa de sucesso do anao para entrar em Novigrad e de 0.00%\n");
      }
      else {
        taxaSucesso = 10 * ((s + l)/2.0);
        printf("A taxa de sucesso do anao para entrar em Novigrad e de %.2lf%\n", taxaSucesso);
      }
    }
    else {
      taxaSucesso = 10 * ((s + l)/2.0);
      if (taxaSucesso > 100){
        printf("A taxa de sucesso do anao para entrar em Novigrad e de 100.00%\n");
      }
      else if (taxaSucesso < 0){
        printf("A taxa de sucesso do anao para entrar em Novigrad e de 0.00%\n");
      }
      else{
        printf("A taxa de sucesso do anao para entrar em Novigrad e de %.2lf%\n", taxaSucesso);
      }
    }
  }
  else if(t == 'B'){
    if (h == 'D'){
      printf("A taxa de sucesso do bruxo para entrar em Novigrad e de 0.00%\n");
    }
    else if (h == 'N'){
      if(w == 'n'){
        printf("A taxa de sucesso do bruxo para entrar em Novigrad e de 100.00%\n");
      }
      else if(w == 'c'){
        l += 3;
        s += 3;
        if(a < 1.70){
          s += 3;
          taxaSucesso = 10 * ((s + l)/2.0);
          if (taxaSucesso > 100){
            printf("A taxa de sucesso do bruxo para entrar em Novigrad e de 100.00%\n");
          }
          else if (taxaSucesso < 0){
            printf("A taxa de sucesso do bruxo para entrar em Novigrad e de 0.00%\n");
          }
          else {
            taxaSucesso = 10 * ((s + l)/2.0);
            printf("A taxa de sucesso do bruxo para entrar em Novigrad e de %.2lf%\n", taxaSucesso);
          }
        }
        else if (a > 2.00){
          s -= 4;
          taxaSucesso = 10 * ((s + l)/2.0);
          if (taxaSucesso > 100){
            printf("A taxa de sucesso do bruxo para entrar em Novigrad e de 100.00%\n");
          }
          else if (taxaSucesso < 0){
            printf("A taxa de sucesso do bruxo para entrar em Novigrad e de 0.00%\n");
          }
          else {
            taxaSucesso = 10 * ((s + l)/2.0);
            printf("A taxa de sucesso do bruxo para entrar em Novigrad e de %.2lf%\n", taxaSucesso);
          }
        }
        else {
          taxaSucesso = 10 * ((s + l)/2.0);
          if (taxaSucesso > 100){
            printf("A taxa de sucesso do anao para entrar em Novigrad e de 100.00%\n");
          }
          else if (taxaSucesso < 0){
            printf("A taxa de sucesso do anao para entrar em Novigrad e de 0.00%\n");
          }
          else {
            printf("A taxa de sucesso do bruxo para entrar em Novigrad e de %.2lf%\n", taxaSucesso);
          }
        }
      }
      else if(w == 's'){
        s -= 1;
        if(a < 1.70){
          s += 3;
          printf("%lf", taxaSucesso);
          if (taxaSucesso > 100){
            printf("A taxa de sucesso do bruxo para entrar em Novigrad e de 100.00%\n");
          }
          else if (taxaSucesso < 0.00){
            printf("A taxa de sucesso do bruxo para entrar em Novigrad e de 0.00%\n");
          }
          else {
            taxaSucesso = 10 * ((s + l)/2.0);
            printf("A taxa de sucesso do bruxo para entrar em Novigrad e de %.2lf%\n", taxaSucesso);
          }
        }
        else if (a > 2.00){
          s -= 4;
          if (taxaSucesso > 100){
            printf("A taxa de sucesso do bruxo para entrar em Novigrad e de 100.00%\n");
          }
          else if (taxaSucesso < 0){
            printf("A taxa de sucesso do bruxo para entrar em Novigrad e de 0.00%\n");
          }
          else {
            taxaSucesso = 10 * ((s + l)/2.0);
            printf("A taxa de sucesso do bruxo para entrar em Novigrad e de %.2lf%\n", taxaSucesso);
          }
        }
        else {
          taxaSucesso = 10 * ((s + l)/2.0);
          if (taxaSucesso > 100){
            printf("A taxa de sucesso do anao para entrar em Novigrad e de 100.00%\n");
          }
          else if (taxaSucesso < 0){
            printf("A taxa de sucesso do anao para entrar em Novigrad e de 0.00%\n");
          }
          else {
            printf("A taxa de sucesso do bruxo para entrar em Novigrad e de %.2lf%\n", taxaSucesso);
          }
        }
      }
    }
  }
  else if (t == 'E'){
    if (h == 'N'){
      printf("A taxa de sucesso do elfo para entrar em Novigrad e de 0.00%\n");
    }
    else{
      if (w == 'n'){
        printf("A taxa de sucesso do elfo para entrar em Novigrad e de 0.00%\n");
      }
      else if (w == 'c'){
        l -= 2;
        if(a < 1.60){
          s += 1;
          taxaSucesso = 10 * ((s + l)/2.0);
          if (taxaSucesso > 100){
            printf("A taxa de sucesso do elfo para entrar em Novigrad e de 100.00%\n");
          }
          else if (taxaSucesso < 0){
            printf("A taxa de sucesso do elfo para entrar em Novigrad e de 0.00%\n");
          }
          else {
            taxaSucesso = 10 * ((s + l)/2.0);
            if (taxaSucesso > 100){
              printf("A taxa de sucesso do anao para entrar em Novigrad e de 100.00%\n");
            }
            else if (taxaSucesso < 0){
              printf("A taxa de sucesso do anao para entrar em Novigrad e de 0.00%\n");
            }
            else {
              printf("A taxa de sucesso do elfo para entrar em Novigrad e de %.2lf%\n", taxaSucesso);
            }
          }
        }
        else if (a > 1.90){
          s -= 6;
          taxaSucesso = 10 * ((s + l)/2.0);
          if (taxaSucesso > 100){
            printf("A taxa de sucesso do elfo para entrar em Novigrad e de 100.00%\n");
          }
          else if (taxaSucesso < 0){
            printf("A taxa de sucesso do elfo para entrar em Novigrad e de 0.00%\n");
          }
          else {
            taxaSucesso = 10 * ((s + l)/2.0);
            if (taxaSucesso > 100){
              printf("A taxa de sucesso do anao para entrar em Novigrad e de 100.00%\n");
            }
            else if (taxaSucesso < 0){
              printf("A taxa de sucesso do anao para entrar em Novigrad e de 0.00%\n");
            }
            else{
              printf("A taxa de sucesso do elfo para entrar em Novigrad e de %.2lf%\n", taxaSucesso);
            }
          }
        }
        else {
          taxaSucesso = 10 * ((s + l)/2.0);
          if (taxaSucesso > 100){
            printf("A taxa de sucesso do anao para entrar em Novigrad e de 100.00%\n");
          }
          else if (taxaSucesso < 0){
            printf("A taxa de sucesso do anao para entrar em Novigrad e de 0.00%\n");
          }
          else{
            printf("A taxa de sucesso do elfo para entrar em Novigrad e de %.2lf%\n", taxaSucesso);
          }
        }
      }
      else if (w == 's'){
        s -= 1;
        taxaSucesso = 10 * ((s + l)/2.0);
        if (taxaSucesso > 100){
          printf("A taxa de sucesso do elfo para entrar em Novigrad e de 100.00%\n");
        }
        else if (taxaSucesso < 0){
          printf("A taxa de sucesso do elfo para entrar em Novigrad e de 0.00%\n");
        }
        else {
          taxaSucesso = 10 * ((s + l)/2.0);
          if (taxaSucesso > 100){
            printf("A taxa de sucesso do anao para entrar em Novigrad e de 100.00%\n");
          }
          else if (taxaSucesso < 0){
            printf("A taxa de sucesso do anao para entrar em Novigrad e de 0.00%\n");
          }
          else{
            printf("A taxa de sucesso do elfo para entrar em Novigrad e de %.2lf%\n", taxaSucesso);
          }
        }
      }
    }
  }
  return 0;
}
