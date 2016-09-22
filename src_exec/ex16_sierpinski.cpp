#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <playAPC/playapc.h>


// desenho realizado no estilo conhecido como   Turtle Graphics
#define LARGURA 800
#define ALTURA  600
#define SIZE 180


typedef unsigned int Cardinal;

Ponto a (Cardinal k, float h, Ponto p, int R, int B, int G);
Ponto b (Cardinal k, float h, Ponto p, int R, int B, int G);
Ponto c (Cardinal k, float h, Ponto p, int R, int B, int G);
Ponto d (Cardinal k, float h, Ponto p, int R, int B, int G);


Ponto reta(Cardinal fator, Cardinal ext, Ponto p, int R, int B, int G) {
  // ang é para multiplicar por 45 graus
  Ponto p1;
  double ar = fator * 45.0 * PI/180;

  p1.x = p.x + ext*cos(ar);
  p1.y = p.y + ext*sin(ar);
  CriaReta(p,p1);
  Grafite(2);
  Pintar(R,G,B);
  return p1;
}



Ponto a (Cardinal k, float h, Ponto p, int R, int B, int G) {
  if ( k > 0 ) {
    p=a(k-1,h, p, 255, 0, 0); p=reta(7,h, p, R, G, B);
    p=b(k-1,h, p, 0, 255, 0); p=reta(0,2*h, p, R, G, B);
    p=d(k-1,h, p, 255, 255, 0); p=reta(1,h, p, R, G, B);
    p=a(k-1,h, p, 255, 0, 0);
  }
  return p;
}

Ponto b (Cardinal k, float h, Ponto p, int R, int B, int G) {
  if ( k > 0 ) {
    p=b(k-1,h, p, 0, 255, 0); p=reta(5,h, p, R, G, B);
    p=c(k-1,h, p, 0, 0, 255); p=reta(6,2*h, p, R, G, B);
    p=a(k-1,h, p, 255, 0, 0); p=reta(7,h, p, R, G, B);
    p=b(k-1,h, p, 0, 255, 0);
  }
  return p;
}

Ponto c (Cardinal k, float h, Ponto p, int R, int B, int G) {
  if ( k > 0 ) {
    p=c(k-1,h, p, 0, 0, 255); p=reta(3,h, p, R, G, B);
    p=d(k-1,h, p, 255, 255, 0); p=reta(4,2*h, p, R, G, B);
    p=b(k-1,h, p, 0, 255, 0); p=reta(5,h, p, R, G, B);
    p=c(k-1,h, p, 0, 0, 255);
  }
  return p;
}

Ponto d (Cardinal k, float h, Ponto p, int R, int B, int G) {
  if ( k > 0 ) {
    p=d(k-1,h, p, 255, 255, 0); p=reta(1,h, p, R, G, B);
    p=a(k-1,h, p, 255, 0, 0); p=reta(2,2*h, p, R, G, B);
    p=c(k-1,h, p, 0, 0, 255); p=reta(3,h, p, R, G, B);
    p=d(k-1,h, p, 255, 255, 0);
  }
  return p;
}


int main(void) {

  Ponto p;
  int   i = 2; //dai pra cima a coisa fica grande e mais lenta
  float   h = 40;

  p.x = -70; p.y = 100; //ordem=1 cabe todo na tela


  MostraPlanoCartesiano(10);
  AbreJanela(LARGURA,ALTURA, "Curvas de Sierpinski");
  PintarFundo(255, 255, 255);


  if (i>0) h /= i*i;
  p=a(i,h, p, 255, 0, 0); p=reta(7,h, p, 0, 0, 0);
  p=b(i,h, p, 0, 255, 0); p=reta(5,h, p, 0, 0, 0);
  p=c(i,h, p, 0, 0, 255); p=reta(3,h, p, 0, 0, 0);
  //p=d(i,h, p, 255, 255, 0); p=reta(1,h, p, 0, 0, 0);


  Desenha();

  return 0;
}
