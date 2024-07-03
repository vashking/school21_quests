#include <stdio.h>
#define size 10

int input(int *a);
void output(int *a);
void bubbleSort(int *a);

int main() {
    int is_error = 0;
    int array[10];
    is_error = input(array);
    if (is_error == 0) {
        bubbleSort(array);
        output(array);
    } else {
        printf("n/a");
    }
    return 0;
}

void bubbleSort(int *a) {
    for (int i = 0; i < size; i++)
        for (int *p = a; p - a < size - 1; p++) {
            if (*p > *(p + 1)) {
                int tmp = *p;
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
        }
}

int input(int *a) {
    int is_error = 0;
    for (int *p = a; p - a < size; p++) {
        if (scanf("%d", p) != 1) {
            is_error = 1;
            break;
        }
    }
    char c = ' ';
    if ((scanf("%c", &c) != 0) && (c != '\n'))
        is_error = 1;
    return is_error;
}

void output(int *a) {
    for (int *p = a; p - a < size; p++) {
        printf("%d", *p);
     if (p - a != size -1)
         printf(" ");
    }
}
