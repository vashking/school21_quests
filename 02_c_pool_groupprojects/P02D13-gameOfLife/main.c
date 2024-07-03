// fixed not recommended warnings
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// date time
#include <time.h>
// screen coordinates
#include <ncurses.h>

// Стандартный размер поля
#define SIZE_X 80
#define SIZE_Y 25

// Работа с полем
int currentField[SIZE_Y + 2][SIZE_X + 2];
int nextField[SIZE_Y + 2][SIZE_X + 2];

/*
Инициализируем все необходимые штуки дрюки для работоспособности игры
Берем ввод типа поля от 1 до 5, исходя из предрасположенной настройки gameRules
6 - рандомное поле, 7 - выход из игры
*/
int init_game();
// Рандомное поле если игрок решил не играть на стандартных картах.
void randomBoard();                   // Функция считывающая поле из файла.
void inputMapFromFile(char *string);  // Считывающая скорость
int set_speed(int *speed);   // Запускает игру на определенной скорости
void start_game(int speed);  // Вычисляет матрицу нового поколения
int newGeneration();  // Вычисление кол-ва живых соседей у каждой клетки
int count_neigh(int row,
                int column);  // Копирует новую матрицу в текущую матрицу
int renewCurrent();           // Задаем границы
void copyMargin();
void print_field();

int main() {
    int speed = 1, out = init_game();
    initscr();
    echo();
    keypad(stdscr, TRUE);
    halfdelay(10);
    noecho();
    while (out % 2 != 0) out = init_game();  // Инициализируем выбор поля.
    if (out == 0) {
        set_speed(&speed);
        start_game(speed);
    }
    endwin();
    return 0;
}

int init_game() {
    int gameVariable, out = 0;

    printf("For start game, please, choose map type:\n");
    printf("1. gameRules1.txt\n");
    printf("2. gameRules2.txt\n");
    printf("3. gameRules3.txt\n");
    printf("4. gameRules4.txt\n");
    printf("5. gameRules5.txt\n");
    printf("6. RANDOM BOARD\n");
    printf("7. Exit\n");

    printf("During the game:\n");
    printf("Up arrow - speed up\n");
    printf("Down arrow - speed down\n");
    printf("Left arrow - quit.\n");

    if (scanf("%d", &gameVariable) != 1) {
        printf("n/a");
        out = 4;
    } else if (gameVariable > 7 || gameVariable < 1) {
        printf("Please, enter 1-6 variable, 7 for exit\n");
        out = 1;
    } else {
        switch (gameVariable) {
            case 1:
                inputMapFromFile("gameRules1.txt");
                break;
            case 2:
                inputMapFromFile("gameRules2.txt");
                break;
            case 3:
                inputMapFromFile("gameRules3.txt");
                break;
            case 4:
                inputMapFromFile("gameRules4.txt");
                break;
            case 5:
                inputMapFromFile("gameRules5.txt");
                break;
            case 6:
                randomBoard();
                break;
            default:
                out = 2;
        }
    }
    return out;
}

void start_game(int speed) {
    int end = 0;
    while (!end) {
        switch (getch()) {
            case KEY_DOWN:
                if (speed > 1) speed--;
                halfdelay(speed);
                break;
            case KEY_UP:
                speed++;
                halfdelay(speed);
                break;
            case KEY_LEFT:
                end = 1;
        }
        print_field();

        end += newGeneration();
        end += renewCurrent();
        copyMargin();
    }
}

void inputMapFromFile(char *string) {
    FILE *f;
    f = fopen(string, "r");
    char **str = (char **)malloc(SIZE_X * SIZE_Y * sizeof(char) + SIZE_Y * sizeof(char *));
    char *ptr = (char *)(str + SIZE_Y);
    int n = 0;

    while (!feof(f)) {
        str[n] = ptr + SIZE_X * n;
        fgets(str[n], SIZE_X, f);
        n++;
    }

    for (int i = 1; i < SIZE_Y + 1; i++) {
        for (int j = 1; j < SIZE_X + 1; j++) {
            if (str[i][j] == '*') {
                currentField[i][j] = 1;
            } else {
                currentField[i][j] = 0;
            }
        }
        printf("\n");
    }

    free(str);
    fclose(f);
}

void print_field() {
    for (int i = 1; i < SIZE_Y + 1; i++) {
        for (int j = 1; j < SIZE_X + 1; j++)
            if (currentField[i][j] == 1)
                printf("*");
            else
                printf(" ");
    }

    refresh();
}

int set_speed(int *speed) {
    int out = 0;

    printf("Enter the speed of the game: \n");

    if (scanf("%d", speed) != 1 || (*speed < 1)) out = 1;

    return out;
}

void randomBoard() {
    unsigned int seed = time(NULL);
    for (int i = 1; i < SIZE_Y + 1; i++) {
        for (int j = 1; j < SIZE_X + 1; j++) {
            currentField[i][j] = rand_r(&seed) % 2;
        }
    }
}

int newGeneration() {
    int out = 1;
    for (int i = 1; i < SIZE_Y + 1; i++) {
        for (int j = 1; j < SIZE_X + 1; j++) {
            int nneighb = count_neigh(i, j);
            if ((currentField[i][j] && (nneighb == 2 || nneighb == 3)) ||
                (!currentField[i][j] && nneighb == 3)) {
                out = 0;
                nextField[i][j] = 1;
            } else {
                nextField[i][j] = 0;
            }
        }
    }
    return out;
}

int count_neigh(int row, int column) {
    int count = 0;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++) {
            if (!((i == 0) && (j == 0))) count += currentField[row + i][column + j];
        }
    return count;
}

void copyMargin() {
    int i = 0, j = 0;
    for (i = 0; i < SIZE_Y + 2; i++) currentField[i][0] = currentField[i][SIZE_X];
    for (i = 0; i < SIZE_Y + 2; i++) currentField[i][SIZE_X + 1] = currentField[i][1];
    for (j = 0; j < SIZE_X + 2; j++) currentField[0][j] = currentField[SIZE_Y][j];
    for (j = 0; j < SIZE_X + 2; j++) currentField[SIZE_Y + 1][j] = currentField[1][j];
    currentField[0][0] = currentField[SIZE_Y][SIZE_X];
    currentField[SIZE_Y + 1][SIZE_X + 1] = currentField[1][1];
    currentField[0][SIZE_X + 1] = currentField[SIZE_Y][1];
    currentField[SIZE_Y + 1][0] = currentField[1][SIZE_X];
}

int renewCurrent() {
    int out = 1;
    for (int i = 0; i < SIZE_Y + 2; i++)
        for (int j = 0; j < SIZE_X + 2; j++) {
            currentField[i][j] = nextField[i][j];
            out = 0;
        }
    return out;
}
