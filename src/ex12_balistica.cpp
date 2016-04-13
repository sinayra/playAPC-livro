#include <playAPC/playapc.h>
#include <time.h>

int colisaoBolinhaRetangulo(int raio, int largurapredio, Ponto alvo, Ponto partida, Ponto movimentacao){

    if( movimentacao.y - raio <= alvo.y
        && movimentacao.y - raio > alvo.y - 1      //tolerancia para pousar no eixo y
        && movimentacao.x + raio < alvo.x + largurapredio
        && movimentacao.x >= alvo.x
        )
        return 1;
    else if(fabs(movimentacao.x + raio) > 100 || fabs(movimentacao.y + raio) > 100)
        return 2;
    else
        return 0;

}

int main(){
    Ponto p, alvo, partida;
    float theta, v0, t;
    int colisao = 1, resposta, bolinha;

    AbreJanela(800,600, "Balistica");
    srand(time(NULL));
    do{
        MostraPlanoCartesiano(10);
        PintarFundo(255, 255, 255);
    ///////////////////////////////////Predio Azul//////////////////////////////////
        CriaGrupo(); //Separa os grupos - este e o grupo dos predios
            if(colisao == 1) //Comeca uma nova fase
                p.x = rand()%20 - 100; //-100 para comecar do lado esquerdo da tela
            else //Repete fase anterior
                p.x = partida.x - 25;
            p.y = 0;
            CriaRetangulo(50, -100, p);
            Pintar(0, 0, 255);
    ////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////Predio Amarelo//////////////////////////////////

            if(colisao == 1) //Comeca uma nova fase
                alvo.x = (p.x) + rand()%50 + 100;
            else //Repete a fase anterior
                alvo.x = alvo.x;
            alvo.y = -70;
            CriaRetangulo(40, -90, alvo);
            Pintar(255, 255, 0);
    ////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////Bolinha//////////////////////////////////
        bolinha = CriaGrupo(); //Separa os grupos - este e o grupo da bolinha
            partida.x = p.x + 25; //25 para estar no meio de um predio de largura 50
            partida.y = 10;
            CriaCircunferencia(10, partida);
            Pintar(255, 0, 0);
    ////////////////////////////////////////////////////////////////////////////////

        Desenha1Frame();

        printf("Angulo: ");
        scanf("%f", &theta);
        printf("\nVelocidade: ");
        scanf("%f", &v0);

        t = 0;
        theta = theta * PI/180;
        colisao = 0;
        do{
            if(!colisao){
                p.x = partida.x + v0 * cos(theta) * t;
                p.y = partida.y + v0 * sin(theta) * t - ((1/2.0) * (9.8) * (t*t));
                Move(p, bolinha);
                t += 0.01; //tempo
            }

            colisao = colisaoBolinhaRetangulo(10, 40, alvo, partida, p);

            Desenha1Frame();
        }while(!colisao);
        //printf("Tipo de colisao: %d\n", colisao);

        LimpaDesenho(); //Limpo o desenho para comecar uma nova fase @{ \label{line:MudaLimitesJanela}@
        if(colisao == 1)
            printf("\nYay! Quer jogar um novo jogo?");
        else
            printf("\nOh nao... Quer tentar de novo?");
        printf("\n1 - Sim\n0 - Nao\n");
        scanf("%d", &resposta);

    }while(resposta);

    Desenha();

    return 0;
}
