#include <playAPC/playapc.h>

int main(){
    Ponto p;
    int carro;

    AbreJanela(400, 400, "Carrinho");
    PintarFundo(255, 255, 255);

    carro = CriaGrupo(); @\label{line:CriaGrupo}@
        p.x = -100;
        p.y = 20;
        CriaRetangulo(30, 20, p);
        Pintar(128, 0, 0);

        p.x = -80;
        p.y = 20;
        CriaRetangulo(20, 12, p);
        Pintar(128, 0, 0);

        p.x = -95;
        p.y = 20;
        CriaCirculo(4, p);
        Pintar(0, 0, 0);

        p.x = -75;
        p.y = 20;
        CriaCirculo(4, p);
        Pintar(0, 0, 0);

    p.y = 20;
    for(p.x = -100; p.x < 100; p.x++){
        Move(p, carro); @\label{line:CriaGrupo}@
        Desenha1Frame();
    }
    Desenha();
}
