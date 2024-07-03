#include <stdio.h>
#include <stdlib.h>

int getSize(int *height, int* width);
int input(int **matrix, int height, int width);
void output(int **matrix, int height, int width);
void memAllocation(int ***matrix, int height, int width);
void bubbleSort(int *array, int length);
void sort_vertical(int **matrix, int height, int width, int **result);
void sort_horizontal(int **matrix, int height, int width, int **result);
void horizWrite(int *kj, int posi, int *posj, int* x_ph, int *array, int* id, int ***result, int width);
void vertWrite(int *ki, int *posi, int posj, int* y_ph, int *array, int* id, int ***result, int height);
void sort_spiral(int **matrix, int height, int width, int **result);


int main() {
    int is_error = 0;
    int **matrix, **result;
    int height, width;
    if (getSize(&height, &width) == -1)
        is_error = 1;
    if (is_error == 0) {
        memAllocation(&matrix, height, width);
        is_error = input(matrix, height, width);
    }
    if (is_error == 0) {
        memAllocation(&result, height, width);
        sort_vertical(matrix, height, width, result);
        output(result, height, width);
        printf("\n\n");
        sort_horizontal(matrix, height, width, result);
        output(result, height, width);
        printf("\n\n");
        sort_spiral(matrix, height, width, result);
        output(result, height, width);
    } else {
        printf("n/a");
    }
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

void memAllocation(int ***matrix, int height, int width) {
    *matrix = (int**)malloc(sizeof(int*) * height);
    int* tmp = (int*)malloc(sizeof(int) * height * width);
    for (int i = 0; i < height; i++)
        (*matrix)[i] = tmp + width * i;
}

void bubbleSort(int *array, int length) {
    for (int i = 0; i < length; i++)
        for (int j = 0; j < length - 1; j++)
            if (array[j] > array[j+1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
}

void sort_vertical(int **matrix, int height, int width, int **result) {
    int* array = (int*)malloc(sizeof(int) * height * width);
    int id = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            array[id] = matrix[i][j];
            id++;
        }
    bubbleSort(array, id);
    id = 0;
    for (int j = 0; j < width; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < height; i++) {
                result[i][j] = array[id];
                id++;
            }
        } else {
            for (int i = height - 1; i >= 0; i--) {
                result[i][j] = array[id];
                id++;
            }
        }
    }
    free(array);
}

void sort_horizontal(int **matrix, int height, int width, int **result) {
    int* array = (int*)malloc(sizeof(int) * height * width);
    int id = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            array[id] = matrix[i][j];
            id++;
        }
    bubbleSort(array, id);
    id = 0;
    for (int i = 0; i < height; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < width; j++) {
                result[i][j] = array[id];
                id++;
            }
        } else {
            for (int j = width - 1; j >= 0; j--) {
                result[i][j] = array[id];
                id++;
            }
        }
    }
    free(array);
}

void sort_spiral(int **matrix, int height, int width, int **result) {
    int* array = (int*)malloc(sizeof(int) * height * width);
    int id = 0;
    int stop = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            array[id++] = matrix[i][j];
    bubbleSort(array, id);
    id = 0;
    int posi = (height - 1) / 2;
    int posj = (width - 1) / 2;
    result[posi][posj] = array[id++];
    int x_ph = 1, y_ph = 1;
    int ki = 1, kj = 1;
    int size = height > width? height : width;
    for (int n = 0; n < size * 2 - 1; n++) {
        for (int j = 0; j < kj; j++) {
            posj += x_ph;
            if ((posi < height) && (posi >= 0) && (posj < width) && (posj >= 0))
                result[posi][posj] = array[id++];
        }
        x_ph *= -1;
        kj++;
        for (int i = 0; i < ki; i++) {
            posi += y_ph;
            if ((posi < height) && (posi >= 0) && (posj < width) && (posj >= 0))
                result[posi][posj] = array[id++];
        }
        y_ph *= -1;
        ki++;
    }
    free(array);
}
