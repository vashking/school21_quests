#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n);
void output(int *a, int n);
void bubbleSort(int *a, int n);

int main() {
    int* array = NULL;
    int n;
    if (input(&array, &n)) {
        printf("n/a");
        return 1;
    }
    bubbleSort(array, n);
    output(array, n);
    free(array);
    return 0;
}

int input(int **a, int *n) {
    if ((scanf("%d", n) != 1) || (*n <= 0))
        return 1;
    *a = (int *)malloc(sizeof(int) * *n);
    for (int *p = *a; p - *a < *n; p++) {
        if (scanf("%d", p) != 1)
            return 1;
    }
    char c = ' ';
    if ((scanf("%c", &c) != 0) && (c != '\n'))
        return 1;
    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
     if (p - a != n -1)
         printf(" ");
    }
}

void bubbleSort(int *a, int n) {
    for (int i = 0; i < n; i++)
        for (int *p = a; p - a < n - 1; p++) {
            if (*p > *(p + 1)) {
                int tmp = *p;
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
        }
}

