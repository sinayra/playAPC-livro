#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <playAPC/playapc.h>

#define LARGURA 800
#define ALTURA 600
#define SIZE 180

Ponto movaCaneta(Ponto from, double theta, double len) {
  Ponto to;
  double rad = theta*PI/180;
  to.x = from.x + len*cos(rad);
  to.y = from.y + len*sin(rad);
  return to;
}


void koch (Ponto from, double len, double theta, int order) {
  Ponto to;
  double rad = theta*PI/180;

  if (order==0) {
    to.x = from.x + len*cos(rad);
    to.y = from.y + len*sin(rad);
    CriaReta(from, to); Grafite(2); Pintar(255,0,0);
  }
  else {
    koch(from, len/3, theta, order-1);

    to = movaCaneta(from, theta, len/3);
    from = to;//dispensável.
    // seu uso é para tornar intuitiva a chamada abaixo
    koch(from, len/3, theta+60, order-1);

    to = movaCaneta(from, theta+60, len/3);
    from = to;
    koch(from, len/3, theta-60, order-1);

    to = movaCaneta(to, theta-60, len/3);
    from = to;
    koch(from, len/3, theta, order-1);
  }
}


int main(void) {
  int ordem = 6;
  Ponto p0;

  AbreJanela(LARGURA,ALTURA, "Curvas de Koch");
  MostraPlanoCartesiano(10);
  PintarFundo(255, 255, 255);

  p0.x = -100; p0.y = 0.0;


  koch(p0, SIZE, 0, ordem);



  Desenha();

  return 0;
}
