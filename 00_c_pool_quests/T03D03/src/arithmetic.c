#include <stdio.h>

int sum(int a, int b);

int main() {
float a, b;
if (scanf("%f %f", &a, &b) != 2) {
    printf("n/a");
    return 1;
}
if (!(a == (int)a && b == (int)b)) {
    printf("n/a");
    return 1;
}
char c = ' ';
if ((scanf("%c", &c) != 0) && (c != '\n')) {
    printf("n/a");
    return 1;
}
sum((int)a, (int)b);
return 0;
}

int sum(int a, int b) {
int sum = a + b;
int diff = a - b;
int com = a * b;
printf("%d %d %d ", sum, diff, com);
if (b == 0) printf("n/a");
else
    printf("%d", a/b);
return 0;
}
