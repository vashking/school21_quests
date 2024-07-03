#include <stdio.h>
#define NMAX 30

int input(int *buffer, int *length, int *shift);
void output(int *buffer, int length);
void array_shift(int *buffer, int length, int shift);

int main() {
    int is_error = 0;
    int array[NMAX], length, shift;
    is_error = input(array, &length, &shift);
    if (is_error == 0) {
        array_shift(array, length, shift);
        output(array, length);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *buffer, int *length, int *shift) {
    int is_error = 0;
    if (scanf("%d", length) != 1 || *length <= 0)
        is_error = 1;
    if (is_error == 0) {
        for (int* p = buffer; p - buffer < *length; p++)
            if (scanf("%d", p) != 1) {
                is_error = 1;
                break;
            }
        if (scanf("%d", shift) != 1)
            is_error = 1;
        char c = ' ';
        if ((scanf("%c", &c) != 0) && (c != '\n'))
            is_error = 1;
    }
    return is_error;
}

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d", *p);
        if (p - buffer != length - 1)
            printf(" ");
    }
}

void array_shift(int *buffer, int length, int shift) {
    shift = shift % length;
    if (shift < 0)
        shift = length + shift;
    for (int i = 0; i < shift; i++) {
        int tmp = *buffer;
        for (int *p = buffer; p - buffer < length; p++) {
            if (p - buffer == length - 1)
                *p = tmp;
            else
                *p = *(p + 1);
        }
    }
}
