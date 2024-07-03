#include <stdio.h>
#include <stdlib.h>

int getSize(int *height, int* width);
int input(double **matrix, int height, int width);
void output(double det);
void memAllocation(double ***matrix, int height, int width);
void getMatrix(double** matrix, double** sub, int i, int j, int size);
double det(double **matrix, int size);

int main() {
    int is_error = 0;
    double **matrix;
    int height, width;
    if (getSize(&height, &width) == -1)
        is_error = 1;
    if (is_error == 0) {
        memAllocation(&matrix, height, width);
        is_error = input(matrix, height, width);
    }
    if (is_error == 0) {
        double determ = det(matrix, height);
        output(determ);
    } else {
        printf("n/a");
    }
    return 0;
}

int getSize(int *height, int* width) {
    if ((scanf("%d %d", height, width) != 2) || (*height <= 0) || (*width <= 0) || (*height != *width))
        return -1;
    return 0;
}

int input(double **matrix, int height, int width) {
    int is_error = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            if (scanf("%lf", &(matrix[i][j])) != 1)
                is_error = 1;
        }
    char c = ' ';
    if ((scanf("%c", &c) != 0) && (c != '\n'))
        is_error = 1;
    return is_error;
}

void output(double det) {
    printf("%.6lf", det);
}

void memAllocation(double ***matrix, int height, int width) {
    *matrix = (double**)malloc(sizeof(double*) * height);
    double* tmp = (double*)malloc(sizeof(double) * height * width);
    for (int i = 0; i < height; i++)
        (*matrix)[i] = tmp + width * i;
}

double det(double **matrix, int size) {
    double determ = 0.0;
    if (size == 1) {
        determ = matrix[0][0];
    } else if (size == 2) {
        determ = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        int k = 1;
        double **sub = (double**)malloc(sizeof(double*) * (size -1));
        for (int i = 0; i < size - 1; i++)
            sub[i] = (double*)malloc(sizeof(double) * (size - 1));
        for (int i = 0; i < size; i++) {
            getMatrix(matrix, sub, i, 0, size);
            determ += k * matrix[i][0] * det(sub, size - 1);
            k *= -1;
        }
        for (int i = 0; i < size - 1; i++)
            free(sub[i]);
        free(sub);
    }
    return determ;
}

void getMatrix(double** matrix, double** sub, int i, int j, int size) {
    int di = 0, dj = 0;;
    for (int n = 0; n < size - 1; n++) {
        if (n == i)
            di = 1;
        dj = 0;
        for (int m = 0; m < size - 1; m++) {
            if (m == j)
                dj = 1;
            sub[n][m] = matrix[n+di][m+dj];
        }
    }
}
