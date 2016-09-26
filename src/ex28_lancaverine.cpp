#include <playAPC/playapc.h>
#include <time.h>

#define TAMANHOQUADRADO 30
int colisaoBolinhaRetangulo(int raio, int largurapredio, Ponto alvo, Ponto movimentacao){

    if( movimentacao.y <= alvo.y + largurapredio
       && movimentacao.x + raio <=  alvo.x + largurapredio
       && movimentacao.x + raio >= alvo.x)
        return 1;
    else if(movimentacao.x > 100 || movimentacao.y < -100)
        return 2;
    else
        return 0;

}

void defineCenario(Ponto *alvo, Ponto *partida, int *grupo_wolverine, int imgbackground, int imgmagneto_standing, int imgwolverine_standing, int colisao){
    Ponto p;

    p.x = -100;
    p.y = -100;
    CriaRetangulo(400, 264, p);
    Pintar(255, 255, 255);
    AssociaImagem(imgbackground);

    if(colisao == 1) //Comeca uma nova fase
        p.x = rand()%20 - 100; //-100 para comecar do lado esquerdo da tela
    else //Repete fase anterior
        p.x = (*partida).x - 25;

    ////Magneto////
    CriaGrupo();

    if(colisao == 1) //Comeca uma nova fase
        (*alvo).x = (p.x) + rand()%50 + 100;
    else //Repete a fase anterior
        (*alvo).x = (*alvo).x;
    (*alvo).y = -100;

    CriaQuadrado(TAMANHOQUADRADO, *alvo);
    Pintar(255, 255, 255);
    AssociaImagem(imgmagneto_standing);
    //////////////////

    ////Wolverine////
    *grupo_wolverine = CriaGrupo();
    (*partida).x = -100;
    (*partida).y = -15;
    CriaQuadrado(TAMANHOQUADRADO, *partida);
    Pintar(255, 255, 255);
    AssociaImagem(imgwolverine_standing);
    //////////////////
}

