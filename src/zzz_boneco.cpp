#include <playAPC/playapc.h>

int main(){
    Ponto p;
    AbreJanela(400, 400, "Boneco palito");
    PintarFundo(255, 255, 255);

    p.x = 0;
    p.y = 60;
   CriaCirculo(20, p); //(raio, ponto central)
    Pintar(0, 0, 0);

    p.y = 10;
    CriaElipse(10, 40, p); //(metade do maior raio da elipse, metade do menor raio da elipse, ponto central)
    Pintar(0, 0, 0);

    p.x = -40;
    p.y = 30;
    CriaRetangulo(80, 10, p); //(base, altura, ponto esquerdo inferior)
    Pintar(0, 0, 0);

    p.x = -40;
    p.y = -30;
    CriaTriangulo(80, 40, p); //(base, altura, ponto esquerdo inferior)
    Pintar(0, 0, 0);

    p.x = -15;
    p.y = -40;
    CriaQuadrado(10, p); //(lado, ponto esquerdo inferior)
    Pintar(0, 0, 0);

    p.x = 5;
    p.y = -40;
    CriaQuadrado(10, p);
    Pintar(0, 0, 0);

    Desenha();
}
