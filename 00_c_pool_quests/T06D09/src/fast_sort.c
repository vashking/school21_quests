#include <stdio.h>
#define NMAX 30

int input(int *a, int* len);
void output(int *a, int len);
void quickSort(int* a, int left, int right);
void insertionSort(int *a, int len);

int main() {
    int is_error = 0;
    int array[NMAX], len;
    is_error = input(array, &len);
    if (is_error == 0) {
        int array2[NMAX];
        for (int i = 0; i < len; i++)
            array2[i] = array[i];
        quickSort(array, 0, len - 1);
        output(array, len);
        printf("\n");
        insertionSort(array2, len);
        output(array2, len);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *len) {
    int is_error = 0;
    if (scanf("%d", len) != 1 || *len <= 0)
        is_error = 1;
    if (is_error == 0) {
        for (int *p = a; p - a < *len; p++)
            if (scanf("%d", p) != 1) {
                is_error = 1;
                break;
            }
        char c = ' ';
        if ((scanf("%c", &c) != 0) && (c != '\n'))
            is_error = 1;
    }
    return is_error;
}

void output(int *a, int len) {
    for (int *p = a; p - a < len; p++) {
        printf("%d", *p);
     if (p - a != len -1)
         printf(" ");
    }
}

void quickSort(int *a, int left, int right) {
    if (right - left == 0)
        return;
    if (right - left == 1) {
        if (a[left] > a[right]) {
            int tmp = a[left];
            a[left] = a[right];
            a[right] = tmp;
        }
        return;
    }
    int l_hold = left, r_hold = right;
    int sr_ar = 0;
    for (int i = l_hold; i <= r_hold; i++)
        sr_ar += a[i];
    sr_ar /= (right - left + 1);
    while (left < right) {
        while ((a[right] > sr_ar) && (left < right))
            right--;
        while ((a[left] <= sr_ar) && (left < right))
            left++;
        if (left < right) {
            int tmp = a[left];
            a[left] = a[right];
            a[right] = tmp;
        }
    }
    if (l_hold < left)
        quickSort(a, l_hold, left);
    if (right < r_hold)
        quickSort(a, right + 1, r_hold);
}

void insertionSort(int *a, int len) {
    for (int i = 1; i < len; i++) {
        int j = i - 1;
        while ((j >= 0) && (a[j] > a[j + 1])) {
            int t = a[j];
            a[j] = a[j+1];
            a[j+1] = t;
            j--;
        }
    }
}
