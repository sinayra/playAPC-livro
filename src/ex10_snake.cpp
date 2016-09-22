#include <stdio.h>
#include <stdlib.h>
#include <playAPC/playapc.h>

#define ESQ GLFW_KEY_LEFT
#define DIR GLFW_KEY_RIGHT
#define CIMA GLFW_KEY_UP
#define BAIXO GLFW_KEY_DOWN

#define TAM 50

typedef enum{
    CABECA,
    CORPO,
    COMIDA,
    VAZIO
}tipoCobra;

typedef struct{
    int direcao; //se tipo nao for vazio, indica direcao
    tipoCobra tipo; //como sera pintado
    int index; //indice do quadrado a ser pintado
}tipoCelula;

void inicializaMatriz(tipoCelula m[TAM][TAM], int pos_i, int pos_j){
    Ponto p;

    printf("Aguarde enquanto o jogo inicializa\n");

    p.y = TAM/2 - 1;
    for(int i = 0; i < TAM; i++){
        p.x = -(TAM/2);
        for(int j = 0; j < TAM; j++){
            m[j][i].index = CriaQuadrado(1, p);
            m[j][i].tipo = VAZIO;
            //printf("m[%d][%d] = %d - P(%f,%f)\n", i, j, m[i][j].index, p.x, p.y);
            Pintar(0, 0, 0);
            p.x++;
        }
        p.y--;
    }
    Pintar(255, 255, 255, QUADRADO, m[pos_i][pos_j].index);
    m[pos_i][pos_j].direcao = CIMA;
    m[pos_i][pos_j].tipo = CABECA;
}

int bateu(tipoCelula m[TAM][TAM], int pos_i, int pos_j){
    if(m[pos_i][pos_j].tipo == CORPO || m[pos_i][pos_j].tipo == CABECA){
        printf("CORPO\n");
        return 1;
    }
    else if(pos_i >= TAM || pos_j >= TAM || pos_i < 0 || pos_j < 0){
        printf("LIMITE DA TELA\n");
        return 1;
    }

    return 0;
}
void atualizaPosicao(int direcao, int *npos_i, int *npos_j){
     switch(direcao){
        case ESQ:
            (*npos_i)--;
        break;
        case DIR:
            (*npos_i)++;
        break;
        case CIMA:
            (*npos_j)--;
        break;
        case BAIXO:
            (*npos_j)++;
        break;
    }
}

void updateTeclado(int *direcao, int *npos_i, int *npos_j){
    if(ApertouTecla(ESQ) && *direcao != DIR)
        (*direcao) = ESQ;

    if(ApertouTecla(DIR) && *direcao != ESQ)
        (*direcao) = DIR;

    if(ApertouTecla(CIMA) && *direcao != BAIXO)
        (*direcao) = CIMA;

    if(ApertouTecla(BAIXO) && *direcao != CIMA)
        (*direcao) = BAIXO;

    atualizaPosicao((*direcao), npos_i, npos_j);
}

//retorna se comeu comida
int updateCabeca(tipoCelula m[TAM][TAM], int pos_i, int pos_j, int direcao){
    int comeu = 0;

    Pintar(255, 255, 255, QUADRADO, m[pos_i][pos_j].index);
    m[pos_i][pos_j].direcao = direcao;

    if(m[pos_i][pos_j].tipo == COMIDA)
        comeu = 1;

    m[pos_i][pos_j].tipo = CABECA;

    return comeu;
}

void updateRastro(tipoCelula m[TAM][TAM], int pos_i, int pos_j){
    Pintar(0, 0, 0, QUADRADO, m[pos_i][pos_j].index);
    m[pos_i][pos_j].tipo = VAZIO;
}

void sorteiaComida(tipoCelula m[TAM][TAM]){

    int pos_i, pos_j;
    do{
        pos_i = rand()%TAM;
        pos_j = rand()%TAM;
    }while(m[pos_i][pos_j].tipo != VAZIO);

    Pintar(255, 255, 0, QUADRADO, m[pos_i][pos_j].index);

    m[pos_i][pos_j].tipo = COMIDA;
}

int main(){
    tipoCelula m[TAM][TAM]; //-100 a 100 pra cima e pra baixo, cada quadrado
    int pos_i = TAM/2; //posicao i da cabeca
    int pos_j = TAM/2; //posicao j da cabeca
    int aberto;

    int rpos_i = pos_i; //posicao i do rabo
    int rpos_j = pos_j; //posicao j do rabo

    int direcao = CIMA;
    MudaLimitesJanela(TAM/2);
    AbreJanela(650, 650, "Snake");
    PintarFundo(255, 0, 0);
    //MostraPlanoCartesiano(5);

    inicializaMatriz(m, pos_i, pos_j);

    sorteiaComida(m);

    while(1){
        int npos_i = pos_i, npos_j = pos_j;

        updateTeclado(&direcao, &npos_i, &npos_j);
        m[pos_i][pos_j].direcao = direcao; //ultima posicao da cabeca recebe direcao que cabeca foi
        if(!bateu(m, npos_i, npos_j)){
            int comeu;

            comeu = updateCabeca(m, npos_i, npos_j, direcao);
            if(comeu)
                sorteiaComida(m);
            else{
                updateRastro(m, rpos_i, rpos_j);
                atualizaPosicao(m[rpos_i][rpos_j].direcao, &rpos_i, &rpos_j);
                m[rpos_i][rpos_j].tipo = CORPO;
            }

            pos_i = npos_i;
            pos_j = npos_j;

            printf("C(%d, %d)\t R(%d, %d)\n", pos_i, pos_j, rpos_i, rpos_j);
        }
        else
            break;

        aberto = Desenha1Frame();
        if(!aberto)
            break;
    }

    printf("O jogo acabou!\n");

    if(aberto)
        Desenha();

    return 0;
}

