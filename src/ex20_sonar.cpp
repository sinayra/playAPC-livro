#include <playAPC/playapc.h>
#include <math.h>

int tela_radar (int aros) {
  int grp = CriaGrupo();
  Ponto p; p.x = 0; p.y = 0;
  for( ; aros > 0; aros--) {
    CriaCircunferencia (10*aros, p);
    Pintar (0, 100, 0);  Grafite(3);
  }
  return grp;
}


int ballon (void) {
  int ufo = CriaGrupo();
  Ponto p;
  p.x = -10;
  p.y = -50;
  CriaPonto(p); Pintar(255, 0, 0); Grafite(10);
  return ufo;
}

int fly (void) {
  int fs = CriaGrupo();
  Ponto p;
  p.x = -10;   p.y = -50;
  CriaPonto(p);
  Pintar(0, 255, 0); Grafite(10);
  return fs;
}

int cacas (void) {
  int cc = CriaGrupo();
  Ponto p;
  p.x = 0;      p.y = 0;
  CriaPonto(p);
  Pintar(0, 0, 255); Grafite(5);
  return cc;
}

int scanner (int range) {
  Ponto p, q;
  int reta = CriaGrupo();
  p.x = 0;    p.y = 0;
  q.x = 0;    q.y = 10*range;
  CriaReta(p, q);
  Pintar (100, 100, 100); Grafite(5);
  return reta;
}


int main (int argc, char * argv[]) {

  AbreJanela (900, 900, "Marvin x Bugs Bunny");
  PintarFundo (255, 255, 255);

  int radar = tela_radar(12);
  int reta = scanner(12);
  int bb  = ballon();
  int marvin = fly();
  int f20 = cacas();
  Ponto p, q, r;

  int dir = 1;

  /*
    os caças F20 ficam rodando feito perus na Lemniscata de Bernoulli
    equação paramétrica:
     x = a \cos t \sqrt{2 \cos (2t)}; \qquad y = a \sin t \sqrt{2 \cos (2t)}

   */

  double theta = 2*PI, alpha = theta;
  while(1) {

    Gira(alpha*100, reta);
    alpha += 0.01;

    /*
       cacas americanos patrulhando a casa quase branca
     */
    r.x = 50*cos(alpha)*sqrt(2*cos(2*alpha));
    r.y = 50*sin(alpha)*sqrt(2*cos(2*alpha));
    Move(r, f20);
    //Os caças acabam aqui

    //outros objetos abaixo
    if (theta > 0) theta = theta - 0.01;
    else {
      theta = 4*PI;
      dir = -dir;
    }
    p.x = 50*(cos(theta) + 0.5*cos(2*theta));
    p.y = 50*(sin(theta) + 0.5*sin(2*theta))+theta;
    //What's up, doc?
    Move(p, bb);//the old pal bugsbunny to save the day!


    q.x = 200*cos(theta*dir)/theta*dir;
    q.y = 200*sin(theta*dir)/theta*dir;
    Move(q, marvin);//Marvin, the martian, who else?


    Desenha1Frame();
  }

  Desenha ();

  return 0;
}
