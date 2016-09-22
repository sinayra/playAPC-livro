#include <playAPC/playapc.h>

int main (){
    int angulo = 1;
    int helices, moinho;
    Ponto p1, p2;

    AbreJanela(400, 400, "Moinho de Vento" );
    PintarFundo(217,255,255);

    moinho = CriaGrupo();

        p1.x = -20;
        p1.y = -20;
        CriaTriangulo(40,60,p1);
        Pintar(255, 255, 0);

        p1.x = -20;
        p1.y = -100;
        CriaRetangulo(40,80,p1);
        Pintar(0, 255, 0);

    helices = CriaGrupo();

        p1.x = 0;
        p1.y = 0;
        // Hélice 1
        p2.x = 0;
        p2.y = 70;
        CriaReta(p1, p2);
        Pintar(255, 255, 255);
        Grafite(8);

        // Hélice 2
        p2.x = 70;
        p2.y = 0;
        CriaReta(p1, p2);
        Pintar(255, 255, 255);
        Grafite(8);

        // Helice 3
        p2.x = 0;
        p2.y = -70;
        CriaReta(p1, p2);
        Pintar(255, 255, 255);
        Grafite(8);

        // Helice 4
        p1.x = -70;
        p2.y = 0;
        CriaReta(p1, p2);
        Pintar(255, 255, 255);
        Grafite(8);

        p1.x = 0;
        p1.y = 0;
        CriaCirculo(5,p1);
        Pintar(255,200,0);

    while( angulo > 0){
        Desenha1Frame();
        Gira(angulo, helices); @\label{line:Giram1}@
        angulo++;
    }

    Desenha();
    return 0;
}
