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


int main(void) {

  Ponto p;
  int   i = 4; //dai pra cima a coisa fica grande e mais lenta
  float   h = 40;

  p.x = -70; p.y = 100; //ordem=1 cabe todo na tela


  MostraPlanoCartesiano(10);
  AbreJanela(LARGURA,ALTURA, "Curvas de Sierpinski");
  PintarFundo(255, 255, 255);


  if (i>0) h /= i*i;
  p=a(i,h, p); p=reta(7,h, p);
  p=b(i,h, p); p=reta(5,h, p);
  p=c(i,h, p); p=reta(3,h, p);
  p=d(i,h, p); p=reta(1,h, p);


  Desenha();

  return 0;
}
