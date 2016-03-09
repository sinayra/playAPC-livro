#include <playCB/playcb.h>
#include <stdio.h>
#include <math.h>

#define HIP 50
#define PI 3.14
int main(){
    int angulo;
    float anguloRad;
    Ponto p1, p2;

    printf("Digite um angulo de 0 a 360 graus:");
    scanf("%d", &angulo);

    p1.x = 0;
    p2.x = 0;

    anguloRad = (PI * angulo)/180;

    p2.y = sin(anguloRad) * HIP;
    p2.x = cos(anguloRad) * HIP;

    AbreJanela(400, 400, "Quadrante da reta");
    PintarFundo(255, 255, 255);
    MostraPlanoCartesiano(10);

    CriaReta(p1, p2);

    if(p2.x > 0){
        if(p2.y > 0)
            Pintar(255, 0, 0); //vermelho: 1 quadrante
        else
            Pintar(0, 0, 0); //preto: 4 quadrante
    }
    else{
        if(p2.y > 0)
            Pintar(0, 255, 0); //verde: 2 quadrante
        else
            Pintar(0, 0, 255); //azul: 3 quadrante
    }

    Desenha();

}
