#include <playAPC/playapc.h>

int main(){
    int R[100][100], G[100][100], B[100][100];
    int Raux[102][102], Gaux[102][102], Baux[102][102];
    int Rf[102][102], Gf[102][102], Bf[102][102];
    int soma;
    int mfiltro = 8;
    Ponto p;

    //inicializa matrizes
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            Raux[i][j] = 0;
            Gaux[i][j] = 0;
            Baux[i][j] = 0;

            Rf[i][j] = 0;
            Gf[i][j] = 0;
            Bf[i][j] = 0;
        }
    }

    ExtraiRGBdeBMP("Mario.bmp", 100, 100, R, G, B); @{ \label{line:ExtraiRGBdeBMP}@

    AbreJanela(300, 300, "Marios");
    //PintarFundo(255, 255, 255);

    //Passa as cores para aux
    for(int i = 1; i < 101; i++){
        for(int j = 1; j < 101; j++){
            Raux[i][j] = R[i - 1][j - 1];
            Gaux[i][j] = G[i - 1][j - 1];
            Baux[i][j] = B[i - 1][j - 1];
        }
    }

    //Realiza filtragem
    for(int i = 1; i < 101; i++){
        for(int j = 1; j < 101; j++){
            soma = 0;
            soma +=     Raux[i-1][j-1] + Raux[i-1][j] + Raux[i-1][j+1]
                    +   Raux[i][j-1] + Raux[i][j] + Raux[i][j+1]
                    +   Raux[i+1][j-1] + Raux[i+1][j] + Raux[i+1][j+1];
            Rf[i][j] = soma/mfiltro;

            soma = 0;
            soma +=     Gaux[i-1][j-1] + Gaux[i-1][j] + Gaux[i-1][j+1]
                    +   Gaux[i][j-1] + Gaux[i][j] + Gaux[i][j+1]
                    +   Gaux[i+1][j-1] + Gaux[i+1][j] + Gaux[i+1][j+1];
            Gf[i][j] = soma/mfiltro;

            soma = 0;
            soma +=     Baux[i-1][j-1] + Baux[i-1][j] + Baux[i-1][j+1]
                    +   Baux[i][j-1] + Baux[i][j] + Baux[i][j+1]
                    +   Baux[i+1][j-1] + Baux[i+1][j] + Baux[i+1][j+1];
            Bf[i][j] = soma/mfiltro;

        }
    }

    p.y = -50;
    for(int i = 1; i < 101; i++){
        p.x = -100;
        for(int j = 1; j < 101; j++){
            CriaQuadrado(1, p);
            Pintar(Raux[i][j], Gaux[i][j], Baux[i][j]);

            p.x++;
        }
        p.y++;
    }

    p.y = -50;
    for(int i = 1; i < 101; i++){
        p.x = 0;
        for(int j = 1; j < 101; j++){
            CriaQuadrado(1, p);
            Pintar(Rf[i][j], Gf[i][j], Bf[i][j]);

            p.x++;
        }
        p.y++;
    }

    Desenha();
}
