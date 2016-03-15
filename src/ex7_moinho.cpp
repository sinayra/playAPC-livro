/* *
 UnB - Professor : Ralha - Computação Básica
 Aluno : Pedro Paulo de Pinho Matos
 Matrícula : 14/0070354
 */

#include <stdlib.h>
#include <stdio.h>
#include <playAPC/playapc.h>


int main (int argc, char* argv[]){
 int angulo =1;

 AbreJanela(1024, 768, "Moinho de Vento" );
 PintarFundo(255,255,255);
 Ponto p,q, r;

 int moinho = CriaGrupo();
 Ponto x, y;
 x.x = -20; x.y = -20; CriaTriangulo(40,60,x); Pintar(255,255,0);
 y.x = -20; y.y = -100; CriaRetangulo(40,80,y); Pintar(0,255,0);

 int grupo = CriaGrupo(); // Hélice 1
 q.x = 0; q.y = 0; r.x = 0; r.y = 70;
 CriaReta(q,r); Pintar(255,0,0); Grafite(8);

 // Hélice 2
 q.x = 0; q.y = 0; r.x = 70; r.y = 0;
 CriaReta(q,r); Pintar(255,0,0); Grafite(8);

 // Helice 3
 q.x = 0; q.y = 0; r.x = 0; r.y = -70;
 CriaReta(q,r); Pintar(255,0,0); Grafite(8);

 // Helice 4
 q.x = 0; q.y = 0; r.x = -70; r.y = 0;
 CriaReta(q,r); Pintar(255,0,0); Grafite(8);

 p.x = 0; p.y = 0;
 CriaCirculo(5,p); Pintar(0,0,0); Grafite(25);

 while( angulo > 0){
     Desenha1Frame();
     Gira(angulo,grupo);
     angulo ++;
 }

 return 0;
}
