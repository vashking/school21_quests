#include <stdio.h>

int main() {
double a, b;
if (scanf("%lf %lf", &a, &b) != 2) {
    printf("n/a");
    return 1;
}
char c = ' ';
if (((scanf("%c", &c)) != 0) && (c != '\n')) {
    printf("n/a");
    return 1; }
if (a*a+b*b < 25) printf("GOTCHA");
else
    printf("MISS");
return 0;
}
