#include <playAPC/playapc.h>
#include <math.h>

int main (int argc, char * argv[]) {

  AbreJanela (960,960, "Galaxia Espiral de 2 brancos");

  /*
    Espiral Hiperbólica: equação em coordenadas cartesianas
       x = a*cos(t)/t
       y = a*sin(t)/t

       a é a assintota para y (reta paralela ao eixo x)
       t equivalente ao angulo em coordenadas polares
   */
  Ponto p, q, r;

  //  for (double t = 0; t < 4*PI; t += .01){

    /* espiral hiperbolica, caminhando do "fim" pro centro (0,0)
    p.x = 100*cos(t)/t;
    p.y = 100*sin(t)/t;
    */
    int k = 0;
  for (double t = 4*PI; t > 0 ; t -= .05) {
    p.x = 100*cos(t)/t;         q.x = -p.x;
    p.y = 100*sin(t)/t;         q.y = -p.y;

    printf("p.x: %f\t p.y: %f\n", p.x, p.y);
    printf("q.x: %f\t q.y: %f\n", q.x, q.y);

    CriaPonto (p);
    Pintar (200, 30, 100);
    Grafite(3);

    CriaPonto (q);
    Pintar (100, 30, 200);
    Grafite(3);

    Desenha1Frame();
    k++;
  }


  //A massive Black Hole in the very centre
  //If you want to see (the unseeable) black hole
  //paint the background on a different colour
  r.x =0;     r.y = 0;
  CriaCirculo(8, r);
  Pintar (0, 0,  0);

  for (double t=0;  ; t += .5) {
    Gira(t);
    Desenha1Frame();

    //Depois de um tempinho, pinta o fundo de branco pra mostrar
    //o buraco negro
    if ( t > 200 ) PintarFundo (255, 255, 255);

    //quebra o loop e encerra o programa
    if(ApertouTecla(GLFW_KEY_ENTER)) return 0;
  }

}

