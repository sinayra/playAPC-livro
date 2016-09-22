#include <playAPC/playapc.h>

int main(){
    Ponto p1, p2, p3;
    AbreJanela(400, 400, "Estrela de Davi");

    p1.x = -25;
    p1.y = 0;
    CriaTriangulo(50, 50, p1); //(base, altura)
    Pintar(255, 255, 0);

    p1.x = -25;
    p1.y = 35;

    p2.x = 25;
    p2.y = 35;

    p3.x = 0;
    p3.y = -15;
    CriaPoligono(3, p1, p2, p3); //(quantidade de pontos, p1, p2, ...)
    Pintar(255, 255, 0);

    Desenha();
}
