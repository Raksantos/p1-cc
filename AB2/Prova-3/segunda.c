#include <stdio.h>

struct dados{
    int atk;
    int life;
    int jump;
};

int batalha(int ambrosioAtaque, int ambrosioVida, int sofiaAtaque, int sofiaVida){
    ambrosioVida -= sofiaAtaque;
    if(ambrosioVida > 0){
        sofiaVida -= ambrosioAtaque;
        if(sofiaVida > 0){
            return batalha(ambrosioAtaque, ambrosioVida, sofiaAtaque, sofiaVida);
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}

int lutas(int r, int n, int iSofia, int jSofia,
        int iAmbrosio, int jAmbrosio, struct dados ambrosio[][n], struct dados sofia[][n])
{
    int i, j, x, auxSofia = 0, auxAmbrosio = 0;
    for(i = 0; i < r; i++){
        if(iSofia == n - 1 && jSofia == n - 1){
            printf("Sofia: (%d, %d)\n", iSofia, iSofia);
            printf("Ambrosio: (%d, %d)\n", iAmbrosio, jAmbrosio);
            printf("Sofia venceu\n");
            return 0;
        }
        else if(iAmbrosio == n - 1 && jAmbrosio == n - 1){
            printf("Sofia: (%d, %d)\n", iSofia, jSofia);
            printf("Ambrosio: (%d, %d)\n", iAmbrosio, jAmbrosio);
            printf("Ambrosio venceu\n");
            return 0;
        }
        else{
            int retorno = batalha(ambrosio[iAmbrosio][jAmbrosio].atk,
                                ambrosio[iAmbrosio][jAmbrosio].life, sofia[iSofia][jSofia].atk, 
                                sofia[iSofia][jSofia].life);
            if(retorno == 0){
                jSofia += sofia[iSofia][jSofia].jump;
                if(jSofia > n - 1){
                    for(x = 0; x < n && jSofia > n -1; x++){
                        jSofia = sofia[iSofia][jSofia].jump - (n - 1);
                        iSofia++;
                    }
                }
            }
            else if(retorno == 1){
                jAmbrosio += ambrosio[iAmbrosio][jAmbrosio].jump;
                if(jAmbrosio > n - 1){
                    for(x = 0; x < n && jAmbrosio > n -1; x++){
                        jAmbrosio = ambrosio[iAmbrosio][jAmbrosio].jump - (n - 1);
                        iAmbrosio++;
                    }
                }  
            }
        }
    }
    printf("Sofia: (%d, %d)\n", iSofia, jSofia);
    printf("Ambrosio: (%d, %d)\n", iAmbrosio, jAmbrosio);
    printf("Ninguem venceu\n");
}

int main()
{
    int n, i, j, r;
    scanf("%d", &n);
    struct dados sofia[n][n], ambrosio[n][n];
    for (i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++){
            scanf("%d", &sofia[i][j].atk);
            scanf("%d", &sofia[i][j].life);
            scanf("%d", &sofia[i][j].jump);
        }
    }
    
    for (i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++){
            scanf("%d", &ambrosio[i][j].atk);
            scanf("%d", &ambrosio[i][j].life);
            scanf("%d", &ambrosio[i][j].jump);
        }
    }

    scanf("%d", &r);

    lutas(r, n, 0, 0, 0, 0, ambrosio, sofia);
    return 0;
}