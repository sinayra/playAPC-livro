#include <stdio.h>
#include <playAPC/playapc.h>

#define CHAO -70
#define POSX_A -62.5
#define POSX_B -2.5
#define POSX_C 58.5

typedef struct{
    int index, largura, label;
    float posicao;
    char torre;
}discoHanoi;
//discoHanoi.index : se refere ao índice do grupo, retornado pela função CriaGrupo
//discoHanoi.label: qual a numeração do disco, do menor para o maior
//discoHanoi.posicao: em qual posição do plano cartesiano o disco está
//discoHanoi.torre: em qual torre que ele está
//discoHanoi.largura: largura do disco

//Aqui eu conto quantos discos tem em uma torre
int contDiscos(discoHanoi disco[], int discoindex, char torre, int numDiscos){
    int i, total;

    total = 0;
    for(i = 0; i < numDiscos; i++){
        if(i != discoindex){
            if(disco[i].torre == torre)
                total++;
        }
    }
    return total;
}

//Aqui eu movo os discos para a torre
void moveHanoi(int n, discoHanoi discos[], char torre, int numDiscos){
    Ponto p;
    int i, disco, discoindex, auxposicao;

    /////////Procurando o disco que tenho que mover
    for(i = 0; i < numDiscos; i++){
        if(discos[i].label == n){
            disco = discos[i].index; //O grupo que este disco pertence
            discoindex = i; //A posição do vetor de discoHanoi que este disco está
            break;
        }
    }

    //Aqui eu movo na coordenada x o meu disco
    if(torre == 'B'){
        p.x = POSX_B - discos[i].largura/2;
        discos[discoindex].torre = 'B';
    }
    else if (torre == 'C'){
        p.x = POSX_C - discos[i].largura/2;
        discos[discoindex].torre = 'C';
    }
    else{
        p.x = POSX_A - discos[i].largura/2;
        discos[discoindex].torre = 'A';
    }

    //posição do chão + quantos discos tem naquela torre
    p.y = CHAO + contDiscos(discos, discoindex, torre, numDiscos) * 10; //vezes largura de cada disco

    Move(p, disco);

    while(!ApertouTecla(GLFW_KEY_ENTER))
        Desenha1Frame();
}

void hanoi(int n, discoHanoi disco[], char a, char b, char c, int numDiscos){
 /* mova n discos do pino a para o pino b usando
   o pino c como intermediario                    */

    if (n == 1){
        printf("\nmova disco %d de %c para %c\n", n, a, b);
        moveHanoi(n, disco, b, numDiscos);
    }
    else
    {
        hanoi(n - 1, disco, a, c, b, numDiscos);                            // H1
        printf("\nmova disco %d de %c para %c\n", n, a, b);
        moveHanoi(n, disco, b, numDiscos);

        hanoi(n - 1, disco, c, b, a, numDiscos);                            // H2
    }
}

int main(void){
    int numDiscos, i;
    discoHanoi disco[5];
    Ponto p;

    do{
        printf("\nDigite uma quantidade de discos menor ou igual a 5: ");
        scanf("%d", &numDiscos);
    }while(numDiscos > 5 || numDiscos <= 0); //Pergunte a quantidade de discos de novo se o usuário colocar um número maior que 5 ou menor ou igual a 0

    AbreJanela(500, 500, "Torre de Hanoi");
    PintarFundo(255, 255, 255);

    ///////////////////////// Chão e torres /////////////////////////
    CriaGrupo(); //Grupo das coisas que não se mexem
    //Chão
    p.x = -100;
    p.y = -80;
    CriaRetangulo(200, 10, p);
    Pintar(0, 0, 0);

    //A
    p.x = POSX_A;
    p.y = CHAO;
    CriaRetangulo(5, 60, p);
    Pintar(255, 0, 0);

    //B
    p.x = POSX_B;
    p.y = CHAO;
    CriaRetangulo(5, 60, p);
    Pintar(255, 0, 0);

    //C
    p.x = POSX_C;
    p.y = CHAO;
    CriaRetangulo(5, 60, p);
    Pintar(255, 255, 0);

    ///////////////////////// Discos /////////////////////////
    p.y = CHAO;
    for(i = 0; i < numDiscos; i++){

        disco[i].index = CriaGrupo(); //Cada disco tem que estar em um grupo para poderem se mover independente
        disco[i].largura = 10 * (numDiscos - i); //largura do disco pra torre ficar bonitinha
        disco[i].posicao = p.y; //posição original do disco
        disco[i].torre = 'A'; //torre de partida
        disco[i].label = numDiscos - i; //Label para os discos
        p.x = POSX_A - disco[i].largura/2;

        CriaRetangulo(disco[i].largura, 10, p);
        Pintar(rand()%256, rand()%256, rand()%256);

        p.y += 10;
    }

    printf("Agora vou mostrar passo a passo como se resolve esta torre. Aperte enter para o proximo passo");
    while(!ApertouTecla(GLFW_KEY_ENTER))
        Desenha1Frame();

    hanoi(numDiscos, disco, 'A', 'B', 'C', numDiscos);

    printf("\nPronto! E assim que se resolve esta torre!");

    Desenha();
    return 0;
}
