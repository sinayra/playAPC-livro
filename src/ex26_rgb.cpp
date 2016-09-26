#include <playAPC/playapc.h>
#include <stdio.h>
#include <math.h>

#define QTD 22

int main(){
    int R[QTD], G[QTD], B[QTD];
    int Rf[QTD], Gf[QTD], Bf[QTD];
    int mfiltro = 3;
    int somaaux[3];
    Ponto p, pf;
    float dist = 0;

    R[0] = 0; R[QTD-1] = 0;
    G[0] = 0; G[QTD-1] = 0;
    B[0] = 0; B[QTD-1] = 0;

    for(int i = 1; i < QTD-1; i++){
        printf("\n****\nElemento n%d\n****\n", i);

        printf("\nInsira componente R:");
        scanf("%d", &R[i]);
        printf("\nInsira componente G:");
        scanf("%d", &G[i]);
        printf("\nInsira componente B:");
        scanf("%d", &B[i]);

    }

    for(int i = 1; i < QTD - 1; i++){
        somaaux[0] = 0;
        somaaux[1] = 0;
        somaaux[2] = 0;
        for(int j = -1; j < mfiltro - 1; j++){
            somaaux[0] += R[(i + j)];
            somaaux[1] += G[(i + j)];
            somaaux[2] += B[(i + j)];
        }
        Rf[i] = somaaux[0]/mfiltro;
        Gf[i] = somaaux[1]/mfiltro;
        Bf[i] = somaaux[2]/mfiltro;

    }

    AbreJanela(400, 400, "Filtragem Media Movel");
    PintarFundo(255, 255, 255);
    MostraPlanoCartesiano(10);

    p.x = -20;
    p.y = 90;

    pf.x = 10;
    pf.y = 90;
    for(int i = 1; i < QTD - 1; i++){
        CriaQuadrado(10, p);
        Pintar(R[i], G[i], B[i]);
        p.y -= 10;

        CriaQuadrado(10, pf);
        Pintar(Rf[i], Gf[i], Bf[i]);
        pf.y -= 10;

        dist += sqrt(pow(R[i] - Rf[i], 2) + pow(G[i] - Gf[i], 2) + pow(B[i] - Bf[i], 2));

    }
    dist = dist/(QTD-2);

    printf("A distancia euclidiana media e %.2f\n", dist);

    Desenha();
}
