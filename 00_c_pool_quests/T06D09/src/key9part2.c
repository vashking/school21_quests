#include <stdio.h>
#define LEN 100

int input(int *buffer, int *length);
void output(int *buffer, int length);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int* len_result);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int* len_result);
int is_less(int *buff1, int len1, int *buff2, int len2);

int main() {
    int is_error = 0;
    int buff1[LEN], buff2[LEN], len1 = 0, len2 = 0, result[101], len_result;
    if (input(buff1, &len1) || input(buff2, &len2))
        is_error = 1;
    if ((is_less(buff1, len1, buff2, len2)) == 0)
        is_error = 1;
    if (is_error == 0) {
        sum(buff1, len1, buff2, len2, result, &len_result);
        output(result, len_result);
        printf("\n");
        sub(buff1, len1, buff2, len2, result, &len_result);
        output(result, len_result);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *buffer, int *length) {
    int is_error = 0;
    int *p = buffer;
    char str[220];
    char c = ' ';
    int size = 0;
    while (c != '\n') {
        scanf("%c", &c);
        str[size] = c;
        size++;
    }
    str[--size] = '\0';
    for (int i = 0; i < size; i++) {
        if (((str[i]) > '9' || (str[i] < '0')) && (str[i] != ' ')) {
            is_error = 1;
            break;
        }
        if (((str[i] != ' ') && (str[i+1] != ' ')) && (i != size - 1)) {
            is_error = 1;
            break;
        }
        if (str[i] == ' ')
            continue;
        (*length)++;
        if (*length > LEN) {
            is_error = 1;
            break;
        }
        *p = (int)(str[i] - '0');
        p++;
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

int is_less(int *buff1, int len1, int *buff2, int len2) {
    int is_less = 1;
    if (len2 > len1)
        is_less = 0;
    if (len2 == len1) {
        int *p1 = buff1;
        int *p2 = buff2;
        while (p1 < buff1 + len1) {
            if (*p2 > *p1) {
                is_less = 0;
                break;
            }
            if (*p2 < *p1)
                break;
            p1++;
            p2++;
        }
    }
    return is_less;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int* len_result) {
    len1 > len2 ? (*len_result = len1 + 1) : (*len_result = len2 + 1);
    int *p1 = buff1 + len1 - 1;
    int *p2 = buff2 + len2 - 1;
    for (int *q = result + *len_result - 1; q > result; q--)
        *q = 0;
    for (int *q = result + *len_result - 1; q > result; q--) {
        if (p1 >= buff1) {
            *q += *p1;
            p1--;
        }
        if (p2 >= buff2) {
            *q += *p2;
            p2--;
        }
        if (*q > 9) {
            *(q - 1) = *q / 10;
            *q = *q % 10;
        }
    }
    while (*result == 0) {
        for (int* q = result; q - result < *len_result; q++)
            *q = *(q + 1);
        (*len_result)--;
    }
}


void sub(int *buff1, int len1, int *buff2, int len2, int *result, int* len_result) {
    *len_result = len1;
    int* q = result;
    for (int* p1 = buff1; p1 - buff1 < len1; p1++, q++)
        *q = *p1;
    int *p2 = buff2 + len2 - 1;
    for (q = result + *len_result - 1; q >= result; q--) {
        if (*q < 0) {
            *q = 9;
            (*(q - 1))--;
        }
        if (p2 >= buff2) {
            if (*q < *p2) {
                *q = (*q + 10 - *p2);
                (*(q - 1))--;
            } else {
                *q -= *p2;
            }
            p2--;
        }
    }
    while (*result == 0) {
        for (int* q = result; q - result < *len_result; q++)
            *q = *(q + 1);
        (*len_result)--;
    }
}
