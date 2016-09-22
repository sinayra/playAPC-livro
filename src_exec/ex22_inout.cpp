#include <playAPC/playapc.h>
#include <stdio.h>
#include <math.h>
int main(){
    float raio, d;
    Ponto centro, p;

    printf("Digite o valor do raio da circunferencia: ");
    scanf("%f", &raio);
    printf("\nDigite a posicao x do centro da circunferencia: ");
    scanf("%f", &centro.x);
    printf("\nDigite a posicao y do centro da circunferencia: ");
    scanf("%f", &centro.y);

    printf("\nDigite a posicao x de um ponto: ");
    scanf("%f", &p.x);
    printf("\nDigite a posicao y de um ponto: ");
    scanf("%f", &p.y);

    d = sqrt(pow(centro.x - p.x, 2) + pow(centro.y - p.y, 2));

    if(d > raio){
        AbreJanela(400, 400, "Ponto fora da circunferencia");
    }
    else{
        AbreJanela(400, 400, "Ponto dentro da circunferencia");
    }

    PintarFundo(255, 255, 255);
    MostraPlanoCartesiano(10);

    CriaCircunferencia(raio, centro);
    Pintar(255, 0, 0);

    CriaPonto(p);
    Pintar(0, 0, 255);
    Grafite(10);
    Desenha();

    return 0;
}
