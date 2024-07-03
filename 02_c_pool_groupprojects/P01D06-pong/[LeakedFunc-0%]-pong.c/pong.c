#include <stdio.h>
#include <stdlib.h>

#define MAX_H 25
#define MAX_W 80
#define ballSize 1
#define rocketSize 3

char field[MAX_W+1][MAX_H];
int startedGame = 0;

struct rocket {
    int posY;
    int rocketLength;
    int rocketScore;
};

struct rocket r1 = {MAX_H/2, 3, '0'};
struct rocket r2 = {MAX_H/2, 3, '0'};

struct ballStruct {
    int ballPosX;
    int ballPosY;
};

struct ballStruct ball = {MAX_H/2, 0};

void initGrid() {

    if(ball.ballPosX == 1) {
        ball.ballPosX = MAX_W/2;
        ball.ballPosY = 0;
        r2.rocketScore++;
    }
    if(ball.ballPosX == 77) {
        ball.ballPosX = MAX_W/2;
        ball.ballPosY = 0;
        r1.rocketScore++;
    }

    for (int h = 0; h < MAX_H; h++) {
        for(int w = 0; w < MAX_W; w++) {
            field[w][h] = ' ';
        }
        field[MAX_W][h] = '\0';
    }

    field[MAX_W/2-6][3] = r1.rocketScore;
    field[MAX_W/2+6][3] = r2.rocketScore;

    for(int i = 0; i < MAX_H; i++) {
        field[MAX_W/2][i] = '|';
    }

    for (int i = 0; i < MAX_W; i++) {
        field[i][0] = '-';
        field[i][MAX_H-1] = '-';
    }

    ball.ballPosX += 1;
    ball.ballPosY += 1;
    field[ball.ballPosX][ball.ballPosY] = 'X';
}

void showField() {
    for(int i = 0; i < MAX_H; i++) {
        for(int j = 0; j < MAX_W; j++) {
            printf("%c", field[j][i]);
        }
        printf("\n");
    }
}

void showRocket() {
    
    for (int i = r1.posY; i < r1.posY+r1.rocketLength; i++){
        field[2][i] = '*';
    }

    for (int i = r2.posY; i < r2.posY+r2.rocketLength; i++){
        field[77][i] = '*';
    }
}

void gameInput(inputKey) {
    switch(inputKey)
    {
        case 'A':
        {
            if (r1.posY != 1)
            r1.posY--;
            break;
        }
        case 'Z':
        {
            if (r1.posY != 21)
            r1.posY++;
            break;
        }
        case 'K':
        {
            if (r2.posY != 1)
            r2.posY--;
            break;
        }
        case 'M':
        {
            if (r2.posY != 21)
            r2.posY++;
            break;
        }
        case 'Q':
        {
            startedGame = 0; break;
        }
    }
}

void startGame() {
    char param;
    while (startedGame) {
        showRocket();
        showField();
        initGrid();  
        scanf("%c", &param);
        gameInput(param);
    }

    system("clear");
    printf("Спасибо за игру!\nИгра окончена со счетом: %c | %c\n", r1.rocketScore, r2.rocketScore);
    return;
}

int main() {
    
    initGrid(); 
    startedGame = 1;
    startGame();
   

    return 0;
}