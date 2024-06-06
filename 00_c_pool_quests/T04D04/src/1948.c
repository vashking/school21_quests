#include <math.h>
#include <stdio.h>

int isPrime(int res);
int division(int a, int *result);

int main() {
    int a = 0;

    if (scanf("%d", &a) != 1) return printf("n/a");

    if (a < 0) {
        a *= -1;
    }
    int result = 0;
    division(a, &result);
    printf("%d", result);

    return 0;
}

int isPrime(int res) {
    int count = 0;
    int b = 0;
    for (int i = 1; i <= res; i++) {
        b = res;
        while (b > 0) {
            b -= i;
        }
        if (b == 0) {
            count++;
        }
    }
    return count == 2 ? 1 : 0;
}

int division(int a, int *result) {
    int b = 0;

    for (int i = 2; i < a; i++) {
        b = a;
        while (b > 0) {
            b -= i;
        }
        if (b == 0) {
            *result = i;
        }
    }
    a = *result;
    if (isPrime(a)) {
        return 1;
    } else {
        division(a, result);
    }
    return 1;
}
