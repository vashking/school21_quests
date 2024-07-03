#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);

/* Find a max & min probabilties */
int main() {
    int x, y, z;
    if (scanf("%d %d %d", &x, &y, &z) != 3) {
        printf("n/a");
        return 1;
    }
    char c = ' ';
    if ((scanf("%c", &c) != 0) && (c != '\n')) {
        printf("n/a");
        return 1;
    }
    int max, min;

    maxmin(x, y, z, &max, &min);

    printf("%d %d", max, min);
    return 0;
}


/* This function should be kept !!! (Your AI) */
/* But errors & bugs should be fixed         */
void maxmin(int prob1, int prob2, int prob3, int *max, int *min) {
    *max = *min = prob1;
    if (prob2 > *max)
        *max = prob2;
    if (prob2 < *min)
        *min = prob2;
    if (prob3 > *max)
        *max = prob3;
    if (prob3 < *min)
        *min = prob3;
}

