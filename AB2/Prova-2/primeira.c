#include <stdio.h>

struct pokemon{
    char nome[50];
    int id;
    int ataque;
    int vida;
};

void batalha(int redAtaque, int redVida, int blueAtaque, int blueVida, int i)
{
    if(redVida > 0 && blueVida > 0){
        redVida -= blueAtaque;
        blueVida -= redAtaque;
        batalha(redAtaque, redVida, blueAtaque, blueVida, i + 1);
    }
    else{
        if(redVida <=0 && blueVida > 0){
            printf("Vencedor: Blue\n");
        }
        else if(redVida > 0 && blueVida <= 0){
            printf("Vencedor: Red\n");
        }
        else{
            printf("Empate\n");
        }
    }
}

int main()
{
    struct pokemon red[6], blue[6], maiorRed, maiorBlue;
    int i, x;
    for(i = 0; i < 6; i++){
        scanf("%s", red[i].nome);
        scanf("%d", &red[i].id);
        scanf("%d", &red[i].ataque);
        scanf("%d", &red[i].vida);
    }
    for(i = 0; i < 6; i++){
        scanf("%s", blue[i].nome);
        scanf("%d", &blue[i].id);
        scanf("%d", &blue[i].ataque);
        scanf("%d", &blue[i].vida);
    }
    for(i = 0; i < 6; i++){
        if(i == 0){
            for(x = 0; red[i].nome[x] != '\0'; x++){
                maiorRed.nome[x] = red[i].nome[x];
            }
            maiorRed.nome[x] = '\0';
            maiorRed.id = red[i].id;
            maiorRed.ataque = red[i].ataque;
            maiorRed.vida = red[i].vida;
        }
        else if(red[i].ataque > maiorRed.ataque){
            for(x = 0; red[i].nome[x] != '\0'; x++){
                maiorRed.nome[x] = red[i].nome[x];
            }
            maiorRed.nome[x] = '\0';
            maiorRed.id = red[i].id;
            maiorRed.ataque = red[i].ataque;
            maiorRed.vida = red[i].vida;
        }
        else if(red[i].ataque == maiorRed.ataque){
            if(red[i].id < maiorRed.id){
                for(x = 0; red[i].nome[x] != '\0'; x++){
                    maiorRed.nome[x] = red[i].nome[x];
                }
                maiorRed.nome[x] = '\0';
                maiorRed.id = red[i].id;
                maiorRed.ataque = red[i].ataque;
                maiorRed.vida = red[i].vida;
            }
        }
    }
    for(i = 0; i < 6; i++){
        if(i == 0){
            for(x = 0; blue[i].nome[x] != '\0'; x++){
                maiorBlue.nome[x] = blue[i].nome[x];
            }
            maiorBlue.nome[x] = '\0';
            maiorBlue.id = blue[i].id;
            maiorBlue.ataque = blue[i].ataque;
            maiorBlue.vida = blue[i].vida;
        }
        else if(blue[i].ataque > maiorBlue.ataque){
            for(x = 0; blue[i].nome[x] != '\0'; x++){
                maiorBlue.nome[x] = blue[i].nome[x];
            }
            maiorBlue.nome[x] = '\0';
            maiorBlue.id = blue[i].id;
            maiorBlue.ataque = blue[i].ataque;
            maiorBlue.vida = blue[i].vida;
        }
        else if(blue[i].ataque == maiorBlue.ataque){
            if(blue[i].id < maiorBlue.id){
                for(x = 0; blue[i].nome[x] != '\0'; x++){
                    maiorBlue.nome[x] = blue[i].nome[x];
                }
                maiorBlue.nome[x] = '\0';
                maiorBlue.id = blue[i].id;
                maiorBlue.ataque = blue[i].ataque;
                maiorBlue.vida = blue[i].vida;
            }
        }
    }
    printf("Pokemon do Red: %s\n", maiorRed.nome);
    printf("Pokemon do Blue: %s\n", maiorBlue.nome);
    batalha(maiorRed.ataque, maiorRed.vida, maiorBlue.ataque, maiorBlue.vida, 0);
    return 0;
}
