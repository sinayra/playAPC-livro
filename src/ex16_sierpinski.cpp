#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <playAPC/playapc.h>


// desenho realizado no estilo conhecido como   Turtle Graphics
#define LARGURA 1962 //800
#define ALTURA  1280 //600
#define SIZE 180



typedef unsigned int Cardinal;

Ponto a (Cardinal k, float h, Ponto p); @\label{line:pontoA}@
Ponto b (Cardinal k, float h, Ponto p); @\label{line:pontoB}@
Ponto c (Cardinal k, float h, Ponto p); @\label{line:pontoC}@
Ponto d (Cardinal k, float h, Ponto p); @\label{line:pontoD}@


Ponto reta(Cardinal fator, Cardinal ext, Ponto p) {
  // ang é para multiplicar por 45 graus
  Ponto p1;
  double ar = fator * 45.0 * PI/180;

  p1.x = p.x + ext*cos(ar);
  p1.y = p.y + ext*sin(ar);
  CriaReta(p,p1);
  Grafite(2);
  Pintar(0,0,255);
  return p1;
}



Ponto a (Cardinal k, float h, Ponto p) {
  if ( k > 0 ) {
    p=a(k-1,h, p); p=reta(7,h, p);
    p=b(k-1,h, p); p=reta(0,2*h, p);
    p=d(k-1,h, p); p=reta(1,h, p);
    p=a(k-1,h, p);
  }
  return p;
}

Ponto b (Cardinal k, float h, Ponto p) {
  if ( k > 0 ) {
    p=b(k-1,h, p); p=reta(5,h, p);
    p=c(k-1,h, p); p=reta(6,2*h, p);
    p=a(k-1,h, p); p=reta(7,h, p);
    p=b(k-1,h, p);
  }
  return p;
}

Ponto c (Cardinal k, float h, Ponto p) {
  if ( k > 0 ) {
    p=c(k-1,h, p); p=reta(3,h, p);
    p=d(k-1,h, p); p=reta(4,2*h, p);
    p=b(k-1,h, p); p=reta(5,h, p);
    p=c(k-1,h, p);
  }
  return p;
}

Ponto d (Cardinal k, float h, Ponto p) {
  if ( k > 0 ) {
    p=d(k-1,h, p); p=reta(1,h, p);
    p=a(k-1,h, p); p=reta(2,2*h, p);
    p=c(k-1,h, p); p=reta(3,h, p);
    p=d(k-1,h, p);
  }
  return p;
}


int main() {

    Ponto p;
    int   k;
    float   h = 40;

    printf("Insira a ordem para a criacao das curvas: ");
    scanf("%d", &k);

    p.x = -70; p.y = 100; //ordem=1 cabe todo na tela


    MostraPlanoCartesiano(10);
    AbreJanela(800,600, "Curvas de Sierpinski");
    PintarFundo(255, 255, 255);


    if (k>0) h /= k*k;
    p = a(k,h, p); p = reta(7,h, p); //esta chamada da funcao reta calcula o proximo ponto onde a outra reta deve comecar
    p = b(k,h, p); p = reta(5,h, p);
    p = c(k,h, p); p = reta(3,h, p);
    p = d(k,h, p); p = reta(1,h, p);

    Desenha();

return 0;
}
