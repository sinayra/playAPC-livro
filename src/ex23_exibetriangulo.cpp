#include <stdio.h>
#include <playAPC/playapc.h>
#include <math.h>

int main(){
    Ponto p1, p2, p3;
    float a, b, c, diffa, diffb, diffc, somaa, somab, somac;
    int triangulo = 1;

    printf("Indique coordenada x do ponto 1:");
    scanf("%f", &p1.x);
    printf("Indique coordenada y do ponto 1:");
    scanf("%f", &p1.y);

    printf("Indique coordenada x do ponto 2:");
    scanf("%f", &p2.x);
    printf("Indique coordenada y do ponto 2:");
    scanf("%f", &p2.y);

    printf("Indique coordenada x do ponto 3:");
    scanf("%f", &p3.x);
    printf("Indique coordenada y do ponto 3:");
    scanf("%f", &p3.y);

    a = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    b = sqrt(pow(p3.x - p2.x, 2) + pow(p3.y - p2.y, 2));
    c = sqrt(pow(p3.x - p1.x, 2) + pow(p3.y - p1.y, 2));

    printf("a: %f \t b: %f \t c: %f \n", a, b, c);

    diffa = fabs(b - c);
    somaa = b + c;

    diffb = fabs(a - c);
    somab = a + c;

    diffc = fabs(a - b);
    somac = a + b;

    if(diffa < a && a < somaa){
        if(diffb < b && b < somab){
            if(diffc < c && c < somac){

                if(a == b && a == c){
                    AbreJanela(400, 400, "Triangulo equilatero");
                    PintarFundo(255, 255, 255);
                    MostraPlanoCartesiano(10);

                    CriaPoligono(3, p1, p2, p3);
                    Pintar(51, 51, 204);
                }
                else if(a == b || a == c || b == c){
                    AbreJanela(400, 400, "Triangulo isosceles");
                    PintarFundo(255, 255, 255);
                    MostraPlanoCartesiano(10);

                    CriaPoligono(3, p1, p2, p3);
                    Pintar(0, 204, 153);
                }
                else{
                    AbreJanela(400, 400, "Triangulo escaleno");
                    PintarFundo(255, 255, 255);
                    MostraPlanoCartesiano(10);

                    CriaPoligono(3, p1, p2, p3);
                    Pintar(0, 0, 0);
                }
                Desenha();
            }
            else{
                triangulo = 0;
            }
        }
        else{
            triangulo = 0;
        }
    }
    else{
        triangulo = 0;
    }

    if(!triangulo){
        printf("Nao satisfaz existencia de triangulo");
    }

    return 0;
}
