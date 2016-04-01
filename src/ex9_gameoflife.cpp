#include <playAPC/playapc.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define LINHAS 17
#define COLUNAS 17
#define VIVO  1
#define MORTO 0

void waitFor (unsigned int );

int main(){

    int geracaoAtual[LINHAS][COLUNAS], proximaGeracao[LINHAS][COLUNAS], geoIndex[LINHAS][COLUNAS];
    int l, c, i, j, soma, r, s, n, ESTADO, deltaQuad=10, largQuad = 6, marg = 2;
    Ponto p1, p2, p3;

    ////////////////////////////////
    // Define o Janela            //
    ////////////////////////////////
    AbreJanela(550, 550, "Game of life");
    PintarFundo(255, 255, 255);

    //////////////////
    // Desehna Grid //
    //////////////////

    // Desenha as retas horizontais
    p1.x = -85;
    p1.y =  85;
    p2.x =  85;
    p2.y =  85;
    for(i = 0; i < LINHAS+1; i++){
    CriaReta(p1, p2); Pintar(0, 0, 255); Grafite(3); //cima
    p1.y -=  deltaQuad;
    p2.y -=  deltaQuad;
    }
    // Desenha as retas verticais
    p1.x = -85;
    p1.y =  85;
    p2.x =  -85;
    p2.y =  -85;
    for(i = 0; i < COLUNAS+1; i++){
    CriaReta(p1, p2); Pintar(0, 0, 255); Grafite(3); //cima
    p1.x +=  deltaQuad;
    p2.x +=  deltaQuad;
    }

    // Desenha celulas
    p1.y =  85-deltaQuad+marg;
    for(i = 0; i < LINHAS; i++){
    p1.x = -85+marg;
        for(j = 0; j < COLUNAS; j++){
            geoIndex[i][j] = CriaQuadrado(largQuad, p1);
            Pintar(0, 0, 0, QUADRADO, geoIndex[i][j]); @\label{line:Pintarm2}@
            p1.x += deltaQuad;
        }
    p1.y -=deltaQuad;
    }

    ///////////////////
    // Joga o jogo   //
    ///////////////////
    // Preenche o fundo com o valor MORTO
    for(l=0; l<LINHAS; l++){
        for(c=0; c<COLUNAS; c++){
            geracaoAtual[l][c]=MORTO;
        }
    }

    // Define as celulas vivas no no canto superior esquerdo
    geracaoAtual[1][5] = VIVO;
    geracaoAtual[2][5] = VIVO;
    geracaoAtual[3][5] = VIVO; geracaoAtual[3][6] = VIVO;
    geracaoAtual[5][1] = VIVO; geracaoAtual[5][2] = VIVO;	geracaoAtual[5][3] = VIVO; geracaoAtual[5][6] = VIVO;	geracaoAtual[5][7] = VIVO;
    geracaoAtual[6][3] = VIVO; geracaoAtual[6][5] = VIVO;	geracaoAtual[6][7] = VIVO;
    geracaoAtual[7][5] = VIVO; geracaoAtual[7][6] = VIVO;

    // Realiza a reflexao do padrao
    for(l = 0; l < LINHAS/2; l++){
        for(c = 0; c < COLUNAS/2; c++){
            geracaoAtual[(LINHAS-1)-l][c] = geracaoAtual[l][c];// Inferior esquerdo
            geracaoAtual[l][(COLUNAS-1)-c] = geracaoAtual[l][c];// Superior direito
            geracaoAtual[(LINHAS-1)-l][(COLUNAS-1)-c] = geracaoAtual[l][c]; // Inferior direito
        }
    }

    while(1){

        // Faz a copia da geracao atual para a geracao anterior
        for(l = 0; l < LINHAS; l++){
            for(c = 0; c < COLUNAS; c++){
                proximaGeracao[l][c] = geracaoAtual[l][c];
            }
        }

        for(l=0; l<LINHAS; l++){
            for(c=0; c<COLUNAS; c++){
                if(proximaGeracao[l][c]==1){
                    printf("%c", 219);
                    Pintar(0, 0, 0, QUADRADO, geoIndex[l][c]);
                } else{
                    printf("%c", proximaGeracao[l][c], ' ');
                    Pintar(255, 255, 255, QUADRADO, geoIndex[l][c]);
                }
            }
            printf("\n");
        }
         Desenha1Frame();

        // Conta a quantidade de vizinhos de uma celula
        for (l = 1; l < LINHAS-1; l++){
            for(c = 1; c < COLUNAS-1; c++){
                ESTADO = proximaGeracao[l][c];
                soma = 0;
                for(r = l-1; r < l+2; r++)
                    for(s = c-1; s < c+2; s++)
                            soma+=proximaGeracao[r][s];

                if(proximaGeracao[l][c] == VIVO) soma--;

                 //Define se uma celula deve morrer, permanecer viva ou nascer
                if ((ESTADO == VIVO && soma < 2) || (ESTADO == VIVO && soma > 3)){
                    geracaoAtual[l][c] = MORTO;
                }else if ((ESTADO == VIVO && (soma > 2 || soma <= 3)) || (ESTADO == MORTO && soma == 3)){
                    geracaoAtual[l][c] = VIVO;
                }
            }
        }
        waitFor (1);
        system("cls");
    }

    Desenha();
    return 0;
}

void waitFor (unsigned int secs) {
    unsigned int retTime;
    retTime = time(0) + secs;     // Get finishing time.
    while (time(0) < retTime);    // Loop until it arrives.
}
