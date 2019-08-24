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

int contaTocas(int i, int aux, int aux2, int j, int x, int array[], int arrayAux[], int n, int numTocas, int tamanhoFamilia[],
              struct dados pessoas[], struct dados ordemCerta[], int vetorAux[])
{
  if(i < n){
    if(arrayAux[i] == 0){
      arrayAux[i] = 1;
      strcpy(ordemCerta[aux2].nome, pessoas[i].nome);
      ordemCerta[aux2].idade = pessoas[i].idade;
      ordemCerta[aux2].sexo = pessoas[i].sexo;
      ordemCerta[aux2].parentesco = numTocas;
      vetorAux[aux2] = i;
      return contaTocas(array[i], aux, aux2 + 1, j, x + 1, array, arrayAux, n, numTocas, tamanhoFamilia, pessoas, ordemCerta, vetorAux);
    }
    else{
      tamanhoFamilia[j] = x;
      return contaTocas(posicaoComecar(i, arrayAux, n), aux, aux2, j + 1, 0, array, arrayAux, n, numTocas + 1, tamanhoFamilia, pessoas, ordemCerta, vetorAux);
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
    struct dados pessoas[n], ordemCerta[n];
    int familias[n], parentesco[n], tamanhoFamilia[n], vetorAux[n];
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
    qtdFamilia = contaTocas(0, 0, 0, 0, 0, parentesco, familias, n, qtdFamilia, tamanhoFamilia,
                  pessoas, ordemCerta, vetorAux);
    
    // for (i = 0; i < n; i++)
    // {
    //   printf("Nome: %s\n", ordemCerta[i].nome);
    //   printf("Idade: %d\n", ordemCerta[i].idade);
    //   printf("Sexo: %d\n", ordemCerta[i].sexo);
    //   printf("Parentesco: %d\n", ordemCerta[i].parentesco);
    // }
    
    printf("Quantidade de Familias: %d\n\n", qtdFamilia);
    for(i = 0; i < qtdFamilia; i++){
         printf("Familia #%d: %d Pessoas\n\n", i + 1, tamanhoFamilia[i]);
         for (x = 0; x < tamanhoFamilia[i]; x++)
         {
           printf("Nome: %s\n", ordemCerta[aux].nome);
           printf("Idade: %d\n", ordemCerta[aux].idade);
           if (ordemCerta[aux].sexo == 1)
           {
             printf("Sexo: Masculino\n\n");
           }
           else{
             printf("Sexo: Feminino\n\n");
           }
           aux++;
         }
         printf("####################\n\n");
         /*for(x = 0; x < tamanhoFamilia[i]; x++){
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
         }*/
    }
    return 0;
}