#include <playAPC/playapc.h>

int main(){
    Ponto p; @\label{line:estruturaPonto}@
    AbreJanela(400, 400, "Boneco palito");
    PintarFundo(255, 255, 255);

    p.x = 0;
    p.y = 60;
   @\label{line:CriaCirculo}@CriaCirculo(20, p); //(raio, ponto central)
    Pintar(255, 233, 234);  @\label{line:Pintarm1}@

    p.y = 10;
    @\label{line:CriaElipse}@CriaElipse(10, 40, p); //(metade do maior raio da elipse, metade do menor raio da elipse, ponto central)
    Pintar(255, 233, 234);

    p.x = -40;
    p.y = 30;
    @\label{line:CriaRetangulo}@CriaRetangulo(80, 10, p); //(base, altura, ponto esquerdo inferior)
    Pintar(255, 233, 234);

    p.x = -40;
    p.y = -30;
    @\label{line:CriaTriangulo}@CriaTriangulo(80, 40, p); //(base, altura, ponto esquerdo inferior)
    Pintar(255, 233, 234);

    p.x = -15;
    p.y = -40;
    @\label{line:CriaQuadrado}@CriaQuadrado(10, p); //(lado, ponto esquerdo inferior)
    Pintar(255, 233, 234);

    p.x = 5;
    p.y = -40;
    CriaQuadrado(10, p);
    Pintar(255, 233, 234);

    Desenha();
}
