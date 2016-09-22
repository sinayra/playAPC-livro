#include <playAPC/playapc.h>
#include <stdio.h>
#include <math.h>
int main(){
    float raio, lado, apotema;
    Ponto p1, p2;

    printf("Digite o valor do raio do circulo: ");
    scanf("%f", &raio);

    lado = raio * sqrt(2);
    apotema = lado/2;

    p1.x = 0;
    p1.y = 0;

    p2.x = -apotema;
    p2.y = -apotema;

    AbreJanela(400, 400, "Quadrado inscrito");
    PintarFundo(0, 0, 0);

    CriaCirculo(raio, p1);
    Pintar(255, 0, 0);

    CriaQuadrado(lado, p2);
    Pintar(255, 255, 255);

    Desenha();

    return 0;
}
