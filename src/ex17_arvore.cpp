#include <playAPC/playapc.h>

#define RAD 0.01745

void arvore(Ponto p1, float altura1, float angulo1, float angulo_diff, float profundidade){
    Ponto p2;
    float altura2, angulo2;

    if(0 < profundidade){
        p2.x = p1.x + altura1 * cos(angulo1 * RAD);
        p2.y = p1.y + altura1 * sin(angulo1 * RAD);
        CriaReta(p1, p2);
        Pintar(0, 255, 0);
        Grafite(5.0);

        altura2 = altura1 * 0.8;
        angulo2 = angulo1 + angulo_diff;
        arvore(p2, altura2, angulo2, angulo_diff, profundidade - 1);

        angulo2 = angulo1 - angulo_diff;
        arvore(p2, altura2, angulo2, angulo_diff, profundidade - 1);
    }

}

int main(){
    Ponto p;
    float altura, angulo, profundidade;

    printf("Informe altura:");
    scanf("%f", &altura);

    printf("Informe angulo entre galhos:");
    scanf("%f", &angulo);

    printf("Informe profundidade da recursao:");
    scanf("%f", &profundidade);

    p.x = 0;
    p.y = -80;

    AbreJanela(800,800, "Arvore recursiva");
    PintarFundo(255, 255, 255);

    arvore(p, altura, 90, angulo, profundidade);

    Desenha();

    return 0;
}
