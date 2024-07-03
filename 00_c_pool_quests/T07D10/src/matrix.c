#include <stdio.h>
#include <stdlib.h>
#define SMAX 100

int getChoice();
int getSize(int* height, int* width);
int input(int **matrix, int height, int width);
void output(int **matrix, int height, int width);
void transform(int *buf, int **matr, int n, int m);
void staticAllocation(int ***matrix);
void dynamicAllocation1(int ***matrix, int height, int width);
void dynamicAllocation2(int ***matrix, int height, int width);
void dynamicAllocation3(int ***matrix, int height, int width);


int main() {
    int is_error = 0;
    int height, width;
    int **matrix;
    int choice = getChoice();
    if (choice == -1)
        is_error = 1;
    if (is_error == 0)
        if (getSize(&height, &width) == -1)
            is_error = 1;
    if (is_error == 0) {
            switch (choice) {
                case 1:
                    staticAllocation(&matrix);
                    break;
                case 2:
                    dynamicAllocation1(&matrix, height, width);
                    break;
                case 3:
                    dynamicAllocation2(&matrix, height, width);
                    break;
                case 4:
                    dynamicAllocation3(&matrix, height, width);
                    break;
            }
    }
    if (is_error == 0)
        is_error = input(matrix, height, width);
    if (is_error == 0)
        output(matrix, height, width);
    else
        printf("n/a");
    return is_error;
}

int getChoice() {
    int choice;
    if ((scanf("%d", &choice) != 1) || (choice > 4) || choice < 1)
        choice = -1;
    return choice;
}

int getSize(int *height, int* width) {
    if ((scanf("%d %d", height, width) != 2) || (*height <= 0) || (*width <= 0))
        return -1;
    return 0;
}

int input(int **matrix, int height, int width) {
    int is_error = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            if (scanf("%d", &(matrix[i][j])) != 1)
                is_error = 1;
        }
    char c = ' ';
    if ((scanf("%c", &c) != 0) && (c != '\n'))
        is_error = 1;
    return is_error;
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
       matr[i] = buf + i * m;
    }
}

void output(int **matrix, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d", matrix[i][j]);
            if (j != width -1)
                printf(" ");
        }
        if (i != height - 1)
            printf("\n");
    }
}

void staticAllocation(int ***matrix) {
    int arr[SMAX][SMAX];
    int* parr[SMAX];
    *matrix = parr;
    transform(arr, *matrix, SMAX, SMAX);
}


void dynamicAllocation1(int ***matrix, int height, int width) {
    *matrix = (int**)malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        (*matrix)[i] = (int*)malloc(sizeof(int) * width);
    }
}

void dynamicAllocation2(int ***matrix, int height, int width) {
    *matrix = (int**)malloc(sizeof(int*) * height);
    int* tmp = (int*)malloc(sizeof(int) * height * width);
    for (int i = 0; i < height; i++)
        (*matrix)[i] = tmp + width * i;
}

void dynamicAllocation3(int ***matrix, int height, int width) {
    *matrix = (int**)malloc(sizeof(int*) * height);
    (*matrix)[0] = (int*)malloc(sizeof(int) * height * width);
    for (int i = 0; i < height; i++)
        (*matrix)[i] = (*matrix)[0] + width * i;
}
