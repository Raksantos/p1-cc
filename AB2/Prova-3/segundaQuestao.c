#include <stdio.h>

typedef struct mapa{
    int i;
    int j;
} mapas;

typedef struct dados{
    int posI;
    int posJ;
    int pontos;
} pessoa;

void jogo(int i, int pontMapa, int n, pessoa jogador,
 int matrizMovimento [100][100][n], int matrizPonto[100][100][n], mapas mapa[],
 char nomeMapa[][n])
{
    if(jogador.posI == mapa[i].i && jogador.posJ == mapa[i].j){
        printf("%d\n", jogador.pontos);
    }
    else{
        if(matrizMovimento[jogador.posI][jogador.posJ][i] == 4){
            printf("%s %d\n", nomeMapa, pontMapa);
            i = matrizPonto[100][100][i];
            jogo(i, pontMapa, n, jogador, matrizMovimento, matrizPonto, mapa, nomeMapa);
        }
        else{
            if(matrizMovimento[jogador.posI][jogador.posJ][i] == 0){
                jogador.posI--;
                if(jogador.posI < 0){
                    jogador.posI += mapa[i].i;
                }
                jogador.pontos += matrizPonto[jogador.posI][jogador.posJ][i];
                jogo(i, pontMapa, n, jogador, matrizMovimento, matrizPonto, mapa, nomeMapa);
            }
            else if(matrizMovimento[jogador.posI][jogador.posJ][i] == 1){
                jogador.posI++;
                if(jogador.posI >= n){
                    jogador.posI -= mapa[i].i;
                }
                jogador.pontos += matrizPonto[jogador.posI][jogador.posJ][i];
                jogo(i, pontMapa, n, jogador, matrizMovimento, matrizPonto, mapa, nomeMapa);
            }
            else if(matrizMovimento[jogador.posI][jogador.posJ][i] == 2){
                jogador.posJ--;
                if(jogador.posJ < 0){
                    jogador.posJ += mapa[i].j;
                }
                jogador.pontos += matrizPonto[jogador.posI][jogador.posJ][i];
                jogo(i, pontMapa, n, jogador, matrizMovimento, matrizPonto, mapa, nomeMapa);
            }
            else if(matrizMovimento[jogador.posI][jogador.posJ][i] == 3){
                jogador.posJ++;
                if(jogador.posJ >= n){
                    jogador.posJ -= mapa[i].j;
                }
                jogador.pontos += matrizPonto[jogador.posI][jogador.posJ][i];
                jogo(i, pontMapa, n, jogador, matrizMovimento, matrizPonto, mapa, nomeMapa);
            }
        }
    }
}

int main()
{
    int n, i = 0, x = 0, j = 0;
    scanf("%d", &n); 
    mapas mapa[n];
    char nomeMatriz[n][100];
    //int matrizTri[100][100][n];
    pessoa jogador;
    jogador.posI = 0;
    jogador.posJ = 0;
    jogador.pontos = 0;
    int matrizMovimento[100][100][n], matrizPonto[100][100][n];

    for(i = 0; i < n; i++){
        scanf("%d", &mapa[i].i);
        scanf("%d", &mapa[i].j);
        scanf("%s", nomeMatriz[i]);

        for(x = 0; x < mapa[i].i; x++){
            for(j = 0; j < mapa[i].j; j++){
                scanf(" %[^',']d", &matrizMovimento[x][j][i]);
                scanf(" %[^',']d", &matrizPonto[x][j][i]);
            }
        }
    }
    jogo(0, 0, n, jogador, matrizMovimento, matrizPonto, mapa, nomeMatriz);
    return 0;
}