#include <stdio.h>
#include <string.h>

struct dados{
    char nome[50];
    int idade;
    int sexo;
    int parentesco;
};

void iniciaAux(int i, int array[], int n)
{
  if(i < n){
    if(i == 0){
      array[i] = 1;
      iniciaAux(i + 1, array, n);
    }
    array[i] = -1;
    iniciaAux(i + 1, array, n);
  }
}

void iniciaFamilia(int i, int array[], int n)
{
  if(i < n){
    if(i == 0){
      array[i] = 1;
      iniciaFamilia(i + 1, array, n);
    }
    array[i] = 0;
    iniciaFamilia(i + 1, array, n);
  }
}

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

int contaTocas(int i, int j, int x, int array[], int arrayAux[], int n, int numTocas, int tamanhoFamilia[])
{
  if(i < n){
    if(arrayAux[i] == 0){
      arrayAux[i] = 1;
      return contaTocas(array[i], j, x + 1, array, arrayAux, n, numTocas, tamanhoFamilia);
    }
    else{
      tamanhoFamilia[j] = x;
      return contaTocas(posicaoComecar(i, arrayAux, n), j + 1, 0, array, arrayAux, n, numTocas + 1, tamanhoFamilia);
    }
  }
  else{
    return numTocas;
  }
}

int main()
{
    int n, i, x, aux = 0, j = 0, qtdFamilia=0;
    scanf("%d", &n);
    struct dados pessoas[n];
    int familias[n], parentesco[n], tamanhoFamilia[n];
    for(i = 0; i < n; i++){
        scanf("%s", pessoas[i].nome);
        scanf("%d", &pessoas[i].idade);
        scanf("%d", &pessoas[i].sexo);
    }
    for(i = 0; i < n; i++){
        scanf("%d", &parentesco[i]);
        pessoas[i].parentesco = parentesco[i];
    }
    iniciaFamilia(0, familias, n);
    iniciaAux(0, tamanhoFamilia, n);
    qtdFamilia = contaTocas(0, 0, 0, parentesco, familias, n, qtdFamilia, tamanhoFamilia);
    printf("Quantidade de Familias: %d\n\n", qtdFamilia);
    for(i = 0; i < qtdFamilia; i++){
         int maisVelho, maisVelhoSexo;
         char maisVelhoNome[50];
         printf("Familia: %d\n", i + 1);
         printf("Tamanho da Familia: %d\n", tamanhoFamilia[i]);
         for(x = 0; x < tamanhoFamilia[i]; x++){
             if(x == 0){
                 strcpy(maisVelhoNome, pessoas[aux].nome);
                 maisVelho = pessoas[aux].idade;
                 maisVelhoSexo = pessoas[aux].sexo;
                 //printf("%d\n", aux);
             }
             else{
                 //printf("Entrou no else\n");
                 if(maisVelho < pessoas[aux].idade){
                    //printf("Entrou no if\n");
                    strcpy(maisVelhoNome, pessoas[aux].nome);
                    maisVelho = pessoas[aux].idade;
                    maisVelhoSexo = pessoas[aux].sexo;
                    //printf("%d\n", aux);
                 }
                 else if(maisVelho == pessoas[aux].idade){
                     //printf("Entrou aqui\n");
                     if(maisVelhoSexo == 1 && pessoas[aux].sexo == 0){
                        strcpy(maisVelhoNome, pessoas[aux].nome);
                        maisVelho = pessoas[aux].idade;
                        maisVelhoSexo = pessoas[aux].sexo;
                        //printf("%d\n", aux);
                     }
                 }
             }
             aux++;
         }
         printf("Integrante mais velho: %s\n", maisVelhoNome);
         printf("Idade do integrante mais velho: %d\n", maisVelho);
         printf("\n");
    }
    return 0;
}