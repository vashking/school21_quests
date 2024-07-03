#include <stdio.h>

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
int x = (int)a;
int y = (int)b;
if (x > y)
    printf("%d", x);
else
    (printf("%d", y));
return 0;
}
