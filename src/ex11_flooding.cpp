#include <playAPC/playapc.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define TAM 20

typedef struct{
    int i, j;
    float valor;
}tipoVizinho;

typedef struct{
    int earth, water;
}Cell;

int checkPosition(int x, int y){
    return ((x >= 0 && x < TAM) && (y >= 0 && y < TAM));
}

int getCurrentLevel(Cell m){
    return m.water + m.earth;
}


int canFlood(Cell other, Cell current){
    if ((getCurrentLevel(current) >  getCurrentLevel(other) + 1) && current.water > 0)
        return 1;
    else
        return 0;
}

// Reduces the water level of the cell and increases the water level
// of another cell.
// Returns true if successful, false otherwise
int flood(Cell *other, Cell *current){
    if ((*other).earth == -1)
        return 0;

    if(canFlood(*other, *current)){
        (*current).water--;
        (*other).water++;

        return 1;
    }
    else
        return 0;

}

Cell getLowerNeighbour(int x, int y, int *nx, int *ny, Cell board[TAM][TAM]){
    Cell lowerCell;
    int new_x;
    int new_y;

    //inicialization
    lowerCell.earth = -1;
    lowerCell.water = -1;

    *nx = -1;
    *ny = -1;

    // Upper left
    new_x = x - 1;
    new_y = y - 1;

    if (checkPosition(new_x, new_y)){
        if (lowerCell.earth == -1 || getCurrentLevel(board[new_x][new_y]) < getCurrentLevel(lowerCell)){
            lowerCell = board[new_x][new_y];
            *nx = new_x;
            *ny = new_y;
        }
    }

    // Upper
    new_x = x;
    new_y = y - 1;

    if (checkPosition(new_x, new_y)){
        if (lowerCell.earth == -1 || getCurrentLevel(board[new_x][new_y]) < getCurrentLevel(lowerCell)){
            lowerCell = board[new_x][new_y];
            *nx = new_x;
            *ny = new_y;
        }
    }

    // Upper right
    new_x = x + 1;
    new_y = y - 1;

    if (checkPosition(new_x, new_y)){
        if (lowerCell.earth == -1 || getCurrentLevel(board[new_x][new_y]) < getCurrentLevel(lowerCell)){
            lowerCell = board[new_x][new_y];
            *nx = new_x;
            *ny = new_y;
        }
    }

    // Left
    new_x = x - 1;
    new_y = y;

    if (checkPosition(new_x, new_y)){
        if (lowerCell.earth == -1 || getCurrentLevel(board[new_x][new_y]) < getCurrentLevel(lowerCell)){
            lowerCell = board[new_x][new_y];
            *nx = new_x;
            *ny = new_y;
        }
    }

    // Right
    new_x = x + 1;
    new_y = y;

    if (checkPosition(new_x, new_y)){
        if (lowerCell.earth == -1 || getCurrentLevel(board[new_x][new_y]) < getCurrentLevel(lowerCell)){
            lowerCell = board[new_x][new_y];
            *nx = new_x;
            *ny = new_y;
        }
    }

    // Bottom left
    new_x = x - 1;
    new_y = y + 1;

    if (checkPosition(new_x, new_y)){
        if (lowerCell.earth == -1 || getCurrentLevel(board[new_x][new_y]) < getCurrentLevel(lowerCell)){
            lowerCell = board[new_x][new_y];
            *nx = new_x;
            *ny = new_y;
        }
    }

    // Bottom
    new_x = x;
    new_y = y + 1;

    if (checkPosition(new_x, new_y)){
        if (lowerCell.earth == -1 || getCurrentLevel(board[new_x][new_y]) < getCurrentLevel(lowerCell)){
            lowerCell = board[new_x][new_y];
            *nx = new_x;
            *ny = new_y;
        }
    }

    // Bottom right
    new_x = x - 1;
    new_y = y + 1;

    if (checkPosition(new_x, new_y)){
        if (lowerCell.earth == -1 || getCurrentLevel(board[new_x][new_y]) < getCurrentLevel(lowerCell)){
            lowerCell = board[new_x][new_y];
            *nx = new_x;
            *ny = new_y;
        }
    }

    return lowerCell;
}

void imprimeTerminal(Cell m[TAM][TAM], int starti, int startj){

    printf("\n\n");
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if(i == starti && j == startj)
                printf("[%d(%d)] ", m[i][j].earth, m[i][j].water);
            else
                printf("%d(%d) ", m[i][j].earth, m[i][j].water);
        }
        printf("\n");
    }
}

void floodNeighbours(int x, int y, Cell board[TAM][TAM], int mShow[TAM][TAM]){
    // Find lower
    int nx, ny; // Neighbour x and neigbour y
    Cell lowerCell;

    //Loop while has lower

    lowerCell = getLowerNeighbour(x, y, &nx, &ny, board);

    while(flood(&lowerCell, &board[x][y])){
        //Pintar(255, 0, 0, QUADRADO, mShow[x][y]);
        // PLACEHOLDER for testing purpouses
        //printf("\nMoved water from ({%d},{%d}) to ({%d},{%d})\n", x, y, nx, ny);
        board[nx][ny] = lowerCell;
        //Pintar(0, 0, board[nx][ny].water + board[nx][ny].earth, QUADRADO, mShow[nx][ny]);
        //Desenha1Frame();

        floodNeighbours(nx, ny, board, mShow);
        lowerCell = getLowerNeighbour(x, y, &nx, &ny, board);

        Pintar(0, 0, board[x][y].water + board[nx][ny].earth, QUADRADO, mShow[x][y]);
    }
}

int main(){
    Cell board[TAM][TAM];
    int lowest = INT_MAX;
    int mShow[TAM][TAM];
    int starti, startj;
    int amount, gen = 0;
    Ponto p;

    AbreJanela(600, 600, "Int Geiser");
    //srand(time(NULL));

    p.y = 90;
    for(int i = 0; i < TAM; i++){
        p.x = -100;
        for(int j = 0; j < TAM; j++){
            board[i][j].earth = rand()%255;
            board[i][j].water = 0;

            mShow[i][j] = CriaQuadrado(10, p);
            Pintar(board[i][j].earth, 255, 0);
            p.x += 10;

            if(board[i][j].earth < lowest){
                lowest = board[i][j].earth;
                starti = i;
                startj = j;
            }
        }
        p.y -= 10;
    }

    printf("***Initial Configuration***\n");
    //imprimeTerminal(board, starti, startj);

    Pintar(255, 0, 0, QUADRADO, mShow[starti][startj]);
    while(!ApertouTecla(GLFW_KEY_ENTER))
        Desenha1Frame();

    Pintar(0, 0, board[starti][startj].water + board[starti][startj].earth, QUADRADO, mShow[starti][startj]);
    amount = 1;
    while(board[starti][startj].water + board[starti][startj].earth != 257){
        printf("\n\n****%dth generation\n", ++gen);
        //riseLevel
        board[starti][startj].water += amount;

        floodNeighbours(starti, startj, board, mShow);
        //imprimeTerminal(board, starti, startj);

        Desenha1Frame();
    }

    Desenha();

    return 0;
}
