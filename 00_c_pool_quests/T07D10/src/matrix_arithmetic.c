#include <stdio.h>
#include <stdlib.h>

int getChoice();
int menu(int ***res, int *hr, int *wr);
int initMatrix(int ***matrix, int *height, int *width);
int getSize(int* height, int* width);
int input(int **matrix, int height, int width);
void output(int **matrix, int height, int width);
void dynamicAllocation(int ***matrix, int height, int width);
int sum(int **m1, int h1, int w1, int **m2, int h2, int w2, int ***res, int *hr, int *wr);
void transpose(int **matrix, int height, int width, int ***res, int *hr, int *wr);
int mul(int **m1, int h1, int w1, int **m2, int h2, int w2, int ***res, int *hr, int *wr);

int main() {
    int is_error = 0;
    int **res;
    int hr, wr;
    is_error = menu(&res, &hr, &wr);
    if (is_error == 0)
        output(res, hr, wr);
    else
        printf("n/a");
    return is_error;
}

int getChoice() {
    int choice;
    if ((scanf("%d", &choice) != 1) || (choice > 3) || choice < 1)
        choice = -1;
    return choice;
}

int menu(int ***res, int *hr, int *wr) {
    int is_error = 0;
    int choice = getChoice();
    if (choice == -1)
        is_error = 1;
    if (choice == 1) {
        int **m1, **m2;
        int h1, w1, h2, w2;
        if (is_error == 0)
            is_error = initMatrix(&m1, &h1, &w1);
        if (is_error == 0)
            is_error = initMatrix(&m2, &h2, &w2);
        if (is_error == 0)
            is_error = sum(m1, h1, w1, m2, h2, w2, res, hr, wr);
    }
    if (choice == 2) {
        int **m1, **m2;
        int h1, w1, h2, w2;
        if (is_error == 0)
            is_error = initMatrix(&m1, &h1, &w1);
        if (is_error == 0)
            is_error =  initMatrix(&m2, &h2, &w2);
        if (is_error == 0)
            is_error = mul(m1, h1, w1, m2, h2, w2, res, hr, wr);
    }
    if (choice == 3) {
        int **m1;
        int h1, w1;
        if (is_error == 0)
            is_error = initMatrix(&m1, &h1, &w1);
        if (is_error == 0)
            transpose(m1, h1, w1, res, hr, wr);
    }
    return is_error;
}

int initMatrix(int ***matrix, int *height, int *width) {
    int is_error = 0;
    if (getSize(height, width) == -1)
        is_error = 1;
    if (is_error == 0)
        dynamicAllocation(matrix, *height, *width);
    if (is_error == 0)
        is_error = input(*matrix, *height, *width);
    return is_error;
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

void dynamicAllocation(int ***matrix, int height, int width) {
    *matrix = (int**)malloc(sizeof(int*) * height);
    int* tmp = (int*)malloc(sizeof(int) * height * width);
    for (int i = 0; i < height; i++)
        (*matrix)[i] = tmp + width * i;
}

int sum(int **m1, int h1, int w1, int **m2, int h2, int w2, int ***res, int *hr, int *wr) {
    int is_error = 0;
    if ((h1 != h2) || (w1 != w2)) {
        is_error = 1;
    } else {
        *hr = h1;
        *wr = w1;
        dynamicAllocation(res, *hr, *wr);
        for (int i = 0; i < *hr; i++)
            for (int j = 0; j < *wr; j++)
                (*res)[i][j] = m1[i][j] + m2[i][j];
    }
    return is_error;
}

int mul(int **m1, int h1, int w1, int **m2, int h2, int w2, int ***res, int *hr, int *wr) {
    int is_error = 0;
    if (w1 != h2) {
        is_error = 1;
    } else {
        *wr = w2;
        *hr = h1;
        dynamicAllocation(res, *hr, *wr);
        for (int i = 0; i < *hr; i++)
            for (int j = 0; j < *wr; j++)
                for (int k = 0; k < w1; k++) {
                    (*res)[i][j] += m1[i][k] * m2[k][j];
                }
    }
    return is_error;
}


void transpose(int **matrix, int height, int width, int ***res, int *hr, int *wr) {
    *hr = width;
    *wr = height;
    dynamicAllocation(res, *hr, *wr);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            (*res)[j][i] = matrix[i][j];
}

