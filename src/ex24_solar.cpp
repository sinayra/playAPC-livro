#include <playAPC/playapc.h>
#include <math.h>

int main () {
  Ponto p1, p2, p3;
  int orbitalua, terra, lua, sol;
  double ang, focoSol, focoTerra;

  AbreJanela (400,400, "Sistema Solar");
  PintarFundo (0, 0, 0);


  //CriaElipse(70, 50 , p1); //Órbita da Terra
  for(ang = 0; ang < 2*PI; ang += 0.01){
    p1.x = 70*cos(ang);
    p1.y = 50*sin(ang);

    CriaPonto(p1);
    Pintar (255,0,0);  Grafite(3);
  }

  focoSol = sqrt(pow(70, 2) - pow(50, 2)); //a² = b² + c²

  orbitalua = CriaGrupo();
  //CriaElipse(15, 10, p1); //Órbita da Lua
  for(ang = 0; ang < 2*PI; ang+= 0.01){
    p1.x = 13*cos(ang);
    p1.y = 11*sin(ang);

    CriaPonto(p1);
    Pintar (0,255,255);
  }

  focoTerra = sqrt(pow(13, 2) - pow(11, 2)); //a² = b² + c²

  p1.y = 0;

  p1.x = focoTerra;
  terra = CriaGrupo();
  CriaCirculo(5, p1); Pintar (0,0,255); //Terra

  p1.x = 0;
  lua = CriaGrupo();
  CriaCirculo(2, p1); Pintar (100, 100, 100);//Lua


  p1.x = focoSol;
  sol = CriaGrupo();
  CriaCirculo(10, p1); Pintar (255,255,0); //Sol


  for (ang = 0;  ; ang +=.01) {
    p2.x = 70*cos(ang);
    p2.y = 50*sin(ang);
    Move(p2,terra);//translada Terra para sua órbita

    p3.x = 13*cos(ang*15)+ p2.x + focoTerra;
    p3.y = 11*sin(ang*15)+ p2.y;
    Move(p3,lua);//translada Lua para sua órbita


    p2.x += 13 + focoTerra;
    Move(p2,orbitalua);//em torno da Terra

    Desenha1Frame();
  }
  Desenha ();//(desnecessário) mantém janela aberta
  return 0;
}