float setaAngulo(Ponto partida){
    Ponto p, p2;
    float theta = 0;
    int grupo_lancar;

    printf("\nPressione a tecla setinha pra cima ou setinha pra baixo para mudar o angulo\n");

    grupo_lancar = CriaGrupo(); //Setinha que ira se mover. Salvei seu indice pois pretendo exclui-la depois
    p.x = 0;
    p.y = 0;
    p2.x = 60;
    p2.y = 0;
    CriaReta(p , p2); //Cria-lo na origem para nao dar problema com as coordenadas
    //Materia de algebra linear

    Pintar(0, 0, 255);
    Grafite(10);
    p = partida;

    Move(p); //Move-lo para o lugar certo
    do{
        Desenha1Frame();

        if(ApertouTecla(GLFW_KEY_UP)){
            theta++;
            printf("\nAngulo: %f", theta);
            Gira(theta);
        }
        else if(ApertouTecla(GLFW_KEY_DOWN)){
            theta--;
            printf("\nAngulo: %f", theta);
            Gira(theta);
        }

    }while(!ApertouTecla(GLFW_KEY_ENTER));
    @{ \label{line:ApagaGrupo}@ApagaGrupo(grupo_lancar); //Apaga setinha do angulo

    return theta;
}

float setaVelocidade(){
    int grupo_lancar;
    float v0;
    Ponto p;

    printf("\nPressione a tecla setinha pra cima ou setinha pra baixo para mudar a velocidade inicial\n");

    grupo_lancar = CriaGrupo();
    p.x = 70;
    p.y = 0; //Y como 0 para nao confundir as coordenadas
    //Materia de algebra linear

    CriaRetangulo(30, 1, p); //Altura como 1 para poder redimensiona-lo depois
    Pintar(0, 255, 0);
    p.x = 70;
    p.y = -100;
    Move(p); //Move-lo para o lugar certo

    do{
        Desenha1Frame();

        if(ApertouTecla(GLFW_KEY_UP)){
            v0 += 10;
            Redimensiona(1, v0); @{ \label{line:Redimensiona}@
            printf("\nVelocidade: %f", v0);
        }
        else if(ApertouTecla(GLFW_KEY_DOWN)){
            v0 -= 10;
            Redimensiona(1, v0);
            printf("\nVelocidade: %f", v0);
        }

    }while(!ApertouTecla(GLFW_KEY_ENTER));
    ApagaGrupo(grupo_lancar); //Apaga retangulo de velocidade

    return v0;
}

int main(){
    Ponto p, alvo, partida;
    float theta, v0, t;
    int colisao = 1, resposta;
    int imgmagneto_attack, imgmagneto_standing, imgmagneto_standing2,
        imgwolverine_flying, imgwolverine_standing, imgwolverine_standing2,
        imgbackground, imgpikachu;
    int grupo_wolverine, grupo_lancar;

    AbreJanela(600,600, "Lancaverine 2.0");

    imgmagneto_attack = AbreImagem("Xmen/magneto_attack.png");
    imgmagneto_standing = AbreImagem("Xmen/magneto_standing.png");
    imgmagneto_standing2 = AbreImagem("Xmen/magneto_standing2.png");
    imgwolverine_flying = AbreImagem("Xmen/wolverine_flying.png");
    imgwolverine_standing = AbreImagem("Xmen/wolverine_standing.png");
    imgwolverine_standing2 = AbreImagem("Xmen/wolverine_standing2.png");
    imgbackground = AbreImagem("Xmen/background.jpg");
    imgpikachu = AbreImagem("Xmen/pikachu.png");

    srand(time(NULL));
    do{


        LimpaDesenho(); //Limpo o desenho para comecar uma nova fase
        defineCenario(&alvo, &partida, &grupo_wolverine, imgbackground, imgmagneto_standing, imgwolverine_standing, colisao);

        Desenha1Frame();

        theta = setaAngulo(partida);
        v0 = setaVelocidade();

        ApagaGrupo(grupo_wolverine); //vamos resetar o wolverine para ataque

        grupo_wolverine = CriaGrupo(); //Separa os grupos - este e o grupo da bolinha
            CriaQuadrado(TAMANHOQUADRADO, partida);
            Pintar(255, 255, 255);
            AssociaImagem(imgwolverine_flying);

        t = 0;
        theta = theta * PI/180;
        colisao = 0;
        do{
            if(!colisao){
                p.x = partida.x + v0 * cos(theta) * t;
                p.y = partida.y + v0 * sin(theta) * t - ((1/2.0) * (9.8) * (t*t));
                Move(p, grupo_wolverine);
                t += 0.1; //tempo
            }

            colisao = colisaoBolinhaRetangulo(TAMANHOQUADRADO, TAMANHOQUADRADO, alvo, p);

            Desenha1Frame();
        }while(!colisao);

        if(colisao == 1){ //atingiu Magneto
            ApagaGrupo(grupo_wolverine); //remove Wolverine
            AssociaImagem(imgmagneto_attack); //Modifica Magneto

            grupo_wolverine = CriaGrupo(); //Separa os grupos - este e o grupo da bolinha
            CriaQuadrado(TAMANHOQUADRADO, p);
            Pintar(255, 255, 255);
            AssociaImagem(imgwolverine_flying);

            t = 0;
            do{ //pausa dramatica
                Desenha1Frame();
                t += 0.1;
            }while(t < 10);

            do{ //lanca wolverine
                Move(p, grupo_wolverine);
                p.x -= 10;
                p.y += 10;

                Desenha1Frame();
            }while(p.x + TAMANHOQUADRADO > -130);
            ApagaGrupo(grupo_wolverine);

            AssociaImagem(imgmagneto_standing);

            CriaGrupo();
                p.x = -80;
                p.y = 32;
                CriaQuadrado(20, p);
                Pintar(255, 255, 255);
                AssociaImagem(imgpikachu);

            Desenha1Frame();
        }

        if(colisao == 2){//Nao atingiu magneto
            if(p.x > alvo.x){ //Wolverine esta na frente do Magneto
                AssociaImagem(imgwolverine_standing2);
            }
            else{ //Wolverine esta nas costas do Magneto
                ApagaGrupo(grupo_wolverine);

                AssociaImagem(imgmagneto_standing2);
                grupo_wolverine = CriaGrupo(); //Separa os grupos - este e o grupo da bolinha
                    CriaQuadrado(TAMANHOQUADRADO, p);
                    Pintar(255, 255, 255);
                    AssociaImagem(imgwolverine_standing);
            }

            t = 0;
            do{ //pausa dramatica
                Desenha1Frame();
                t += 0.1;
            }while(t < 10);
        }

        if(colisao == 1){
            printf("\nYay! Quer jogar um novo jogo?");
        }
        else{
            printf("\nOh nao... Quer tentar de novo?");
        }
        printf("\n1 - Sim\n0 - Nao\n");
        scanf("%d", &resposta);

    }while(resposta);

    Desenha();

    return 0;
}
