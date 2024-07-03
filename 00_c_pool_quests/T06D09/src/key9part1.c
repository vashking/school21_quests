#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void numbers_output(int sum, int *buffer, int length);
int sum_numbers(int *buffer, int length);
void find_numbers(int *buffer, int length, int number, int *numbers, int *length_num);

int main() {
    int is_error = 0;
    int array[NMAX], numbers[NMAX], n, length_num;
    is_error = input(array, &n);
    if (is_error == 0) {
        int sum = sum_numbers(array, n);
        find_numbers(array, n, sum, numbers, &length_num);
        numbers_output(sum, numbers, length_num);
    } else {
        printf("n/a");
    }
    return 0;
}


int input(int *buffer, int *length) {
    int is_error = 0;
    if (scanf("%d", length) != 1 || *length <= 0)
        is_error = 1;
    if (is_error == 0) {
        for (int *p = buffer; p - buffer < *length; p++)
            if (scanf("%d", p) != 1)
                is_error = 1;
        char c = ' ';
        if ((scanf("%c", &c) != 0) && (c != '\n'))
            is_error = 1;
    }
    return is_error;
}

void numbers_output(int sum, int *buffer, int length) {
    printf("%d\n", sum);
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d", *p);
        if (p - buffer != length - 1)
            printf(" ");
    }
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }
    return sum;
}

void find_numbers(int *buffer, int length, int number, int *numbers, int *length_num) {
    if (number == 0) {
        length_num = 0;
        return;
    }
    *length_num = 0;
    int *q = numbers;
    for (int *p = buffer; p - buffer < length; p++) {
        if (number % *p == 0) {
            *q = *p;
            q++;
            (*length_num)++;
        }
    }
}
