#include <playAPC/playapc.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define TAM 20

typedef struct{
    int i, j;
    float valor;
}tipoVizinho;

void imprimeTerminal(float m[TAM][TAM], int comecoi, int comecoj){

    printf("\n\n");
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if(i == comecoi && j == comecoj)
                printf("(%3.5f) ", m[i][j]);
            else
                printf("%3.5f ", m[i][j]);
        }
        printf("\n");
    }
}

void imprimeTerminalInt(int m[TAM][TAM], int comecoi, int comecoj){

    printf("\n\n");
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if(i == comecoi && j == comecoj)
                printf("(%d) ", m[i][j]);
            else
                printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

float getVizinho(float m[TAM][TAM], int i, int j){

    if(i >= 0 && i < TAM){
        if(j >= 0 && j < TAM){
            return m[i][j];
        }
    }

    return -1;
}

int getVizinhoInt(int m[TAM][TAM], int i, int j){

    if(i >= 0 && i < TAM){
        if(j >= 0 && j < TAM){
            return m[i][j];
        }
    }

    return -1;
}

void contaInunda(int mEnche[TAM][TAM], float m[TAM][TAM], float maior, float taxa, int qtd, int mExibe[TAM][TAM]){

    if(taxa > 0){
        taxa /= qtd;
    }
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if(mEnche[i][j] > 0){
                m[i][j] = maior + taxa;
                Pintar(0, 0, m[i][j], QUADRADO, mExibe[i][j]);
                mEnche[i][j] = 0;
            }
        }
    }

    printf("Nivel de agua: %f\n", maior+taxa);
}

void bubblesort(tipoVizinho v[], int tamanho){
    short int f = 1;

    while(f){
        f = 0;
        for(int i = 0; i < tamanho-1; i++){
            if(v[i].valor > v[i+1].valor){
                tipoVizinho aux = v[i];

                v[i] = v[i+1];
                v[i+1] = aux;
                f = 1;
            }
        }
    }
}

void setVizinhos(tipoVizinho v[8], int ordem[8], float m[TAM][TAM], int comecoi, int comecoj){

    for(int i = 0; i < 8; i++)
        ordem[i] = -1;

    v[0].valor = getVizinho(m, comecoi - 1, comecoj - 1);
    v[0].i = comecoi - 1;
    v[0].j = comecoj - 1;

    v[1].valor = getVizinho(m, comecoi, comecoj - 1);
    v[1].i = comecoi;
    v[1].j = comecoj - 1;

    v[2].valor = getVizinho(m, comecoi + 1, comecoj - 1);
    v[2].i = comecoi + 1;
    v[2].j = comecoj - 1;

    v[3].valor = getVizinho(m, comecoi + 1, comecoj);
    v[3].i = comecoi + 1;
    v[3].j = comecoj;

    v[4].valor = getVizinho(m, comecoi + 1, comecoj + 1);
    v[4].i = comecoi + 1;
    v[4].j = comecoj + 1;

    v[5].valor = getVizinho(m, comecoi, comecoj + 1);
    v[5].i = comecoi;
    v[5].j = comecoj + 1;

    v[6].valor = getVizinho(m, comecoi - 1, comecoj + 1);
    v[6].i = comecoi - 1;
    v[6].j = comecoj + 1;

    v[7].valor = getVizinho(m, comecoi - 1, comecoj);
    v[7].i = comecoi - 1;
    v[7].j = comecoj;
    bubblesort(v, 8);
}

void inunda(float m[TAM][TAM], int mEnche[TAM][TAM], float *taxa, int comecoi, int comecoj, int *qtd, float *maior, int mExibe[TAM][TAM]){

    tipoVizinho v[8];
    int k = 0, ordem[8];

    setVizinhos(v, ordem, m , comecoi, comecoj);
    k = 0;

    for(int i = 0; i < 8; i++){
        if(v[i].valor == -1)
            continue;

        if(mEnche[v[i].i][v[i].j] != 1){

            if(m[comecoi][comecoj] + *taxa > v[i].valor && v[i].valor > m[comecoi][comecoj]){
                float dif = (v[i].valor - m[comecoi][comecoj]);
                (*taxa) -= dif;
                if(v[i].valor > *maior)
                    *maior = v[i].valor;

                m[comecoi][comecoj] = v[i].valor;
                if(*taxa > 0){
                    (*qtd)++;
                    ordem[k] = i;
                    k++;
                    mEnche[v[i].i][v[i].j] = 1;
                }
            }
            else if(v[i].valor < m[comecoi][comecoj]){
                float dif = (m[comecoi][comecoj] - m[v[i].i][v[i].j]);

                if((*taxa) - dif <= 0){
                    m[v[i].i][v[i].j] += (*taxa);
                    (*taxa) = 0;
                    Pintar(0, m[v[i].i][v[i].j], m[v[i].i][v[i].j], QUADRADO, mExibe[v[i].i][v[i].j]);
                }
                else{
                    m[v[i].i][v[i].j] += dif;
                    (*taxa) -= dif;
                }
                if(*taxa > 0){
                    (*qtd)++;
                    ordem[k] = i;
                    k++;
                    mEnche[v[i].i][v[i].j] = 1;
                }
                else{
                    *taxa = 0;
                }
            }
            else if(v[i].valor == m[comecoi][comecoj]){
                (*qtd)++;
                ordem[k] = i;
                k++;
                mEnche[v[i].i][v[i].j] = 1;
            }
        }
    }

    for(int i = 0; i < k; i++){
        inunda(m, mEnche, taxa, v[ordem[i]].i, v[ordem[i]].j, qtd, maior, mExibe);
    }
}

int main(){
    float mTerrenos[TAM][TAM];
    int mEnche[TAM][TAM], mExibe[TAM][TAM];
    int menor = INT_MAX;
    int comecoi = 0, comecoj = 0;
    float maior;
    Ponto p;

    AbreJanela(600, 600, "Geiser");
    srand(time(NULL));
    p.y = 90;
    for(int i = 0; i < TAM; i++){
        p.x = -100;
        for(int j = 0; j < TAM; j++){
            mTerrenos[i][j] = rand()%255;

            mExibe[i][j] = CriaQuadrado(10, p);

            Pintar(mTerrenos[i][j], 255, 0);
            p.x += 10;

            mEnche[i][j] = 0;

            if(mTerrenos[i][j] < menor){
                menor = mTerrenos[i][j];
                comecoi = i;
                comecoj = j;
            }
        }
        p.y -= 10;
    }
    mEnche[comecoi][comecoj] = 1;
    Pintar(255, 0, 0, QUADRADO, mExibe[comecoi][comecoj]);

    printf("****geracao inicial****\n");
    while(!ApertouTecla(GLFW_KEY_ENTER))
        Desenha1Frame();

    for(int geracao = 0; maior <= 255; geracao++){
        maior = mTerrenos[comecoi][comecoj];
        float taxa = 1;
        int qtd = 1;
        printf("\n****geracao %2d****\n", geracao+1);

        inunda(mTerrenos, mEnche, &taxa, comecoi, comecoj, &qtd, &maior, mExibe);
        contaInunda(mEnche, mTerrenos, maior, taxa, qtd, mExibe);
        mEnche[comecoi][comecoj] = 1;

        Desenha1Frame();
    }

    Desenha();

    return 0;
}
