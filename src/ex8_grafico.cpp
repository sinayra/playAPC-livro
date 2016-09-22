#include <playAPC/playapc.h>
#include <math.h>

int main(){
    Ponto p[100];
    int i, j;

    MudaLimitesJanela(125000); @{ \label{line:MudaLimitesJanela}@

    AbreJanela(400, 400, "Criando um grafico");
    PintarFundo(255, 255, 255);
    MostraPlanoCartesiano(7000);

    j = -50;
    for(i = 0; i < 100; i++, j++){
        p[i].x = j;
        p[i].y = -pow(p[i].x, 3);
    }

    CriaGrafico(100, p, 1); @{ \label{line:CriaGrafico}@

    Pintar(255, 0, 0);

    Desenha();

}
