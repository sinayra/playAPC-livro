#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <playAPC/playapc.h>

#define LARGURA 800 //1962
#define ALTURA  600 //1280
#define SIZE 180

Ponto movaCaneta(Ponto from, double theta, double len) {
  Ponto to;
  double rad = theta*PI/180;
  to.x = from.x + len*cos(rad);
  to.y = from.y + len*sin(rad);
  return to;
}


Ponto koch (Ponto from, double len, double theta, int order) {
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
  return movaCaneta(from, theta, len/3);
}

void floco_de_neve(int ordem) {
  Ponto p0;
  p0.x = -45.0; p0.y = 26.0;//centro do floco de neve


  p0 = koch(p0, SIZE/2,    0, ordem);
  p0 = koch(p0, SIZE/2, -120, ordem);
  p0 = koch(p0, SIZE/2,  120, ordem);


}


int main(void) {
  int ordem = 6;


  MostraPlanoCartesiano(10);
  AbreJanela(LARGURA,ALTURA, "Flocos de Neve");
  PintarFundo(255, 255, 255);

  floco_de_neve(ordem);

  Desenha();

  return 0;
}
