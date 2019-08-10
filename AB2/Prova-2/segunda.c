#include <stdio.h>
#include <string.h>

void colher(int n, int m, int terreno[][m], int* morango)
{
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(terreno[i][j] == 3){
                *morango += 1;
                terreno[i][j] = 0;
            }
            else if(terreno[i][j] == -1){
                terreno[i][j] = 0;
            }
        }
    }
}

void plantar(int n, int m, int terreno[][m], int linha, int* ml)
{
    int i;
    for(i = 0; i < m; i++){
        if(terreno[linha][i] == 0){
            terreno[linha][i] = 1;
            *ml += 2;
        }
    }
}

void lerArray(int i, int linhas, int array[])
{
    if(i < linhas){
        scanf("%d", &array[i]);
        if(getchar() == '\n'){
            lerArray(linhas, linhas, array);
        }
        else{
            lerArray(i + 1, linhas, array);
        }
    }
}

void temporada(int n, int m, int terreno[][m], int* ml)
{
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(terreno[i][j] == 1 || terreno[i][j] == 2){
                terreno[i][j]++;
                if(terreno[i][j] == 2){
                    *ml += 2;
                }
            }
        }
    }
}

void ataque(int k, int w, int m, int terreno[][m])
{
    if(terreno[k][w] == 1 || terreno[k][w] == 2 || terreno[k][w] == 3){
        terreno[k][w] = -1;
    }
}

void loop(int n, int m, int terreno[][m], char comando[50], int morangos, int ml)
{
    if(scanf("%s", comando) != EOF){
        if(strcmp(comando, "Colher") == 0){
            colher(n, m, terreno, &morangos);
            loop(n, m, terreno, comando, morangos, ml);
        }
        else if(strcmp(comando, "Plantar") == 0){
            int linha[n];
            int i;
            for(i = 0; i < n; i++){
                linha[i] = -1;
            }
            lerArray(0, n, linha);
            for(i = 0; linha[i] != -1; i++){
                plantar(n, m, terreno, linha[i], &ml);
            }
            loop(n, m, terreno, comando, morangos, ml);
        }
        else if(strcmp(comando, "Temporada") == 0){
            temporada(n, m, terreno, &ml);
            loop(n, m, terreno, comando, morangos, ml);
        }
        else if(strcmp(comando, "Ataque") == 0){
            int i, j, k, w;
            scanf("%d %d", &k, &w);
            ataque(k, w, m, terreno);
            loop(n, m, terreno, comando, morangos, ml);
        }
    }
    else{
        int i, j;
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                if(j == m - 1){
                    printf("%d\n", terreno[i][j]);
                }
                else{
                    printf("%d ", terreno[i][j]);
                }
            }
        }
        printf("\n");
        printf("Foram colhidos %d morangos.\n", morangos);
        printf("Foram utilizados %dml de inseticida.\n", ml);
    }
}

int main()
{
    int n, m, i, j;
    char caracter, comando[50];
    scanf("%d %d", &n, &m);
    int terreno[n][m];
    for(i = 0; i < n; i++){
        for (j = 0; j < m; j++) {
            scanf("%d", &terreno[i][j]);
        }
    }
    getchar();
    loop(n, m, terreno, comando, 0, 0);
    return 0;
}
