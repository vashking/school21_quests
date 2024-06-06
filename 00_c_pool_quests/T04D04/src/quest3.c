#include <stdio.h>

int fibonacci(int a);

int main() {
    int a;

    if ((scanf("%d", &a) != 1) || (a <= 0)) {
        printf("n/a");
        return 1;
    } else {
        printf("%d", fibonacci(a));
    }

    return 0;
}

int fibonacci(int a) {
    if (a == 0) return 0;

    if ((a == 1) || (a == 2)) return 1;

    return fibonacci(a - 1) + fibonacci(a - 2);
}
