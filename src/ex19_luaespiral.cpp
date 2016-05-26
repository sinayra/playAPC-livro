#include <playAPC/playapc.h>
#include <math.h>

int main(){

    float t, phi, dx, dy, d;
    Ponto p, q, r;
    int terra, lua, traj, boquinha; //grupos

    AbreJanela(600, 600, "Lua em espiral que atinge a Terra");
    //MostraPlanoCartesiano(10);
    PintarFundo(0, 0, 0);


    terra = CriaGrupo();
    p.x = 0;
    p.y = 0;
    CriaCirculo(30, p); Pintar(0, 0, 255);

    //terrinhas
    p.x = -22;
    p.y = -20;
    CriaRetangulo(10, 20, p); Pintar(0, 128, 0);
    p.x = -20;
    p.y = 5;
    CriaRetangulo(20, 10, p); Pintar(0, 128, 0);
    p.x = 8;
    p.y = 15;
    CriaRetangulo(15, 2, p); Pintar(0, 128, 0);
    //olhinhos
    p.x = 10;
    p.y = 10;
    CriaCirculo(2, p); Pintar(255, 255, 255);
    p.x = 20;
    p.y = 10;
    CriaCirculo(2, p); Pintar(255, 255, 255);
    p.x = 10;
    p.y = 10;
    CriaCircunferencia(2, p); Pintar(0, 0, 0);
    p.x = 20;
    p.y = 10;
    CriaCircunferencia(2, p); Pintar(0, 0, 0);
    p.x = 10;
    p.y = 10;
    CriaCircunferencia(2.2, p); Pintar(0, 0, 0);
    p.x = 20;
    p.y = 10;
    CriaCircunferencia(2.2, p); Pintar(0, 0, 0);

    //boquinha
    p.x = 5;
    p.y = 0;
    q.x = 20;
    q.y = 0;
    r.x = 10;
    r.y = -5;
    CriaPoligono(3, p, q, r); Pintar(255, 255, 255);

    lua = CriaGrupo();
    p.x = 0;
    p.y = 0;
    CriaCirculo(10, p); Pintar(127, 127, 127);

    //Cria grupo da trajetoria
    traj = CriaGrupo();
    q.x = (10 * 4*PI)*cos(4*PI);
    q.y = (10 * 4*PI)*sin(4*PI);

    CriaPonto(q); Grafite(2); Pintar(87, 87, 87); //Preciso criar o primeiro ponto
    for (t = 4*PI; t > 0 ; t -= .05){
        phi = 10 * t; //polar
        p.x = phi*cos(t);
        p.y = phi*sin(t);

        Move(p, lua);

        dx = q.x - p.x;
        dy = q.y - p.y;
        d = sqrt(dx*dx + dy*dy);

        if(d > 5){ //Distancia para intercalar pontos
            CriaPonto(p); Grafite(3); Pintar(87, 87, 87);
            q = p;
        }

        dx = p.x;
        dy = p.y;
        d = sqrt(dx*dx + dy*dy);
        if(d <= 30 + 10) //Se distancia entre os centro da lua e da terra for menor que a soma dos raios, colidiu
            break;

        Desenha1Frame();
    }
    p.x += 30; //mais raio da terra
    p.y += 30; //mais raio da terra

    //cria um grupo separado pra boquinha
    boquinha = CriaGrupo();
    q.x = 12;
    q.y = -5;
    CriaCirculo(10, q); Pintar(0, 0, 255);
    q.x = 15;
    q.y = 2;
    CriaCirculo(2.5, q); Pintar(255, 255, 255);
    Redimensiona(1, 1.5, boquinha);

    q.x = 15;
    q.y = -6;
    for(t = 0; t < 100; t+= .05){
        p.x += t;
        p.y += t;

        Move(p, terra);

        q.x += t;
        q.y += t;
        Move(q, boquinha);
        Desenha1Frame();
    }

    Desenha();

    return 0;
}
