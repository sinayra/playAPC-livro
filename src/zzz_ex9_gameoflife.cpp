#include <playAPC/playapc.h>

int main(){
    int mCell[20][20], mCellPos[20][20], mVizinho[20][20];
    Ponto p;

    AbreJanela(400, 400, "Game of Life");
    PintarFundo(255, 255, 255);
    MostraPlanoCartesiano(10);

    p.y = 90;

    //criando matriz
    for(int i = 0; i < 20; i++){
        p.x = -100;
        for(int j = 0; j < 20; j++){
            mCell[i][j] = 0; //celula morta
            mCellPos[i][j] = CriaQuadrado(10, p);
            Pintar(255, 255, 255);

            p.x += 10;
        }

        p.y -= 10;
    }

    //criando grid
    for(int i = -100; i < 100; i += 10){
        CriaReta({-100, i}, {100, i}); //horizontal
        Grafite(2);
        Pintar(180, 180, 180);

        CriaReta({i, 100}, {i, -100}); //horizontal
        Grafite(2);
        Pintar(180, 180, 180);
    }

    //Populacao inicial
    mCell[9][10] = 1;
    Pintar(0, 0, 0, QUADRADO, mCellPos[9][10]);
    mCell[10][10] = 1;
    Pintar(0, 0, 0, QUADRADO, mCellPos[10][10]);
    mCell[11][10] = 1;
    Pintar(0, 0, 0, QUADRADO, mCellPos[11][10]);

    Desenha1Frame();

    while(!ApertouTecla(GLFW_KEY_SPACE)){

        for(int i = 0; i < 20; i++){ //analisa vizinhos
            for(int j = 0; j < 20; j++){
                int vizinho = 0;

                if(j < 19 && mCell[i][j+1] == 1) //direita
                    vizinho++;

                if(j > 0 && mCell[i][j-1] == 1) //esquerda
                    vizinho++;

                if(j < 19 && j < 19 && mCell[i-1][j-1] == 1) //cima esquerda
                    vizinho++;

                if(mCell[i-1][j] == 1) //cima
                    vizinho++;

                if(mCell[i-1][j+1] == 1) //cima direita
                    vizinho++;

                if(mCell[i+1][j-1] == 1) //baixo esquerda
                    vizinho++;

                if(mCell[i+1][j] == 1) //baixo
                    vizinho++;

                if(mCell[i+1][j+1] == 1) //baixo direita
                    vizinho++;

                mVizinho[i][j] = vizinho;
            }
        }

        for(int i = 0; i < 20; i++){ //verifica quem ficou vivo
            for(int j = 0; j < 20; j++){

                if(mCell[i][j] == 1){
                    if(mVizinho[i][j] < 2 || mVizinho[i][j] > 3){
                        mCell[i][j] = 0;
                        Pintar(255, 255, 255, QUADRADO, mCellPos[i][j]);
                    }
                }
                else{
                    if(mVizinho[i][j] == 3){
                        mCell[i][j] = 1;
                        Pintar(0, 0, 0, QUADRADO, mCellPos[i][j]);
                    }
                }

            }
        }

        Desenha1Frame();
    }

    Desenha();

    return 0;
}
