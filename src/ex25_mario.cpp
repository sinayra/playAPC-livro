#include <playAPC/playapc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    Ponto p, pcano1, pcano2, pmario;
    int imgbackground, imgcano,
        imgmario_caminhando_1, imgmario_caminhando_2, imgmario_caminhando_3, imgmario_pre_caminhada, imgmario_pre_salto, imgmario_salto;
    int grupocano, grupomario, grupoback;
    float t, x, y;
    int raio_pulo = 40;

    srand (time(NULL));
    AbreJanela(600, 385, "Run, Mario, run!");

    imgbackground = AbreImagem("Mario_Run/background.png"); @{ \label{line:AbreImagem}@
    imgcano = AbreImagem("Mario_Run/cano.png");
    imgmario_caminhando_1 = AbreImagem("Mario_Run/mario_caminhando_1.png");
    imgmario_caminhando_2 = AbreImagem("Mario_Run/mario_caminhando_2.png");
    imgmario_caminhando_3 = AbreImagem("Mario_Run/mario_caminhando_3.png");
    imgmario_pre_caminhada = AbreImagem("Mario_Run/mario_pre_caminhada.png");
    imgmario_pre_salto = AbreImagem("Mario_Run/mario_pre_salto.png");
    imgmario_salto = AbreImagem("Mario_Run/mario_salto.png");

    //Background
    grupoback = CriaGrupo();
        p.x = -156;
        p.y = -100;
        CriaRetangulo(312, 200, p);
        Pintar(255, 255, 255);
        AssociaImagem(imgbackground); @{ \label{line:AssociaImagemm1}@

    //Canos
    grupocano = CriaGrupo();
        pcano1.x = -(100 - rand()%50);
        pcano1.y = -70;
        CriaQuadrado(30, pcano1);
        Pintar(255, 255, 255);
        AssociaImagem(imgcano);

        pcano2.x = 50 + rand()%50;
        pcano2.y = -70;
        CriaQuadrado(30, pcano2);
        Pintar(255, 255, 255);
        AssociaImagem(imgcano);

        grupomario = CriaGrupo();
            p.x = -156;
            p.y = -75;
            CriaRetangulo(30, 55, p); @{ \label{line:ultimoRetangulo}@
            Pintar(255, 255, 255);
            AssociaImagem(imgmario_pre_caminhada);


        t = 0;
        while(t < 100){
            t++;
            Desenha1Frame();
        }

        for(p.x = -156; p.x < 125; p.x += 5){

            if(p.x + raio_pulo > pcano1.x && p.x < pcano1.x + raio_pulo){
                AssociaImagem(imgmario_pre_salto);
                t = 0;
                while(t < 50){
                    t++;
                    Desenha1Frame();
                }

                AssociaImagem(imgmario_salto);
                t = 0;
                pmario = p;
                while(t <= PI){
                    x = -(raio_pulo * cos(t)); //circulo (0,0) com raio 30 (x esta invertido porque ta indo de 0 a PI)
                    y = 50 * sin(t);

                    p.x = pmario.x + raio_pulo + x; //posicao do deslocamento x + raio 30 + posicao inicial do Mario
                    p.y = pmario.y + y;

                    Move(p, grupomario);
                    Desenha1Frame();
                    Desenha1Frame();
                    Desenha1Frame();

                    t+= 0.5;
                }
                p.y = -75;
            }

            if(p.x + raio_pulo > pcano2.x && p.x < pcano2.x + raio_pulo){
                AssociaImagem(imgmario_pre_salto);
                t = 0;
                while(t < 50){
                    t++;
                    Desenha1Frame();
                }

                AssociaImagem(imgmario_salto);
                t = 0;
                pmario = p;
                while(t <= PI){
                    x = -(raio_pulo * cos(t)); //circulo (0,0) com raio 30 (x esta invertido porque ta indo de 0 a PI)
                    y = 50 * sin(t);

                    p.x = pmario.x + raio_pulo + x; //posicao do deslocamento x + raio 30 + posicao inicial do Mario
                    p.y = pmario.y + y;

                    Move(p, grupomario);
                    Desenha1Frame();
                    Desenha1Frame();
                    Desenha1Frame();

                    t+= 0.5;
                }
                p.y = -75;
            }

            AssociaImagem(imgmario_caminhando_1);
            Desenha1Frame();
            Desenha1Frame();
            Desenha1Frame();
            Desenha1Frame();

            Move(p, grupomario);

            AssociaImagem(imgmario_caminhando_2);
            Desenha1Frame();
            Desenha1Frame();
            Desenha1Frame();
            Desenha1Frame();

            p.x += 5;

            Move(p, grupomario);

            AssociaImagem(imgmario_caminhando_3);
            Desenha1Frame();
            Desenha1Frame();
            Desenha1Frame();
            Desenha1Frame();

        }

    AssociaImagem(imgmario_pre_caminhada);
    Desenha();
    return 0;
}
